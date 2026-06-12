#include <iostream>

// 窗口基类
class Window {
protected:
    int _x, _y, _w, _h;
};

// 派生类，用链表的形式将窗口组织起来
class WindowInScreen: public Window {
    int id;
    WindowInScreen *next;

public:
    WindowInScreen(): next(nullptr) {}

    void display() {
        // TODO
    }
};

// 屏幕类
class Screen {
    int _w, _h;
    int count;
    WindowInScreen *root;

public:
    Screen(int w = 1920, int h = 1080): _w(w), _h(h), count(0), root(nullptr) {}
    ~Screen() {
        // TODO
    }

    void addWindow(int id) {
        // TODO
    }

    void delWindow(int id) {
        // TODO
    }

    void display() {
        // TODO
    }
};
