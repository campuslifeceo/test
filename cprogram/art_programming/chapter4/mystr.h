#ifndef _MYSTR_H_
#define _MYSTR_H_
#include <string.h>

int my_strstr(char* str, char* substr)
{
	if(str == NULL || substr == NULL)
		return -1;

	int lenstr = strlen(str);
	int lensub = strlen(substr);

	if(lenstr < lensub)
		return -1;

	int last_position = lenstr-lensub;

	int i,j;
	for(i=0; i<=last_position; i++)
	{
		for(j=0; j<lensub; j++)
		{
			if(str[i+j] != substr[j])
				break;
			if(j == lensub-1)
				return i+1;
		}
	}

	return -1;
}

bool my_strcmp(char* stra, char* strb)
{
	if(stra==NULL || strb==NULL)
		return false;
	
	int lena = strlen(stra);
	int lenb = strlen(strb);
	if(lena != lenb)
		return false;
	int i,j;
	for(j=0; j<lenb; ++j)
	{
		if(stra[j] != strb[j])
			return false;
	}

	if(j == lenb)
		return true;
}

int my_strlen(char* str)
{
	if(str == NULL)
		return -1;

	int len = 0;
	while(*str++ != '\0')
		++len;

	return len;
}
#endif

