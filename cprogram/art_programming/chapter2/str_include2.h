#ifndef STR_INCLUDE2_H
#define STR_INCLUDE2_H
#include <cstring>

void str_swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}
int str_partition(char* str, int start_index, int end_index)
{
	char primary = str[end_index];
	int p_index = start_index-1;
	for(int i=start_index; i<end_index; i++)
	{
		if(str[i] < primary)
			str_swap(str[i], str[++p_index]);
	}
	str_swap(str[end_index], str[++p_index]);
	return p_index;
}



void str_sort(char* str, int  start_index, int end_index)
{
	int q;
	if(start_index<end_index)
	{
		q = str_partition(str, start_index, end_index);
		str_sort(str, start_index, q-1);
		str_sort(str, q+1, end_index);
	}
}


int str_include2(char* str_long, char* str_short)
{
	if(str_long == NULL || str_short == NULL)
		return -1;
	str_sort(str_long,0,strlen(str_long)-1);
	str_sort(str_short,0,strlen(str_short)-1);
	printf("%s\n%s\n", str_long, str_short);
	while(*str_short != '\0')
	{
		if(*str_short != *str_long)
		{
			++str_long;
			if(*str_long == '\0')
				return 0;
		}
		else
		{
			++str_long;
			++str_short;
		}
	}

	if(*str_short == '\0')
		return 1;

}
#endif
