#pragma once
#include<iostream>
using namespace std;

template<typename T1, typename T2>
class MyPair {
public:
    //add member here
    T1 first;
    T2 second;

    MyPair();
    MyPair(const T1& a, const T2& b);

    bool operator==(const MyPair<T1, T2>& other) const;

};

template<typename T>
class MyVector {
private:
    T* data;
    int sz;
    int capacity;

    void resize(int new_capacity); // 动态扩容

public:
    MyVector();
    ~MyVector();

    int size() const;
    bool empty() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    void push_back(const T& value);
    void pop_back();
    void clear();
};









// MyMap 类模板（函数待实现）
template<typename K, typename V>
class MyMap {
private:
    MyVector<MyPair<K, V>> data;

public:
    MyMap();

    void insert(const K& key, const V& value);
    int size() const;
    bool contains(const K& key) const;

    V& operator[](const K& key);
    void erase(const K& key);
    void clear();

    MyPair<K, V> get(int index) const;
};