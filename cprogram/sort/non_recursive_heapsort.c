#include <stdio.h>
/*
 * Heapsort proceeds in two phases. First, we must arrange the entries
 * in the list so that they satisfy the requirements for a heap.
 * Second, we repeatedly remove the top of the heap and promote another
 * entry to take its place.
 * */


void insert_heap(int* heap, int current, int low_index, int high_index);
void build_heap(int* heap, int length);
void non_recursive_heapsort(int* dest, int length)
{
	build_heap(dest, length);
	int current;
	for(int last_unsorted=length-1; last_unsorted>0; last_unsorted--)
	{
		current = dest[last_unsorted];
		dest[last_unsorted] = dest[0];
		insert_heap(dest, current, 0, last_unsorted-1);
	
	}
	printf("\nAfter non-recursive-heapsort:\n");
	for(int i=0; i<length; i++)
		printf("%d  ",dest[i]);
	printf("\n");
	return;
}

/*
 *
 */

void build_heap(int* heap, int length)
{
	int build_index; // the index  to be built	
	int tmp;
	for(build_index = (length-2)/2; build_index>=0; --build_index)
	{
		tmp = heap[build_index];
		insert_heap(heap, tmp, build_index, length-1);
	}
}



/*
 * the heap with index from low_index+1 to high_index holds the heap property.
 * after insert the item current into the heap, this function makes the heap
 * satisfy heap property from index low_index to high_index.
 *
 * the temporary variable max_index holds the index of the maximum item.
 * */
void insert_heap(int* heap, int current, int low_index, int high_index)
{
	int max_index;
	max_index = 2*low_index + 1;

	while(max_index <= high_index)
	{
		
		if(max_index < high_index && heap[max_index+1] > heap[max_index])
		{
			max_index++;
		}
		if(heap[max_index] < current)
			break;
		else
		{
			heap[low_index] = heap[max_index];
			low_index = max_index;
			max_index = 2*low_index + 1;
		}			
	}

	heap[low_index] = current;
	return;
}
