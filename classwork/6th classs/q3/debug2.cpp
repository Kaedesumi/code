#include <iostream>
using namespace std;

class A {
    int i, j;
public:
    A() { i = j = 0; }#include <iostream>
using namespace std;

class A {
    int i, j;
public:
    A() { i = j = 0; }
    void f() { i++; j++; }
};
class B {
    A* p;
public:
    B() { p = new A; }
    ~B() { delete p; p = NULL; }
    void g() { p->f(); }
};
void func(B x) { x.g(); }
int main() {
    B b1;
    func(b1);
    b1.g();
    return 0;
}
    void f() { i++; j++; }
};
class B {
    A* p;
public:
    B() { p = new A; }
    ~B() { delete p; p = NULL; }
    void g() { p->f(); }
};
void func(B x) { x.g(); }
int main() {
    B b1;
    func(b1);
    b1.g();
    return 0;
}