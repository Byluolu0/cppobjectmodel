#include <iostream>

using namespace std;

/*
 * �޼̳У����麯��
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
