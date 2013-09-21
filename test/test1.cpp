#include <iostream>
using namespace std;
class A
{
	public:
		int a[100];
};
class B:public A
{
	public:
		int a[200];
};

int main()
{
	A *a = new A();
	B *b = new B();
	for(int i = 0; i < 100; i++)
	//	((A* )b)->a[i] = 1;
		b->a[i] = 1;
	cout << b->a[0] << endl;
	cout << sizeof(*a) << sizeof(*b) <<endl;
}
