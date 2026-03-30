#include "mylist.h"

// 构造函数
MyList::MyList() {
    head = nullptr;
    len = 0;
}

// 析构函数
MyList::~MyList() {
    clear();
}

// 在指定位置插入
void MyList::insert(int index, int value) {
    if (index < 0 || index > len) {
        cout << -1 << endl;
        return;
    }

    Node* newNode = new Node(value);

    // 插到头部
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        len++;
        return;
    }

    // 找到 index-1 位置
    Node* prev = head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;
    len++;
}

// 删除指定位置元素
void MyList::remove(int index) {
    if (index < 0 || index >= len) {
        cout << -1 << endl;
        return;
    }

    Node* toDelete;

    // 删除头结点
    if (index == 0) {
        toDelete = head;
        head = head->next;
        delete toDelete;
        len--;
        return;
    }

    // 找到 index-1
    Node* prev = head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;
    len--;
}

// 获取指定位置元素
int MyList::get(int index) const {
    if (index < 0 || index >= len) {
        return -1;
    }

    Node* cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }

    return cur->data;
}

// 设置指定位置元素
void MyList::set(int index, int value) {
    if (index < 0 || index >= len) {
        cout << -1 << endl;
        return;
    }

    Node* cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }

    cur->data = value;
}

// 返回大小
int MyList::size() const {
    return len;
}

// 清空链表
void MyList::clear() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    head = nullptr;
    len = 0;
}

// 从 index 开始前 k 个元素求和
int MyList::sum_from(int index, int k) const {
    if (index < 0 || index >= len || k <= 0 || index + k > len) {
        return -1;
    }

    Node* cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += cur->data;
        cur = cur->next;
    }

    return sum;
}

// 反转链表
void MyList::reverse() {
    Node* prev = nullptr;
    Node* cur = head;

    while (cur != nullptr) {
        Node* nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }

    head = prev;
}

// 合并 other 到当前链表尾部
void MyList::merge(MyList& other) {
    // other 空，直接返回
    if (other.head == nullptr) {
        return;
    }

    // 当前链表空
    if (head == nullptr) {
        head = other.head;
        len = other.len;
    } else {
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = other.head;
        len += other.len;
    }

    // 转移所有权后清空 other
    other.head = nullptr;
    other.len = 0;
}