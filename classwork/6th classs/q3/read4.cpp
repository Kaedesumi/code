#include <iostream>
using namespace std;

class A {
    int x, y;
public:
    A() { cout << "in A's constructor\n"; f(); }
    virtual void f() { cout << "in A's f\n"; }
    void g() { cout << "in A's g\n"; }
    virtual ~A() { cout << "in A's destructor\n"; f(); }
};

class B : public A {
    int z;
public:
    B() { cout << "in B's constructor\n"; }
    void f() override { cout << "in B's f\n"; }
    void g() { cout << "in B's g\n"; }
    ~B() { cout << "in B's destructor\n"; }
};

void func(A& x) {
    x.f();
    x.g();
}

int main() {
    cout << "------Section 1------\n";
    B b;
    cout << "------Section 2------\n";
    func(b);
    cout << "------Section 3------\n";
    A* p = new B;
    cout << "------Section 4------\n";
    p->f();
    cout << "------Section 5------\n";
    p->g();
    cout << "------Section 6------\n";
    delete p;
    cout << "------Section 7------\n";
    return 0;
}