#include <iostream>
using namespace std;

class X
{
public:
	X(int x = 100) : a(x) {}
	virtual void f() { cout << "X::f()" << endl; }
	virtual void g() { cout << "X::g()" << endl; }
	virtual ~X() {}
private:
	int a;
};

class Y: public X
{
public:
	Y(int x, int y) : X(x), b(y) {}
	virtual void f() { cout << "Y::f()" << endl; }
	virtual void h() { cout << "Y::h()" << endl; }
	virtual ~Y() {}
private:
	int b;
};

void testSingleInherit();