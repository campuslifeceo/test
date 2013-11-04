#include <iostream>
using namespace std;

void left_rotate(char* arr, int len, int shift_amount);
void reverse( char* arr, int startpos, int endpos);
int main()
{
	char a[10] = {'a','b','c','d','e','f','g','h','i','j'};
	left_rotate(a, 10, 4);

	for(int i=0; i<10; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}

void left_rotate(char* arr, int len, int shift_amount)
{
	shift_amount %= len;
	reverse(arr, 0, shift_amount-1);
	reverse(arr, shift_amount, len-1);
	reverse(arr, 0, len-1);
}


void reverse( char* arr, int startpos, int endpos)
{
	char temp;
	if(startpos>9 || endpos>9 || startpos<0 || endpos<0)
		return;
	while(startpos<endpos)
	{
		temp = arr[startpos];
		arr[startpos] = arr[endpos];
		arr[endpos] = temp;
		startpos++;
		endpos--;
	}
}
