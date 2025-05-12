#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <vector>
#include <atomic>
using namespace std;

class ThreadPool {
private:
    vector<thread> threads;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    atomic<bool> running = true;

    void loop();
public:
    ThreadPool();
    ~ThreadPool();

    void submit(function<void()>);
};

#endif