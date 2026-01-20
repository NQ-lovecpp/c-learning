#define _CRT_SECURE_NO_WARNINGS
////定义学生类型
//struct Stu
//{
//	//结构体成员
//	char name[20];
//	int age;
//	float weight;
//}s4, s5, s6;//全局变量
//int main()
//{
//	struct Stu S1;//局部变量
//	struct Stu S2;
//	struct Stu S3;
//	return 0;
//}

//struct
//{
//	char c;
//	int a;
//	double d;
//}s1, s2;
//
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//
//
//typedef struct
//{
//	int data;
//	char c;
//}haha;
//
//
//int main()
//{
//	struct Node n1;
//	struct Node n2;
//	n1.next = &n2;
//	return 0;
//}
//#include <stdio.h>
//#include <stddef.h>
//struct S1
//{
//	int a;
//	char c;
//};
//struct S2
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S3
//{
//	char c1;
//	int a;
//	char c2;
//	char c3;
//};
//
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n",offsetof(struct S1, c));
//	return 0;
//
//
//}

//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};

#pragma pack(16)
#pragma pack()


enum Sex
{
	MALE,
	FEMALE,
	SECRET
};

int main()
{
	enum Sex s=MALE
	return 0;
}