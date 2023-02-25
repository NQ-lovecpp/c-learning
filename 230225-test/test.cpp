#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	float r, s;
//	r = 5.0;
//	s = 3.1415926 * r * r;
//	printf("%f", s);
//	return 0;
//}

//#include iostream
//main();
//float rs;
//r = 5.0;
//s = 3.14159 * r * r;
//cout << s << end1

//#include iostream
//main
//{ floata,b,c,v;
//a = 2.0;b = 3.0;c = 4.0;v = a * b * c;
//cout << v << end1
//}

//#include <iostream>
//using namespace std;
//void main()
//{
//	int a, b, c, x;
//	a = 15, b = 18, c = 21;
//	x = a < b || c++;
//	cout << "x=" << x << " c=" << c << '\n';
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int i, j, m, n;
//	i = 8;
//	j = 10;
//	m = ++i;
//	n = j++;
//	cout << i << ',' << j << ',' << n << ',' << n << '\n';
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a;
//	char ch;
//	printf("请输入一个0~128的整数和一个字符：");
//	scanf("%d%c", &a, &ch);
//	ch = ch + a;
//	printf("%c", ch);
//	printf("%d", a);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	long long a = 100000;
//	long long b = 100000, c = 1000;
//	printf("%lld", a * b / c);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b;
//	printf("请输入两个整数：");
//	scanf("%d %d", &a, &b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("\n变换后：%d %d", a, b);
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	float a, b, c;
//	float p = 0;
//	float S, C;
//	printf("请输入三角形的三边长：");
//	scanf("%f %f %f", &a, &b, &c);
//	p = (a + b + c) / 2;
//	S = sqrt((p - a) * (p - b) * (p - c) * p);
//	C = a + b + c;
//	printf("周长为：%f，面积为：%f", C, S);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d %d", a / b, a % b);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float a, b, c, v;
//	a = 2.0;
//	b = 3.0;
//	c = 4.0;
//	v = a * b * c;
//	printf("%f", v);
//}

#include <stdio.h>
float divide(float a)
{
	return 1 / (1 + a);
}
int main()
{
	float x, y;
	scanf("%f %f", &x, &y);
	printf("%f", divide(divide(1 / (x + y))));
}
