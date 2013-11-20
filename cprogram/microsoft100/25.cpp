#include <cstring>
#include <cstdio>
#include <cctype>


int continumax(char* outputstr, char* inputstr);
int continumax2(char* , char*);

int main(int argc, char** argv)
{
	char inputstr[] = "abcd12345ed125ss123456789";
//	char inputstr[] = "adsfnadnfaldjfja1";
	char* outputstr = new char[strlen(inputstr)];
	memset(outputstr, '0', strlen(outputstr));
	int count = continumax2(outputstr, inputstr);
	printf("%d\n", count);
	printf("%s\n", inputstr);
	printf("%s\n", outputstr);
	return 0;
}


int continumax2(char* outputstr, char* inputstr)
{
	int len = 0;
	int max_count = 0;
	char* start_index = NULL;
	while(1)
	{
		if(*inputstr >= '0' && *inputstr <= '9')
			len++;
		else
		{
			if(len > max_count)
			{
				start_index = inputstr - len;
				max_count = len;
			}
			len = 0;
		}

		if(*inputstr++ == '\0')
			break;
	}

	for(int i=0; i<max_count; i++)
		*outputstr++ = *start_index++;
	*outputstr = '\0';

	return max_count;
}

int continumax(char* outputstr, char* inputstr)
{
	bool isScanningDigit = false;
	int len = strlen(inputstr);
	int max_count = 0;
	int start_index = 0;
	int max_start_index = 0;


	for(int i=0; i<=len; i++)
	{
		if(isdigit(inputstr[i]) && !isScanningDigit)
		{
			isScanningDigit = true;
			start_index = i;
			continue;
		}

		if(!isdigit(inputstr[i]) && isScanningDigit)
		{
			isScanningDigit = false;
			if(max_count <(i-start_index))
			{
				max_start_index = start_index;
				max_count = i-start_index;
			}
		}
	}
	
	for(int j=0; j<max_count; j++)
		outputstr[j] = inputstr[j+max_start_index];

	outputstr[max_count] = '\0';

	return max_count;
}
