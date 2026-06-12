#include <iostream>
using namespace std;

struct Node{
    int content;
    Node *next; 
}; 

Node *head = nullptr;

class Ptr{
private:
    Node* p;

public:
    Ptr(Node* ptr = nullptr) {
        p = ptr;
    }

    int& operator*() {
        return p->content;
    }

    Ptr& operator++(int) {
        p = p->next;
        return *this;
    }

    bool operator!=(Node* ptr) {
        return p != ptr;
    }

    bool operator!=(const Ptr& other) {
        return p != other.p;
    }

    Ptr& operator=(Node* ptr) {
        p = ptr;
        return *this;
    }
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

    for (p++; p != nullptr; p++) {
        if (*p > *p_max) {
            p_max = p;
        }
    }

    return p_max; 
}

void list_sort(Ptr p){
    while (p != nullptr){

        Ptr p1 = list_max_element(p); 

        if (p1 != p) {

            int t = *p1;
            *p1 = *p;
            *p = t;
        }

        p++; 
    }
}

int main(){

    head = new Node{
        3,
        new Node{
            1,
            new Node{
                4,
                new Node{
                    2,
                    nullptr
                }
            }
        }
    };

    list_print(head);

    Ptr p;

    if ((p = list_max_element(head)) != nullptr){

        cout << *p << endl;
    }

    list_sort(head);

    list_print(head);
}