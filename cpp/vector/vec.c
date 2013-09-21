#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> vec1(24, 0);
	cout << vec1.size() << " " << vec1.max_size()
		<< " " << vec1.capacity() << endl;

}
