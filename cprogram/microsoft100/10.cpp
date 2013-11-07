#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


char* reverseSentence(char*);
void reverseWord(char*, int, int);
int main()
{
	char sentence[] = "\" I     am  a student. so    is our teacher \"";
//	const char* non;
	char* reversed = reverseSentence(sentence);

	//printf(reversed);
	cout << reversed << endl;
}

char* reverseSentence(char* origin)
{
	
	int len = strlen(origin);
	cout << len << endl;
	char* reversed = new char[len+1];
	memset(reversed,'0',len);
	reversed[len] = '\0';
	
	int start_index = 0;
	bool isScanningWord = false;

	for(int i=0; i<len; i++)
	{
		reversed[i] = origin[len-1-i];
		if(reversed[i] == ' ' && !isScanningWord)
			start_index++;
		if(reversed[i] == ' ' && isScanningWord)
		{
			reverseWord(reversed, start_index, i-1);
			start_index = i+1;
			isScanningWord = false;
		}
		if(reversed[i] != ' ')
			isScanningWord = true;
	}

	return reversed;
}


void reverseWord(char* sentence, int start_index, int end_index)
{
	if(sentence == 0)
		return;
	char c;
	while(start_index < end_index)
	{
		c = sentence[start_index];
		sentence[start_index] = sentence[end_index];
		sentence[end_index] = c;
		start_index++;
		end_index--;
	}
}
