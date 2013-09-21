#include <iostream>
#include <string>
using namespace std;
void overload(const string& str1)
{
	cout << str1 << endl;
}	

void overload(const string& str2)
{
	cout << str2 << endl;
}

int main()
{
	string str1("haha");
	string str2("haha2");
	string& str3 = str2;
	overload(str1);
	overload(str3);
}
