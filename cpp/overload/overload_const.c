#include<iostream>
using namespace std;
class A{
	public:
		A();
		int foo(int *test);
		int foo(const int *test);
};
A::A(){
}
int A::foo(int *test){
	std::cout << *test << " A::foo(int *test)" <<std::endl;
	return 1;
}
int A::foo(const int *test){
	std::cout << *test << " A::foo(const int *test)" <<std::endl;
	return 1;
}
int main()
{
	const int b =5;
	int c = 3;
	A a;
	a.foo(&b);
	a.foo(&c);
	return 1;
}

