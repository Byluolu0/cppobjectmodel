#include <iostream>
using namespace std;

class VBase
{
public:
	int vb;
public:
	VBase(int x) : vb(x) {}
	virtual void vbf() { cout << "VBase::vbf()" << endl; }
	virtual void f() { cout << "VBase::f()" << endl; }
	virtual ~VBase() { cout << "~VBase()" << endl; }
};

class VDerive : virtual public VBase
{
public:
	int vd;
public:
	VDerive(int x, int y): VBase(x), vd(y) {}
	virtual void vdf() { cout << "VDerive::vdf()" << endl; }
	virtual void f() { cout << "VDerive::f()" << endl; }
	virtual ~VDerive() { cout << "~VDerive()" << endl; }
};
