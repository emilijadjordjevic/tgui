#include "screen/application.h"
#include <poll.h>

int pipeFd[2];

Application::Application(Screen& screen) : queue(), screen(screen) {
    running = true;
    setup();
}

void Application::setup() {
    screen.init();
    pipe(pipeFd);

    fcntl(pipeFd[0], F_SETFL, O_NONBLOCK);
    fcntl(pipeFd[1], F_SETFL, O_NONBLOCK);
    setvbuf(stdout, nullptr, _IONBF, 0);

    signal(SIGWINCH, sigwinchHandler);
}

void Application::sigwinchHandler(int) {
    char writeEnd = 'r';
    write(pipeFd[1], &writeEnd, 1);
}

void Application::run() {
    thread inputThread([&]{ inputLoop(); });
    screen.render();
    screen.print();
    while (running) {
        Event e = queue.pop();
        if (e.async) {
            //stavi je na thread pool da se izvrsi
        } else {
            e.handler();
        }
    }

    if (inputThread.joinable()) 
        inputThread.join();
}

void Application::inputLoop() {
    while (running) {
        waitForEvents();
    }
}

void Application::waitForEvents() {

    pollfd fds[] = {
        { .fd = STDIN_FILENO, .events = POLLIN, .revents = 0 },
        { .fd = pipeFd[0], .events = POLLIN, .revents = 0 }
    };

    int result = poll(fds, 2, -1);
    if (result == -1) 
        cout << "POLL NOT WORKING" << endl;
    
        if (fds[0].revents & POLLIN) {
            handleKeyPress();
        }

        if (fds[1].revents & POLLIN) {
            handleResize();
        }
}

void Application::handleKeyPress() {
    char c;
    read(STDIN_FILENO, &c, 1);

    Event e;
    e.type = Event::KeyPress;
    switch (c) {
        case 'q':
            e.handler = []() {
                std::cout << "Exit friend..." << std::endl;
            };
            running = false;
            break;
    
        case '\r': // Enter key in raw mode
            e.handler = []() {
                std::cout << "clicked" << std::flush;
            };
            break;
    
        default:
            e.handler = [c]() {
                std::cout << c << std::flush;
            };
            break;
    }
    queue.push(e);
}

void Application::handleResize() {
    char b;
    read(pipeFd[0], &b, 1);

    Event e;
    e.type = Event::Resize;
    e.handler = [this]() {
        // cout << "sarting execturion" << endl;
        screen.resize(); 
        screen.render();
        screen.print();
    };
    queue.push(e);
}