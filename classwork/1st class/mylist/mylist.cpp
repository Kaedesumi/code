#include "mylist.h"
#include <iostream>

using namespace std;


//构造函数
MyList::MyList(){
    head = nullptr;
    len = 0;
}

//析构函数
MyList::~MyList(){
    Node* cur = head;
    while (cur != nullptr)
    {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
}






//insert
void MyList::insert(int index, int value){
    //invalid
    if (index < 0 || index > len)
    {
        cout << -1 << endl;
        return;
    }
    
    //create newNode
    Node* newNode = new Node(value);
    //index == 0
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        len++;
        return;
    }
    //other
    Node* pre = head;
    for (int i = 1; i < index; i++)
    {
        pre = pre->next;
    }
    newNode->next = pre->next;
    pre->next = newNode;
    len++;
    return;
}
    








void MyList::remove(int index) {
    //invalid
    if (index < 0 || index > len)
    {
        cout << -1 << endl;
        return;
    }
    //0
    if (index == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        len--;
        return;
    }
    //other
    Node* pre = head;
    for (int i = 1; i < index; i++)
    {
        pre = pre->next;
    }
    Node* toDelete = pre->next;
    pre->next = toDelete->next;
    delete toDelete;
    len--;
    return;
}


int MyList::get(int index) const {
    return 0;
}



void MyList::set(int index, int value) {}

int MyList::size() const {
    return 0;
}

void MyList::clear() {}

int MyList::sum_from(int index, int k) const {
    return 0;
}

void MyList::reverse() {}

void MyList::merge(MyList& other) {}