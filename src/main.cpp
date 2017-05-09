#include <nonInherit.h>
#include <singleInherit.h>
#include <multiInherit.h>
#include <multiInheritPlus.h>
#include <virtualInherit.h>
#include <virtualInheritPlus.h>

void testNonInherit()
{
	cout << " ----------  testNonInherit  ---------- " << endl;
	Base p(1000);

	cout << "对象的内存起始地址： " << &p << endl;

	cout << "虚函数表的地址： " << (int*)(&p) << endl;

	cout << "虚函数表第一个函数的地址： " << (int*)*(int*)(&p) << endl;

	cout << "虚函数表第二个函数的地址： " << (int*)*(int*)(&p) + 1 << endl;

	typedef void(*Fun)(void);
	Fun printFun = (Fun)*((int*)*(int*)(&p) + 1);
	cout << "调用虚函数： " << endl;
	printFun();

	cout << "baseI: " << *((int*)(&p) + 1) << endl;
}

void testSingleInherit()
{
	cout << " ----------  testSingleInherit  ---------- " << endl;

	typedef void(*Fun)(void);

	X x(100);

	int* xfvfa = (int*)*(int*)(&x);
	Fun xf1 = (Fun)*xfvfa;
	xf1();
	Fun xf2 = (Fun)*(xfvfa + 1);
	xf2();

	Y y(100, 200);

	y.f();
	y.g();
	y.h();

	int* yfvfa = (int*)*(int*)(&y);
	Fun yf1 = (Fun)*yfvfa;
	yf1();
	Fun yf2 = (Fun)*(yfvfa + 1);
	yf2();
	Fun yf4 = (Fun)*(yfvfa + 3);
	yf4();

	X* px = new Y(100, 200);
	int* pxfvfa = (int*)*(int*)px;
	Fun pxf1 = (Fun)*pxfvfa;
	pxf1();
	Fun pxf2 = (Fun)*(pxfvfa + 1);
	pxf2();
	Fun pxf4 = (Fun)*(pxfvfa + 3);
	pxf4();
}


void testMultiInherit()
{
	cout << " ----------  testMultiInherit  ---------- " << endl;
	typedef void(*Fun)(void);

	A* ptrA = new C();
	int* fa = (int*)*(int*)ptrA;
	Fun f1 = (Fun)*(fa + 1);
	f1();
	Fun f2 = (Fun)*(fa + 2);
	f2();
	B* ptrB = new C();
	int* fb = (int*)*(int*)ptrB;
	Fun ff1 = (Fun)*(fb + 1);
	ff1();
	Fun ff2 = (Fun)*(fb + 2);
	ff2();
	C* ptrC = new C();
	int* fc = (int*)*(int*)ptrC;
	Fun fc1 = (Fun)*(fc + 1);
	fc1();
	Fun fc2 = (Fun)*(fc + 2);
	fc2();
}

void testMultiInheritPlus()
{
	cout << " ----------  testMultiInheritPlus  ---------- " << endl;

	typedef void(*Fun)(void);

	Son s(1, 2, 3, 4, 5);
	int* sa = (int*)*(int*)(&s);
	Fun f1 = (Fun)*sa;
	f1();
	Fun f2 = (Fun)*(sa + 1);
	f2();
	//	Fun f3 = (Fun)*(sa + 2);
	//	f3();
	Fun f4 = (Fun)*(sa + 3);
	f4();
	Fun f5 = (Fun)*(sa + 4);
	f5();
	Fun f6 = (Fun)*(sa + 5);
	f6();
	cout << *((int*)(&s) + 1) << endl;
	cout << *((int*)(&s) + 2) << endl;
	cout << endl << "============================" << endl << endl;

	int* sa2 = (int*)*((int*)(&s) + 3);
	Fun f21 = (Fun)*(sa2);
	f21();
	Fun f22 = (Fun)*(sa2 + 1);
	f22();
	//Fun f23 = (Fun)*(sa2 + 2);
	//f23();
	Fun f24 = (Fun)*(sa2 + 3);
	f24();
	Fun f25 = (Fun)*(sa2 + 4);
	f25();

	cout << *((int*)(&s) + 4) << endl;
	cout << *((int*)(&s) + 5) << endl;
	cout << *((int*)(&s) + 6) << endl;
}

void testVirtualInherit()
{
	cout << " ----------  testVirtualInherit  ---------- " << endl;

	typedef void(*Fun)(void);

	VDerive temp(1, 2);
	int* add1 = (int*)*(int*)(&temp);
	Fun f11 = (Fun)*add1;
	f11();

	cout << *((int*)*((int*)(&temp) + 1) + 1) << endl; //VDerive 虚函数表与 父类虚函数表的偏移

	cout << *((int*)(&temp) + 2) << endl;

	int* add2 = (int*)*((int*)(&temp) - *(int*)*((int*)(&temp) + 1));
	Fun f21 = (Fun)*add2;
	f21();
	Fun f22 = (Fun)*(add2 + 1);
	f22();

	cout << *(((int*)(&temp) - *(int*)*((int*)(&temp) + 1)) + 1) << endl;
}

void testVirtualInheritPlus()
{
	cout << " ----------  testVirtualInheritPlus  ---------- " << endl;

	typedef void(*Fun)(void);

	VSon temp;
	int* add1 = (int*)*(int*)(&temp);
	Fun f11 = (Fun)*add1;
	f11();
	Fun f12 = (Fun)*(add1 + 1);
	f12();
	Fun f13 = (Fun)*(add1 + 2);
	f13();
	//这里没有析构函数
	//Fun f14 = (Fun)*(add1 + 3);
	//f14();

	cout << *(int*)*((int*)(&temp) + 1) << endl;
	cout << *((int*)*((int*)(&temp) + 1) + 1) << endl;

	cout << *((int*)(&temp) + 2) << endl;

	int* add2 = (int*)*((int*)(&temp) + 3);
	Fun f21 = (Fun)*add2;
	f21();
	Fun f22 = (Fun)*(add2 + 1);
	f22();
	//这里也没有析构函数
	//Fun f23 = (Fun)*(add2 + 2);
	//f23();

	cout << *(int*)*((int*)(&temp) + 4) << endl;
	cout << *((int*)*((int*)(&temp) + 4) + 1) << endl;

	cout << *((int*)(&temp) + 5) << endl;
	cout << *((int*)(&temp) + 6) << endl;

	int* add3 = (int*)*((int*)(&temp) + 8);
	Fun f31 = (Fun)*add3;
	f31();
	Fun f32 = (Fun)*(add3 + 1);
	f32();
	//析构函数在这里
	//Fun f33 = (Fun)*(add3 + 2);
	//f33();

	cout << *((int*)(&temp) + 9) << endl;
}

int main()
{
	testNonInherit(); // 无继承
	testSingleInherit(); // 单继承
	testMultiInherit(); // 多继承
	testMultiInheritPlus(); // 多继承，菱形
	testVirtualInherit(); // 虚拟继承
	testVirtualInheritPlus(); // 虚拟继承，菱形
	return 0;
}