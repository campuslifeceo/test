#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void func()
{
	static int i = 0;
	i =0;
	cout << ++i << endl;
}
int main()
{
	for(int i=0; i<10; i++)
		func();
	return 0;
}
