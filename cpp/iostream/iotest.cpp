#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int x;
	while(cin >> x)
	{
		;
	}
	if(cin.rdstate() & iostream::eofbit)
		cout << "eof\n";
	if(cin.rdstate() & iostream::failbit)
		cout << "fail\n";
	if(cin.rdstate() & iostream::badbit)
		cout << "bad\n"; 
	exit(0);
}
