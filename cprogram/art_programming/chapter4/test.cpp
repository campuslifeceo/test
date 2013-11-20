#include "mystr.h"
#include "mystr.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	char *str = NULL;
	char substr[] = "abcdef";
	if(my_strcmp(str, substr))
	{
		cout << my_strstr(str, substr) << endl;
		cout << my_strlen(str) << endl;
	}
	
	return 0;
}
