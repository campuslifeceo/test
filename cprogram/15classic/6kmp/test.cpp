#include <cstdio>
#include <cstring>


int my_atoi(char*);
int main(int argc, char** argv)
{
	char a[] = "4038403";
	int result = my_atoi(a);
	printf("%d \n", result);
}

int my_atoi(char* str)
{
	int result = str[0] - '0';
	int len = strlen(str);
	for(int i=1; i<len; ++i)
	{
		result = (result)*10 + str[i] -'0';
	}

	return result;
}
