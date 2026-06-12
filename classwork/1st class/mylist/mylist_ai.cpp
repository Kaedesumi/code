#include "mylist.h"
#include <iostream>
using namespace std;

MyList::MyList()
{
    head = nullptr;
    list_size = 0;
}

MyList::~MyList()
{
    clear();
}

MyList::Node* MyList::getNodeAt(int index) const
{
    if (index < 0 || index >= list_size)
    {
        return nullptr;
    }

    Node* cur = head;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }

    return cur;
}

void MyList::insert(int index, int value)
{
    if (index < 0 || index > list_size)
    {
        cout << -1 << endl;
        return;
    }

    Node* newNode = new Node(value);

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* pre = getNodeAt(index - 1);
        newNode->next = pre->next;
        pre->next = newNode;
    }

    list_size++;
}

void MyList::remove(int index)
{
    if (index < 0 || index >= list_size)
    {
        cout << -1 << endl;
        return;
    }

    Node* del;

    if (index == 0)
    {
        del = head;
        head = head->next;
    }
    else
    {
        Node* pre = getNodeAt(index - 1);
        del = pre->next;
        pre->next = del->next;
    }

    delete del;
    list_size--;
}

int MyList::get(int index) const
{
    Node* node = getNodeAt(index);

    if (node == nullptr)
    {
        return -1;
    }

    return node->value;
}

void MyList::set(int index, int value)
{
    Node* node = getNodeAt(index);

    if (node == nullptr)
    {
        cout << -1 << endl;
        return;
    }

    node->value = value;
}

int MyList::size() const
{
    return list_size;
}

void MyList::clear()
{
    Node* cur = head;

    while (cur != nullptr)
    {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }

    head = nullptr;
    list_size = 0;
}

int MyList::sum_from(int index, int k) const
{
    if (index < 0 || k < 0 || index + k > list_size)
    {
        return -1;
    }

    int sum = 0;
    Node* cur = getNodeAt(index);

    for (int i = 0; i < k; i++)
    {
        sum += cur->value;
        cur = cur->next;
    }

    return sum;
}

void MyList::reverse()
{
    Node* prev = nullptr;
    Node* cur = head;

    while (cur != nullptr)
    {
        Node* nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }

    head = prev;
}

void MyList::merge(MyList& other)
{
    if (other.head == nullptr)
    {
        return;
    }

    if (head == nullptr)
    {
        head = other.head;
    }
    else
    {
        Node* tail = head;

        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        tail->next = other.head;
    }

    list_size += other.list_size;

    other.head = nullptr;
    other.list_size = 0;
}