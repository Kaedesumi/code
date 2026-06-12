#pragma once
#include <iostream>
using namespace std;



//=================first====================
template<typename T1, typename T2>
class MyPair {
public:
    T1 first;
    T2 second;

    MyPair();
    MyPair(const T1& a, const T2& b);

    bool operator==(const MyPair<T1, T2>& other) const;
};

template<typename T1, typename T2>
MyPair<T1, T2>::MyPair()
{
    first = T1();
    second = T2();
}

template<typename T1, typename T2>
MyPair<T1, T2>::MyPair(const T1& a, const T2& b)
{
    first = a;
    second = b;
}

template<typename T1, typename T2>
bool MyPair<T1, T2>::operator==(const MyPair<T1, T2>& other) const
{
    return first == other.first && second == other.second;
}


//===============second============
template<typename T>
class MyVector {
private:
    T* data;
    int sz;
    int capacity;

    void resize(int new_capacity);

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

template<typename T>
MyVector<T>::MyVector()
{
    sz = 0;
    capacity = 1;
    data = new T[capacity];
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete[] data;
}

template<typename T>
void MyVector<T>::resize(int new_capacity)
{
    T* new_data = new T[new_capacity];

    for (int i = 0; i < sz; i++)
    {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template<typename T>
int MyVector<T>::size() const
{
    return sz;
}

template<typename T>
bool MyVector<T>::empty() const
{
    return sz == 0;
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
    return data[index];
}

template<typename T>
const T& MyVector<T>::operator[](int index) const
{
    return data[index];
}

template<typename T>
void MyVector<T>::push_back(const T& value)
{
    if (sz == capacity)
    {
        resize(capacity * 2);
    }

    data[sz] = value;
    sz++;
}

template<typename T>
void MyVector<T>::pop_back()
{
    if (sz > 0)
    {
        sz--;
    }
}

template<typename T>
void MyVector<T>::clear()
{
    sz = 0;
}















//================third============================

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

template<typename K, typename V>
MyMap<K, V>::MyMap()
{
}

template<typename K, typename V>
void MyMap<K, V>::insert(const K& key, const V& value)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].first == key)
        {
            data[i].second = value;
            return;
        }
    }

    data.push_back(MyPair<K, V>(key, value));
}

template<typename K, typename V>
int MyMap<K, V>::size() const
{
    return data.size();
}

template<typename K, typename V>
bool MyMap<K, V>::contains(const K& key) const
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].first == key)
        {
            return true;
        }
    }

    return false;
}

template<typename K, typename V>
V& MyMap<K, V>::operator[](const K& key)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].first == key)
        {
            return data[i].second;
        }
    }

    data.push_back(MyPair<K, V>(key, V()));
    return data[data.size() - 1].second;
}

template<typename K, typename V>
void MyMap<K, V>::erase(const K& key)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].first == key)
        {
            for (int j = i; j < data.size() - 1; j++)
            {
                data[j] = data[j + 1];
            }

            data.pop_back();
            return;
        }
    }
}

template<typename K, typename V>
void MyMap<K, V>::clear()
{
    data.clear();
}

template<typename K, typename V>
MyPair<K, V> MyMap<K, V>::get(int index) const
{
    return data[index];
}