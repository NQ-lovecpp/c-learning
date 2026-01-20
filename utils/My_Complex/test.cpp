#include <iostream>
#include <cassert>
using namespace std;

//复数类
class Complex
{
public:
	//重载流插入
	friend ostream& operator<<(ostream& _cout, const Complex& c);

	//构造函数
	Complex(float real=0, float imag=0)
		:realpart(real)
		,imagpart(imag)
	{}

	//运算符重载
	Complex operator+(Complex c2)
	{
		Complex cret(realpart + c2.realpart, imagpart + c2.imagpart);
		return cret;
	}

	Complex operator-(Complex c2)
	{
		Complex cret(realpart - c2.realpart, imagpart - c2.imagpart);
		return cret;
	}

	Complex operator*(Complex c2)
	{
		float retr = realpart * c2.realpart - imagpart * c2.imagpart;
		float reti = imagpart * c2.realpart + realpart * c2.imagpart;
		return Complex(retr, reti);
	}

	Complex operator/(Complex c2)
	{
		float deno = c2.realpart * c2.realpart + c2.imagpart * c2.imagpart;
		assert(deno != 0);
		float retr = realpart * c2.realpart + imagpart * c2.imagpart;
		float reti = imagpart * c2.realpart - realpart * c2.imagpart;
		
		return Complex(retr/deno, reti/deno);
	}

private:
	float realpart;
	float imagpart;
};

ostream& operator<<(ostream& _cout, const Complex& c)
{
	_cout << c.realpart;
	if (c.imagpart >= 0)
	{
		_cout << "+";
	}
	cout << c.imagpart << "i";
	return _cout;
}

int main()
{
	Complex c1(1.1, 2.2);
	Complex c2(3.5, 4.6);
	Complex out1 = c1 + c2;
	Complex out2 = c1 - c2;
	Complex out3 = c1 * c2;
	Complex out4 = c1 / c2;


	cout << c1 << endl << c2 << endl;
	cout << "results:" << endl;
	cout << out1 << endl;
	cout << out2 << endl;
	cout << out3 << endl;
	cout << out4 << endl;

	return 0;
}