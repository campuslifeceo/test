#include <iostream>
using namespace std;
void right_rotate(int* arr, int N, int K);
void invert(int* arr, int start, int end);
void swap(int& tempa, int& tempb);

int main()
{
	int source[7] = {1,2,3,4,5,6,7};
	right_rotate(source,7,3);
	for(int i=0; i<7; i++)
	{
		cout << source[i] << " ";
	}
	cout << endl;
	return 0;
}


void right_rotate(int* arr, int N, int K)
{
	K%=N;
	invert(arr,0,N-K-1);
	invert(arr,N-K,N-1);
	invert(arr,0,N-1);
}

void invert(int* arr, int start, int end)
{
	while(start<end)
	{
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}

void swap(int & tempa, int & tempb)
{
	int temp;
	temp = tempa;
	tempa = tempb;
	tempb = temp;
}



