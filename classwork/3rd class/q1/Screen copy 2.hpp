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
    WindowInScreen(): next(nullptr) {}

    WindowInScreen(int id, int x, int y, int w, int h) : _id(id), next(nullptr){
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
        << ")" <<endl;
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
        while (root != nullptr){
            WindowInScreen *temp = root;
            root = root->next;
            delete temp;
        }
    }

    void addWindow(int id) {
        // TODO
        //如果是空的
        if (count == 0)
        {
            count++;
            root = new WindowInScreen(id, 0, 0, _w, _h);
            return;
        }
        //找最后一个窗口
        WindowInScreen *cur = root;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }//现在cur就是最后一个了
        if (cur->_w >= cur->_h)
        {
            WindowInScreen *newNode = new WindowInScreen(id, (_w + cur->_x)/2, cur->_y, cur->_w / 2, cur->_h);
            cur->_w /= 2;
            cur->next = newNode;
        }else{
            WindowInScreen *newNode = new WindowInScreen(id, cur->_x, (_h + cur->_y)/2, cur->_w, cur->_h / 2);
            cur->_h /= 2;
            cur->next = newNode;
        }
        count++;
        return;
    }

    void delWindow(int id) {
        // TODO
        //如果只有一个
        if (root == nullptr) return;

        if (count == 1)
        {
            if (root->_id == id)
            {
                delete root;
                root = nullptr;
                count = 0;
            }
            return;
        }
        if (root->_id == id)
        {
            root->_id = root->next->_id;
            id = root->next->_id;
        }

        //判断删除的节点是在中间还是末
        WindowInScreen *cur = root;
        while(cur->next != nullptr && cur->next->_id != id){
            cur = cur->next;
        }
        if (cur->next == nullptr)
        {
            return;
        }
        //此时cur是要删除的节点的前一个节点
        //==========如果是最后一个===========
        if (cur->next->next == nullptr)
        {
            delete cur->next;
            count--;
            //判断长宽来fangda
            if (cur->_w > cur->_h)
            {
                cur->_h *= 2;
            }else{
                cur->_w *= 2;
            }
            cur->next = nullptr;
            //把这个删掉，前一个的长款要变
        }else{//===============如果不是最后一个，我要把id依次往前移动一个，再把最后一个节点删了
            while (cur->next->next != nullptr)
            {
                cur->next->_id = cur->next->next->_id;
                cur = cur->next;
            }//现在的cur是倒数第二个节点
            //删除最后一个节点
            delete cur->next;
            count--;
            //判断长宽来fangda
            if (cur->_w > cur->_h)
            {
                cur->_h *= 2;
            }else{
                cur->_w *= 2;
            }
            cur->next = nullptr;
        }
    }

    void display() {
        // TODO
        WindowInScreen *cur = root;
        while (cur != nullptr)
        {
            cur->display();
            cur = cur->next;
        }
        return;
    }
};
