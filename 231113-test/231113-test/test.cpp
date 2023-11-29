#include <iostream>
using namespace std;

class Integer 
{
	friend ostream& operator<<(ostream& _cout, Integer num);
public:
	Integer(int i)
		:value(i)
	{}
	Integer(const Integer& i)
		:value(i.value)
	{}

	Integer operator+(const Integer& sec)
	{
		Integer ret(sec.value + value);
		return ret;
	}

	Integer operator++()
	{
		value++;
		return *this;
	}

	Integer operator++(int)
	{
		Integer ret(*this);
		value++;
		return ret;
	}

	Integer operator+=(int val)
	{
		value += val;
		return *this;
	}
private:
	int value;
};

ostream& operator<<(ostream& _cout, Integer num)
{
	_cout << num.value;
	return _cout;
}
int main()
{
	Integer i1(10);
	Integer i2 = 24;
	Integer i3(0);

	cout << ++i1 << endl;
	cout << i2++ << endl;
	i3 = i1 + i2;
	cout << i3 << endl;
	i3 += 10;
	cout << i3 << endl;
	return 0;
}