#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
using namespace std;

// 题目一般会给这个结点结构
struct Node {
    int data;
    Node* next;

    Node(int v) : data(v), next(nullptr) {}
};

class MyList {
private:
    Node* head;
    int len;

public:
    // 构造函数
    MyList();

    // 析构函数
    ~MyList();

    // 基本操作
    void insert(int index, int value);
    void remove(int index);
    int get(int index) const;
    void set(int index, int value);
    int size() const;
    void clear();

    // 进阶操作
    int sum_from(int index, int k) const;
    void reverse();
    void merge(MyList& other);
};

#endif