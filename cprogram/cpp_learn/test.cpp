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
//	for(int i=0; i<10; i++)
//		func();
//	const char* ch = "hello";
//	cout << ch << endl;
	func(5);
	int i = 5;
	func(i);
	return 0;
}
