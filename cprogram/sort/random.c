#include <iostream>
#include <stdlib.h>
#include <time.h>

#define random(x) (rand()%x)
using namespace std;

int main()
{
	srand((int)time(0));
	for(int i=0; i<10; i++)
		cout << random(100) << endl;

	cout << RAND_MAX;
	return 0;
}
