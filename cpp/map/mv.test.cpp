#include <map>
#include <iostream>
using namespace std;


int main()
{
	map<string,int> wordcount;
	int occurs = wordcount["zhangyue"];
	cout << occurs <<" ";
	occurs = wordcount["zhangyue"];
	cout << occurs;
	cout << endl;

}
