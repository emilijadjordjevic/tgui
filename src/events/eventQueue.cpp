#include "events/eventQueue.h"

void EventQueue::push(const Event& e) {
    unique_lock<mutex> lock(mtx);
    eventQueue.push(e);
    cv.notify_one();
}

Event EventQueue::pop() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&] { return !eventQueue.empty(); });
    Event e = eventQueue.front();
    eventQueue.pop();
    return e;
}

bool EventQueue::empty() {
    unique_lock<mutex> lock(mtx);
    return eventQueue.empty();
}