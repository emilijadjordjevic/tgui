#ifndef APPLICATION_H
#define APPLICATION_H
#include <functional>
#include <unistd.h>
#include <sys/select.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include "screen.h"
#include "events/eventQueue.h"
#include "events/threadPool.h"

// extern int pipeFd[2];

class Application {
private:
    Screen& screen;
    EventQueue queue;
    atomic<bool> running;
    void setup();
    static void sigwinchHandler(int);
    void waitForEvents();
    void handleKeyPress();
    void handleResize();
public:
    Application(Screen&);
    void run();
    void inputLoop();
};

#endif