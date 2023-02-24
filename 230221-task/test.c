#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	float r, s;
//	r = 5.0;
//	s = 3.1415926 * r * r;
//	printf("%d", s);
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
#include <stdio.h>
int main()
{
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	*pFloat = 9.0;
	printf("num的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	return 0;
}