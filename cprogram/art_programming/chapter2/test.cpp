
#include <cstdio>
#include <cstring>

#include "str_include1.h"
#include "str_include2.h"

int main(int argc, char** argv)
{
	char a[] = "acdempn";
	char b[] = "apdm";
	int result = str_include2(a,b);
	if(result == 1)
		printf("true\n");
	else if(result == -1)
		printf("Non-pointer!\n");
	else
		printf("false\n");
	
	return 0;
}

