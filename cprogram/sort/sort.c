#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "non_recursive_heapsort.c"
#include "quick_sort.cpp"
#define random(x) (rand()%x)
#define SEQ_LENGTH 100

static int heap_complexity=0;

// generate #quantity of numbers, stored in seq array
void generate_seq(int *seq, int quantity);
int  bubble_sort(int *source, int *dest, int length);
int insert_sort(int* dest, int length);
int heap_sort(int* dest, int length);
void build_maxheap(int* heap, int length);
extern void non_recursive_heapsort(int* dest, int length);
bool max_heapify(int* heap, int p_index, int length); /*p_index is the index of a parent*/
int main()
{
	int* seq;
	int k;
	seq = new int[SEQ_LENGTH];
	generate_seq(seq, SEQ_LENGTH);
	printf("The Original sequence is: \n");
	for(int i=0; i<SEQ_LENGTH; i++)
		printf("%d  ", seq[i]);
	printf("\n");
	
	int* dest;
	dest = new int[SEQ_LENGTH];
	int complexity;
	complexity = bubble_sort(seq, dest, SEQ_LENGTH);
	printf("After bubble sort: \n");
	for(int j=0; j<SEQ_LENGTH; j++)
		printf("%d  ", dest[j]);
	printf("\ncomplexity: %d\n\n", complexity);
	

	int* dest_insert = new int[SEQ_LENGTH];
	for(int k=0; k<SEQ_LENGTH; k++)
		dest_insert[k] = seq[k];
	insert_sort(dest_insert, SEQ_LENGTH);
	
	int* dest_heap = new int[SEQ_LENGTH];

	int* dest_nonrecursiveheap = new int[SEQ_LENGTH];
	int* dest_quicksort = new int[SEQ_LENGTH];
	for( k=0; k<SEQ_LENGTH; k++)
	{
		dest_heap[k] = seq[k];
		dest_nonrecursiveheap[k] = seq[k];
		dest_quicksort[k] = seq[k];
	}
	heap_sort(dest_heap, SEQ_LENGTH);
	non_recursive_heapsort(dest_nonrecursiveheap, SEQ_LENGTH);
	quick_sort(dest_quicksort, SEQ_LENGTH);
	

	delete []dest_heap;
	delete []dest;
	delete []dest_insert;
	delete []dest_nonrecursiveheap;
	delete []dest_quicksort;
	return 0;
}


void generate_seq(int *seq, int quantity)
{
	srand(time(0));
//	seq = new int[quantity];
	for(int i=0; i<quantity; i++)
	{
		seq[i] = random(1000);
	}
	return;
}


int  bubble_sort(int* source, int* dest, int length)
{
	int complexity = 0;
	for(int k=0; k<length; k++)
		dest[k] = source[k];

	int tmp;

	for(int i=0; i<length; i++)
		for(int j=i+1; j<length; j++)
			if(dest[j] < dest[i])
			{
				tmp = dest[j];
				dest[j] = dest[i];
				dest[i] = tmp;
				complexity ++;
			}

	return complexity;
}

int insert_sort(int* dest, int length)
{
	int complexity = 0;
//	int tmp;
/*	for(int i=0; i<length-1; i++)
		for(int j=i; j>=0; j--)
			if(dest[j+1] < dest[j])
			{
				complexity++;
				tmp = dest[j+1];
				dest[j+1] = dest[j];
				dest[j] = tmp;
			}
*/
	int first_unsorted;
	int current;
	int position;
	for(first_unsorted = 1; first_unsorted<length; first_unsorted++)
	{
		if(dest[first_unsorted] < dest[first_unsorted-1])
		{
			current = dest[first_unsorted];
			position = first_unsorted;
			do
			{
				dest[position] = dest[position-1];
				position--;
				complexity++;
			}
			while(position>0 && (dest[position-1] > current));
			dest[position] = current;
		}


	}
	

	printf("After Intertion sort:\n");

	for(int k=0; k<length; k++)
		printf("%d  ",dest[k]);
	printf("\n");
	printf("complexity is :%d\n", complexity);

	return complexity;
}


int heap_sort(int* dest, int length)
{
	int heap_size;
	int tmp;

	build_maxheap(dest, length);
	for(heap_size = length; heap_size>1; heap_size--)
	{
	//	build_maxheap(dest, heap_size, length);
		tmp = dest[0];
		dest[0] = dest[heap_size-1];
		dest[heap_size-1] = tmp;

		max_heapify(dest,0,heap_size-1);
	}
	
	
	
	
	
	printf("after heapsort:\n");
	for(int i=0; i<length; i++)
	{
		printf("%d  ", dest[i]);
	}
	printf("\nheap complexity: %d", heap_complexity);
	printf("\n");	
	return 0;
}

void build_maxheap(int* heap, int length)
{
	int i;
	for(i= (length-2)/2; i>=0; i--)
		max_heapify(heap, i, length);
	return;
}


// given an array with size length, and nodes under index p_index are all max-heaps.
// the max_heapify function is to make node p_index a max-heap.
bool max_heapify(int* heap, int p_index, int heap_size)
{
	int max_index,left,right;
	int tmp;
	max_index = p_index;
	left = 2*p_index+1;
	right = 2*p_index+2;
	if(left<heap_size && heap[left] > heap[p_index])
		max_index = left;
	if(right<heap_size && heap[right] > heap[max_index])
		max_index = right;
	if(max_index != p_index)
	{
		tmp = heap[max_index];
		heap[max_index] = heap[p_index];
		heap[p_index] = tmp;
		heap_complexity++;
		max_heapify(heap, max_index, heap_size);
	}

	
		
	return true;
}
