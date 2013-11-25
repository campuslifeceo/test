#include <iostream>
using namespace std;

class X
{
	int i;
public:
	X()
	{
		i = 0;
	}

	void set(int ii)
	{
		i = ii;
	}

	int read() const
	{
		return i;
	}

	int permute()
	{
		return i = i* 47;
	}

};


class Y : public X
{
	int i;
public:
	Y()
	{
		i = 0;
	}

	int change()
	{
		i = permute();
		return i;
	}

	void set(int ii)
	{
		i = ii;
		X::set(ii);
	}
};


int main()
{
	cout << "sizeof(X) = " << sizeof(X) << endl;
	cout << "sizeof(Y) = " << sizeof(Y) << endl;

	Y D;
	D.change();
	D.read();
	D.permute();
	D.set(12);
}
