#include <iostream>
using namespace std;

struct Node{
    int content;
    Node *next; 
}; 
Node *head=nullptr;

class Ptr{
    // TODO: 请实现智能指针类 Ptr
private:
    Node* ptr;   // 真正保存的链表节点指针
public:
    // 构造函数：允许 Node* 自动转换成 Ptr  
    Ptr(Node* p = nullptr) {
        ptr = p;
    }
    // 解引用：让 *p 表示当前节点的 content
    int& operator*() {
        return ptr->content;
    }
    // 后置++：让 p++ 移动到下一个节点
    Ptr operator++(int) {
        Ptr old = *this;
        if (ptr != nullptr) {
            ptr = ptr->next;
        }
        return old;
    }
    // 判断 Ptr 是否不等于 nullptr
    bool operator!=(nullptr_t) const {
        return ptr != nullptr;
    }
    // 判断 Ptr 是否等于 nullptr
    bool operator==(nullptr_t) const {
        return ptr == nullptr;
    }
    // 判断两个 Ptr 是否不相等
    bool operator!=(const Ptr& other) const {
        return ptr != other.ptr;
    }
    //========p++代表移动到下一个==========

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