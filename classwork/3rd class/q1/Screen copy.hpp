#include <iostream>
 using namespace std;

// 窗口基类
class Window {
protected:
    int _x, _y, _w, _h;
};

// 派生类，用链表的形式将窗口组织起来
class WindowInScreen: public Window {
    friend class Screen;
    

    int _id;
    WindowInScreen *next;





public:
    WindowInScreen(): next(nullptr) {};

    WindowInScreen(int id, int x, int y, int w, int h)
        : _id(id), next(nullptr) {
        _x = x;
        _y = y;
        _w = w;
        _h = h;
    }

    void display() {
        // TODO
        cout << "(id: " << _id
        << ", x: " << _x
        << ", y: " << _y
        << ", w: " << _w
        << ", h: " << _h
        << ")" << endl;
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
        while (root != nullptr) {
            WindowInScreen* temp = root;
            root = root->next;
            delete temp;
        }
    }

    void addWindow(int id) {
    // 情况1：屏幕为空，第一个窗口占满屏幕
    if (count == 0) {
        root = new WindowInScreen(id, 0, 0, _w, _h);
        count++;
        return;
    }

    // 情况2：屏幕已有窗口，先找到最后一个窗口
    WindowInScreen* last = root;
    while (last->next != nullptr) {
        last = last->next;
    }

    // 记录旧尾窗口原来的位置和大小
    int oldX = last->_x;
    int oldY = last->_y;
    int oldW = last->_w;
    int oldH = last->_h;

    // 如果宽更大：左右切
    if (oldW >= oldH) {
        last->_w = oldW / 2;

        WindowInScreen* node = new WindowInScreen(
            id,
            oldX + oldW / 2,
            oldY,
            oldW / 2,
            oldH
        );

        last->next = node;
    }
    // 如果高更大：上下切
    else {
        last->_h = oldH / 2;

        WindowInScreen* node = new WindowInScreen(
            id,
            oldX,
            oldY + oldH / 2,
            oldW,
            oldH / 2
        );

        last->next = node;
    }

    count++;
}




void delWindow(int id) {
    if (root == nullptr) return;

    WindowInScreen* prev = nullptr;
    WindowInScreen* cur = root;

    while (cur != nullptr && cur->_id != id) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == nullptr) return;

    // 只有一个窗口
    if (count == 1) {
        delete root;
        root = nullptr;
        count = 0;
        return;
    }

    // 删除最后一个窗口
    if (cur->next == nullptr) {
        if (prev->_y == cur->_y)
            prev->_w += cur->_w;
        else
            prev->_h += cur->_h;

        prev->next = nullptr;
        delete cur;
        count--;
        return;
    }

    // 删除中间窗口
    WindowInScreen* p = cur;

    while (p->next->next != nullptr) {
        p->_id = p->next->_id;
        p = p->next;
    }

    WindowInScreen* last = p->next;

    p->_id = last->_id;

    if (p->_y == last->_y)
        p->_w += last->_w;
    else
        p->_h += last->_h;

    p->next = nullptr;
    delete last;
    count--;
}
void display() {
        WindowInScreen* cur = root;

        while (cur != nullptr) {
            cur->display();
            cur = cur->next;
        }
    }
};
