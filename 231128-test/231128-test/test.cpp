#include <iostream>
using namespace std;

int main()
{
	long double ld = 3.1415926536;
	int a{ ld }, b = { ld };       // 编译器报错，存在丢失信息的风险
	int c(ld), d = ld;             //正确
	cout << ld << " " << a << " " << b << " " << c << " " << d << endl;
	return 0;
}

