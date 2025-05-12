#include "events/threadPool.h"

ThreadPool::ThreadPool() {
    size_t count = std::max(1u, std::thread::hardware_concurrency() - 1);

    for (int i = 0; i < count; i++) {
        threads.emplace_back(&ThreadPool::loop, this);
    }
}

ThreadPool::~ThreadPool() {
    running = false;
    cv.notify_all();
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }
}

void ThreadPool::submit(function<void()> func) {
    {
        unique_lock<mutex> lock(mtx);
        tasks.push(func);
    }
    cv.notify_one();
}

void ThreadPool::loop() {
    while (running) {
        function<void()> task;
        {
            unique_lock lock(mtx);
            cv.wait(lock, [&] { return !tasks.empty() || !running; });
            if (!running && tasks.empty()) return;
            task = tasks.front();
            tasks.pop();
        }

        task();
    }
}
