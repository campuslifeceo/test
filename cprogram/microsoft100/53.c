#include <iostream>
#include <cassert>

using namespace std;


void str_permute(char*);
void str_permutation(char*, char*);
void exchange(char*, char*);

int main(int argc, char** argv)
{
	char input[] = "abc";
	str_permute(input);
}


void str_permute(char* str)
{
	str_permutation(str, str);
}

void str_permutation(char* str, char* pBegin)
{
	assert(str && pBegin);

	if(*pBegin == '\0')
		cout << str << endl;
	else
	{

		char* pCh = pBegin;

		while(*pCh != '\0')
		{
			exchange(pCh, pBegin);
			str_permutation(str, pBegin+1);
			exchange(pCh, pBegin);

			pCh++;
		}
	}
	
}

void exchange(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
