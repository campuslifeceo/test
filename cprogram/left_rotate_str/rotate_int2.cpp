#include <iostream>
using namespace std;

void inverse(int a[], int start, int end);
void left_rotate(int a[], int arr_size, int shift_amount);
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	left_rotate(a,10,4);

	for(int i=0; i<10; i++)
	{
		cout << a[i];
	}
	return 0;
}


void left_rotate(int a[], int arr_size, int shift_amount)
{
	shift_amount = shift_amount%arr_size;
	inverse(a,0,shift_amount-1);
	inverse(a,shift_amount,arr_size-1);
	inverse(a,0,arr_size-1);
}

void inverse(int a[], int start, int end)
{
	int temp;
	if(start>9 || end>9 || start<0 || end<0)
		return;
	while(start<end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}
