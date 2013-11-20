#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

struct X;
struct Y
{
	void f(X);
};

struct X
{
	private:
		int i;
	public:
		void initialize();
		friend void g(X*, int);
		friend void Y::f(X);
		friend struct Z;
		friend void h();
		int	get_x();
};

int X::get_x()
{
	return i;
}


void X::initialize()
{
	i = 0;
}

void g(X* x, int i)
{
	x->i = i;
}

void Y::f(X x)
{
	x.i = 47;
}

struct Z
{
	private:
		int j;
	public:
		void initialize();
		void g(X* x);
};

void Z::initialize()
{
	j = 99;
}

void Z::g(X* x)
{
	x->i += j;
}

void h()
{
	X x;
	x.i=100;
}


int main()
{
	int a[3] = {1};
	double *b = new double[3];	
	cout << sizeof(b) << endl
		<< sizeof(*b) << endl;
}















