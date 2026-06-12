#include <iostream>
using namespace std;

class A {
    int x, y;
    void f1() { x = y = z = 0; }
protected:
    int z;
    void f2() { x++; y++; z++; }
public:
    void f3() { z = x + y; }
};
class B : public A {
    int m;
public:
    void f4() { m = x + y + z; f1(); f2(); f3(); }
};
int main() {
    A a;
    a.f1(); a.f2(); a.f3();
    B b;
    b.f1(); b.f2(); b.f3(); b.f4();
    return 0;
}   