#include <cstring>
#include <cstdio>
const int N_MAX = 10 ;

void printToMaxOfNDigits(int n);
bool increase(char*);
void printNumber(char*);

int main()
{
	printToMaxOfNDigits(N_MAX);	
}



void printToMaxOfNDigits(int n)
{
	if(n<=0)
		return;
	char* number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';
	
	while(!increase(number))
		printNumber(number);

	printf("\n");
	
	delete []number;
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



bool increase(char* number)
{
	int sum = 0;
	bool isOverFlow = false;
	int flag = 0;
	int len = strlen(number);

	for(int i=len-1; i>=0; i--)
	{
		sum = number[i] - '0' + flag;

		if(i==len-1)
			sum++;

		if(sum>=10)
		{
			if(i==0)
				 isOverFlow = true;
			else
			{
				sum -= 10;
				flag = 1;
				number[i] = '0' + sum;
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}

	return isOverFlow;
}


