#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>


int ch_to_int(char*);
int my_atoi(const char*);
int main()
{
	char orgin_int[] = "-123234";
	int result = 0;
	result = my_atoi(orgin_int);
	printf("%d\n", result);
	return 0;
}

int ch_to_int(char* origin)
{
	int len = strlen(origin);
	int sum = 0;

	for(int i=len-1; i>=0; --i)
	{
		sum += (origin[i] - '0')*(pow(10, len-i-1));
	}
	return sum;
}

int my_atoi(const char* origin)
{
	int sum = 0;
	bool neg_flag = false;
	if(*origin == '-' || *origin == '+')
		neg_flag = (*origin++ == '-');

	while(isdigit(*origin))
		sum = sum*10 + (*origin++ - '0');
	if(neg_flag)
		sum = -sum;
	return sum;
}
