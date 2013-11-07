#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void func( int ic)
{
	const int& i = ic;
	ic++;
	cout << "i=" << i << endl
		<< "ic=" << ic << endl;
}
int main()
{
//	cout << 'c' - 'a' << endl;
//	cout << 'b' + 'a' << endl;
//    int i = char(20);
//	cout << char(35) - char(12) << endl;
	int i = '0';
	cout << i << endl;

	return 0;
}
