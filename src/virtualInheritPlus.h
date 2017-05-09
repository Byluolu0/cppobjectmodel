#include <iostream>
using namespace std;

class VB
{
public:
	int vb;
public:
	VB() : vb(1) {}
	virtual void vbf() { cout << "VB::vbf()" << endl; }
	virtual void f() { cout << "VB::f()" << endl; }
	virtual ~VB() { cout << "~VB()" << endl; }
};

class VFa1 : virtual public VB
{
public:
	int vfa1;
public:
	VFa1() : vfa1(2) {}
	virtual void vfa1f() { cout << "VFa1::vfa1f()" << endl; }
	virtual void f() { cout << "VFa1::f()" << endl; }
	virtual void f1() { cout << "VFa1::f1()" << endl; }
	virtual ~VFa1() {}
};

class VFa2 : virtual public VB
{
public:
	int vfa2;
public:
	VFa2() : vfa2(3) {}
	virtual void vfa2f() { cout << "VFa2::vfa2f()" << endl; }
	virtual void f() { cout << "VFa2::f()" << endl; }
	virtual void f2() { cout << "VFa2::f2()" << endl; }
 	virtual ~VFa2() {}
};

class VSon : public VFa1, public VFa2
{
public:
	int vson;
public:
	VSon() : vson(4) {}
	virtual void vsonf() { cout << "VSon::vsonf()" << endl; }
	virtual void f() { cout << "VSon::f()" << endl; }
	virtual void f1() { cout << "VSon::f1()" << endl; }
	virtual void f2() { cout << "VSon::f2()" << endl; }
	virtual ~VSon() {}
};
