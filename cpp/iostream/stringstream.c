#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int val1 = 512, val2 = 1024;
	ostringstream format_message;
	format_message << "val1" << val1 << "\n"
		           << "val2" << val2 << "\n";
	//cout << format_message;
	istringstream input_string(format_message.str());
	string dump;
	val1 = val2 = 0;
	input_string >> dump >> val1 >> dump >> val2;
	cout << val1 << " " << val2 << " " << endl;
	return 0;
}

