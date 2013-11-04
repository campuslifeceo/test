#include <iostream>
using namespace std;


void check_cover(string longstr, string shortstr);

int main()

{
	string longstr = "abcefghijklmnopqrstuvwxyz";
	string shortstr = "and";

	check_cover(longstr, shortstr);

	return 0;
}


//////////////////////////////	
void  check_cover( longstr, string shortstr)
{
	int len_long = longstr.length();
	int len_short = shortstr.length();
	int i,j;

	for( j=0; j<len_short; j++)
	{
		for( i=0; i<len_long; i++)
		{
			if(longstr[i] == shortstr[j])
				break;
			else if(i == len_long-1)
			{

				cout << " false " << endl;
				return;
			}
		}
	}
	
	cout << "true" << endl;

}
