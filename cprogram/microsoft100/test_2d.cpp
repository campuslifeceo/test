#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int m=2, n=3;
	int i,j;
	int** table = new int*[m];
	for( i=0; i<m;i++)
		table[i] = new int[n];

	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
		{
			table[i][j] = i+j;
			cout << table[i][j] << "\t";
		}

	cout << endl;

	for(i=0; i<m; ++i)
		delete[] table[i];

	delete table;

	return 0;
}

