#include <iostream>
using namespace std;




void quick_sort(string &str, int start, int end);
int partition(string &str, int start, int end);
int compare(string str1, string str2);

int main()
{
	string str_long = "adoiunmqwerzxc";
	string str_short = "iuxcz";
	int len_long = str_long.length();
	quick_sort(str_long, 0, len_long-1);

	int len_short = str_short.length();
	quick_sort(str_short, 0, len_short-1);

	int flag = compare(str_long , str_short);
	cout << flag << endl;
	cout << str_long << endl;
	cout << str_short << endl;
}


int compare(string str1, string str2)
{
	int pos1=0, pos2=0;
	// assume str1 is longer that str2
	
	while(pos1<str1.length() && pos2<str2.length())
	{
		while(str1[pos1]<str2[pos2] && pos1<str1.length()-1)
			pos1++;
		if(str1[pos1]!= str2[pos2])
		{
			break;
		
		}
		pos2++;

	}

	if(pos2 == str2.length())
		return 1;
	else
		return 0;
}

void quick_sort(string &str, int start, int end)
{
	int k;
	if(start < end)
	{
		k = partition(str, start, end);
		quick_sort(str, start, k-1);
		quick_sort(str, k+1, end);
	}
}


int partition(string &str, int start, int end)
{
	int key = str[end];
	int last_lessthan_key = start - 1; // the last item that is less than key
	int i = start;
	
	for(i=start; i<end; i++)
	{
		if(str[i] <= key)
		{
			last_lessthan_key++;
			swap(str[i], str[last_lessthan_key]);
		}
	}

	swap(str[end], str[last_lessthan_key+1]);
	return last_lessthan_key+1;
}
