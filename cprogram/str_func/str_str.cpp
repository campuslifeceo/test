#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_str(char* original, char* substring)
{
	if(original == NULL || substring == NULL)
		return -1;

	int origin_len = strlen(original);
	int sub_len = strlen(substring);

	if(origin_len < sub_len)
		return -1;
	
	int compare_len = origin_len - sub_len;
	for(int i=0; i<compare_len; i++)
	{
		for(int j=0; j<sub_len; j++)
		{
			if(original[i+j] != substring[j])
				break;
			if(j == sub_len-1)
				return i+1;
		}
	}
}

int main()
{
	char a[] = "abcdf";
	char b[] = "cd";

	int index = str_str(a,b);
	printf("%d", index);
	return 0;
}
