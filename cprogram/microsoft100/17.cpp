#include <iostream>
#include <cstring>
using namespace std;
#include <cassert>


char findFirstOnly(char*);
int main(int argc, char** argv)
{

	char test[] = "aabbccddeeff";
	char c = findFirstOnly(test);
	cout << test << endl << c << endl;
	return 0;
}

char findFirstOnly(char* test)
{
	int a[255];
	memset(a, 0, 255*sizeof(int));


	char* p = test;

	while(*p != '\0')
		a[*p++]++;
	p = test;
	while(*p++ != '\0')
	{
		if(a[*p] == 1)
			return *p;
	}
	return '\0';
}
