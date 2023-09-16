#include <iostream>
using namespace std;

class Complex
{
public:
	friend ostream& operator<<(ostream& _cout, const Complex& c);

	Complex(float real=0, float imag=0)
		:realpart(real)
		,imagpart(imag)
	{
		;
	}

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
		float retr = realpart * c2.realpart + imagpart * c2.imagpart;
		float reti = imagpart * c2.realpart - realpart * c2.imagpart;
		float deno = c2.realpart * c2.realpart + c2.imagpart * c2.imagpart;
		return Complex(retr/deno, reti/deno);
	}

private:
	float realpart;
	float imagpart;
};

ostream& operator<<(ostream& _cout, const Complex& c)
{
	_cout << c.realpart << "+" << c.imagpart << "i" << endl;
	return _cout;
}

int main()
{
	Complex c1(1.1, 2.2);
	Complex c2(3.5, 4.6);
	Complex out = c1 + c2;

	cout << c1 << c2 << out << endl;

	return 0;
}