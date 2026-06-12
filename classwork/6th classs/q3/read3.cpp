#include <iostream>
using namespace std;

int x = 0;

class A {
    int m;
public:
    A(int i) {
        m = i; x += i;
        cout << 'a' << m << "'s constructor, x=" << x << endl;
    }
    ~A() { cout << "in a" << m << "'s destructor\n"; }
};

class B {
    int n;
public:
    B(int i) {
        n = i; x += i;
        cout << 'b' << n << "'s constructor, x=" << x << endl;
    }
    ~B() { cout << "in b" << n << "'s destructor\n"; }
};

class C : public B {
    A a1, a2;
public:
    C() : a2(2), a1(1), B(1) {
        cout << "in C's constructor\n";
    }
    ~C() { cout << "in C's destructor\n"; }
};

int main() {
    C c;
    return 0;
}