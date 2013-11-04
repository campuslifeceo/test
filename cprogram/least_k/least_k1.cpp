#include <iostream>
#include <time.h>
using namespace std;


int find_max(int a[]);
void find_k_least(int a[], int b[], int k);
int main()
{
	int start = clock();
	int end = clock();
	cout <<(end-start)/CLOCKS_PER_SEC << endl;

	int a[100];
	for(int i=0; i<100; i++)
		a[i] = i;
	a[0] = 342;
	a[1] = 45;
	a[2] = 0;
	a[38] = -1;
	a[46] = -3;
	a[58] = 3;

	int b[10];

	find_k_least(a, b, 10);

	for(int j=0; j<10; j++)
		cout << b[j] << endl;
	return 0;
}



void find_k_least(int a[], int b[], int k)
{
	int kmax_index;
	for(int i=0; i<k; i++)
	{
		b[i] = a[i];
	}
	kmax_index = find_max(b);
	for(int j=k; j != '\0'; j++)
	{
		if(a[j]<b[kmax_index])
		{
			b[kmax_index]=a[j];
			kmax_index = find_max(b);
		}
	}
}


int find_max(int a[])
{
	int i = 1;
	int max=a[0];
	int index = 0;
	while(a[i] != '\0')
	{
		if(a[i]>max)
		{	
			max = a[i];
			index = i;
		}
		i++;
	}

	return index;
}
