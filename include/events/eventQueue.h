#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H
#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <queue>
#include "event.h"
using namespace std;


class EventQueue {
private:
    queue<Event> eventQueue;
    mutex mtx;
    condition_variable cv;
public:
    void push(const Event&);
    Event pop();
    bool empty();
};

#endif