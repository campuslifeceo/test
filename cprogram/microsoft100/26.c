#include <stdio.h>
#include <string.h>


void left_rotate(char*, int);
void reverse(char*, int , int);
int main(int argc, char** argv)
{
	char test[] = "hello, this is really nice!";
	left_rotate(test, 3);
	printf("%s\n", test);
	return 0;
}


void left_rotate(char* origin, int left_shift)
{
	int len = strlen(origin);
	left_shift %= len;

	reverse(origin,0, left_shift-1);
	reverse(origin, left_shift, len-1);
	reverse(origin, 0, len-1);

}

void reverse(char* origin, int start_index, int end_index)
{
	char tmp;
	while(start_index < end_index)
	{
		tmp = origin[start_index];
		origin[start_index] = origin[end_index];
		origin[end_index] = tmp;
		start_index++;
		end_index--;
	}
}
