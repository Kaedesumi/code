#include <iostream>
using namespace std;

struct Node{
    int content;
    Node *next; 
}; 
Node *head=nullptr;

class Ptr{
    // TODO: 请实现智能指针类 Ptr
};

void list_print(Ptr p){
    while (p != nullptr){
        cout << *p << ','; 
        p++; 
    }
    cout << endl; 
} 
Ptr list_max_element(Ptr p){
    if (p == nullptr) return nullptr; 
    Ptr p_max = p;
    for (p++; p!=nullptr; p++) 
       if (*p > *p_max) p_max = p; 
    return p_max; 
} 
void list_sort(Ptr p){
    while (p != nullptr){
        Ptr p1=list_max_element(p); 
       if (p1 != p) { int t = *p1; *p1 = *p; *p = t; } 
       p++; 
    }
} 

int main(){
    //建立head指向的链表
    head = new Node{3, new Node{1, new Node{4, new Node{2, nullptr}}}};
    list_print(head); //显示head指向的链表中所有节点的值 
    Ptr p;
    if ((p = list_max_element(head)) != nullptr) //获取head指向的链表中最大节点的智能指针 
    cout << *p << endl; //输出链表中的最大元素 
    list_sort(head); //对head指向的链表中节点的值进行排序 
    list_print(head); 
}