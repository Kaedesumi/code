#include "mylist.h"
#include <iostream>
using namespace std;

/* =========================
   构造函数
   初始化空链表
   ========================= */
MyList::MyList() {
    head = nullptr; // 头指针为空
    len = 0;        // 长度为0
}

/* =========================
   析构函数
   释放所有节点，防止内存泄漏
   ========================= */
MyList::~MyList() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* temp = cur;     // 保存当前节点
        cur = cur->next;      // 移动到下一个节点
        delete temp;          // 删除当前节点
    }
    head = nullptr;
    len = 0;
}

/* =========================
   插入元素
   index: 插入位置
   value: 插入值
   ========================= */
void MyList::insert(int index, int value) {
    // 非法下标
    if (index < 0 || index > len) {
        cout << -1 << endl;
        return;
    }

    // 创建新节点
    Node* newNode = new Node(value);

    // 插入头部
    if (index == 0) {
        newNode->next = head; // 新节点指向原头
        head = newNode;       // 更新头指针
        len++;
        return;
    }

    // 找到 index-1 位置的节点
    Node* prev = head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    // 插入节点
    newNode->next = prev->next; // 新节点指向后继
    prev->next = newNode;       // 前驱指向新节点

    len++;
}

/* =========================
   删除元素
   ========================= */
void MyList::remove(int index) {
    // 非法下标
    if (index < 0 || index >= len) {
        cout << -1 << endl;
        return;
    }

    Node* toDelete;

    // 删除头节点
    if (index == 0) {
        toDelete = head;
        head = head->next; // 头指针后移
        delete toDelete;
        len--;
        return;
    }

    // 找到 index-1
    Node* prev = head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    // 删除节点
    toDelete = prev->next;
    prev->next = toDelete->next; // 跳过该节点
    delete toDelete;

    len--;
}

/* =========================
   获取元素
   ========================= */
int MyList::get(int index) const {
    if (index < 0 || index >= len) {
        return -1;
    }

    Node* cur = head;

    // 移动到 index
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }

    return cur->data;
}

/* =========================
   修改元素
   ========================= */
void MyList::set(int index, int value) {
    if (index < 0 || index >= len) {
        cout << -1 << endl;
        return;
    }

    Node* cur = head;

    // 找到位置
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }

    cur->data = value;
}

/* =========================
   返回长度
   ========================= */
int MyList::size() const {
    return len;
}

/* =========================
   清空链表
   ========================= */
void MyList::clear() {
    // 空链表，无意义
    if (head == nullptr) {
        cout << -1 << endl;
        return;
    }

    Node* cur = head;

    // 逐个删除节点
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    head = nullptr;
    len = 0;
}

/* =========================
   求区间和
   从 index 开始取 k 个
   ========================= */
int MyList::sum_from(int index, int k) const {
    // 非法情况
    if (index < 0 || index >= len || k <= 0 || index + k > len) {
        return -1;
    }

    Node* cur = head;

    // 移动到起点
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }

    int sum = 0;

    // 累加 k 个节点
    for (int i = 0; i < k; i++) {
        sum += cur->data;
        cur = cur->next;
    }

    return sum;
}

/* =========================
   反转链表（核心：三指针）
   ========================= */
void MyList::reverse() {
    Node* prev = nullptr; // 前一个节点
    Node* cur = head;     // 当前节点

    while (cur != nullptr) {
        Node* nextNode = cur->next; // 保存下一个节点

        cur->next = prev; // 反转指向

        prev = cur;       // 前移
        cur = nextNode;   // 前移
    }

    head = prev; // 新头
}

/* =========================
   合并链表（重点）
   不复制节点，直接接尾
   ========================= */
void MyList::merge(MyList& other) {
    // 自己合并自己 or other为空 → 无意义
    if (this == &other || other.head == nullptr) {
        cout << -1 << endl;
        return;
    }

    // 当前链表为空
    if (head == nullptr) {
        head = other.head;
    } 
    else {
        // 找到尾节点
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        // 接上 other
        tail->next = other.head;
    }

    // 更新长度
    len += other.len;

    // 清空 other（转移所有权）
    other.head = nullptr;
    other.len = 0;
}