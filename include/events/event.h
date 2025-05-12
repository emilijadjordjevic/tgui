#ifndef EVENT_H
#define EVENT_H
#include <functional>
#include <iostream>
using namespace std;

class Event {
public:
    enum Type { KeyPress, Resize } type;
    function<void()> handler;
    bool async = false;
};

#endif