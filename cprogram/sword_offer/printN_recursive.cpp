#include <cstdio>
#include <cstring>

const int N_MAX = 2;

void printNumber(char*);
void printRecursive(char*, int, int);

int main()
{
	char* number = new char[N_MAX+1];
	memset(number, '0', N_MAX);
	number[N_MAX] = '\0';

	for(int i=0; i<10; i++)
	{
		number[0] = '0' + i;
		printRecursive(number,N_MAX,0);
	}
	printf("\n");
	delete []number;
	return 0;
}


void printRecursive(char* number, int length, int cur_index)
{
	if(cur_index == length-1)
	{

		printNumber(number);
	
		return;
	}
	for(int i=0; i<10; i++)
	{
		number[cur_index+1]  = '0' + i;
		printRecursive(number, length, cur_index+1);
	}
}

void printNumber(char* number)
{
	int len = strlen(number);
	int first_nonzero_index;
	for(first_nonzero_index=0; first_nonzero_index<len; first_nonzero_index++)
	{
		if(number[first_nonzero_index] != '0')
			break;
	}
	for(int j=first_nonzero_index; j<len; j++)
	{
		printf("%d", number[j] -'0');
	}
	printf("\t");
}
