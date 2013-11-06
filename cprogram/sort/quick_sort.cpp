// this is an implementation of quick_sort

#include <iostream>
using namespace std;

void real_sort(int*, int, int);
void myswap(int*, int*);
int partition(int*, int ,int);

void quick_sort(int* dest, int length)
{
	real_sort(dest, 0, length-1);
	
	
	for(int i=0; i<length; i++)
	{
		cout << dest[i] << "  ";
	}

	cout << endl;
	
}

void real_sort(int* dest, int low, int high)

{
	int q;
	if(low<high)
	{
		q = partition(dest, low, high);
		real_sort(dest, low, q-1);
		real_sort(dest, q+1, high);
	}
}


// given a sub set of dest, the partition function works to return
// an index i  that, after partition, the items before index i is 
// less than sub_dest[i], and items after index i is greater that
// sub_dest[i]. and we fill the content of sub_dest[i] by sub_dest[end_index],
// which is the last item of the current array.

int partition(int* sub_dest, int start_index, int end_index)
{
	// do some justifications
	int primary = 	sub_dest[end_index];
	int serve_index = start_index -1;
	int j;
	int temp;
	for( j=start_index; j < end_index; j++)
	{
		if(sub_dest[j]<primary)
		{
			serve_index++;
			temp = sub_dest[serve_index];
			sub_dest[serve_index] = sub_dest[j];
			sub_dest[j] = temp;
		}
	}

	temp = sub_dest[serve_index+1];
	sub_dest[serve_index+1] = sub_dest[end_index];
	sub_dest[end_index] = temp;
	return serve_index+1;
}


void myswap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
