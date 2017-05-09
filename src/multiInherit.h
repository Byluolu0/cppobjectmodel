#include <iostream>
using namespace std;

class A
{
public:
	A() {}
	virtual ~A() {}
	virtual void f() { cout << "A::f()" << endl; }
	virtual void g() { cout << "A::g()" << endl; }
protected:
	int a;
};

class B
{
public:
	B() {}
	virtual ~B() {}
	virtual void h() { cout << "B::h()" << endl; }
	virtual void g() { cout << "B::g()" << endl; }
protected:
	int b;
};

class C : public A, public B
{
public:
	C() {}
	virtual ~C() {}
	virtual void g() { cout << "C::g()" << endl; }
private:
	int c;
};

