#include <iostream>

using namespace std;

/*
 * ÎÞ¼Ì³Ð£¬ÓÐÐéº¯Êý
 */

class Base
{
public:
	Base(int i) : baseI(i) {}
	int getI() { return baseI; }
	static void countI() {}
	virtual ~Base() {}
	virtual void print() { cout << "Base::print()" << endl; }
private:
	int baseI;
	static int baseS;
};
