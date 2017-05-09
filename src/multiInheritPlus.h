#include <iostream>
using namespace std;

class An
{
public:
	int an;

public:
	An(int x): an(x) {}
	virtual void f() { cout << "An::f()" << endl; }
	virtual void anf() { cout << "An::anf()" << endl; }
	virtual ~An() {}
};

class Fa1: public An
{
public:
	int fa1;
public:
	Fa1(int x, int y): An(x), fa1(y) {}
	virtual void f() { cout << "Fa1::f()" << endl; }
	virtual void f1() { cout << "Fa1::f1()" << endl; }
	virtual void fa1f() { cout << "Fa1::fa1f()" << endl; }
	virtual ~Fa1() {}
};

class Fa2 : public An
{
public:
	int fa2;
public:
	Fa2(int x, int y): An(x), fa2(y) {}
	virtual void f() { cout << "Fa2::f()" << endl; }
	virtual void f2() { cout << "Fa2::f2()" << endl; }
	virtual void fa2f() { cout << "Fa2::fa2f()" << endl; }
	virtual ~Fa2() {}
};

class Son : public Fa1, public Fa2
{
public:
	int son;
public:
	Son(int x, int y, int z, int i, int j): Fa1(x, y), Fa2(z, i), son(j) {}
	virtual void f() { cout << "Son::f()" << endl; }
	virtual void f1() { cout << "Son::f1()" << endl; }
	virtual void f2() { cout << "Son::f2()" << endl; }
	virtual void sonf() { cout << "Son::sonf()" << endl; }
	virtual ~Son() {}
};

void testMultiInheritPlus();