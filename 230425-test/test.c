#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//typedef struct stud
//{
//	int number;
//	char name[30];
//	float sub1;
//	float sub2;
//	float sub3;
//	float sub4;
//}stud;
//void pr(stud s)
//{
//	printf("-----------------------\n");
//	printf("学生编号：%d\n", s.number);
//	printf("学生姓名：%s\n", s.name);
//	printf("Python成绩：	%f\n", s.sub1);
//	printf("Java成绩：	%f\n", s.sub2);
//	printf("C++成绩：	%f\n", s.sub3);
//	printf("数学成绩：	%f\n", s.sub4);
//}
//
//int main()
//{
//	stud s1 = { 001,"guamao",100,100,100,0 };
//	stud s2 = { 002,"sangyong",0,0,0,0 };
//	pr(s1);
//	pr(s2);
//	return 0;
//}

//#include <stdio.h>
//typedef struct stud
//{
//	int number;
//	char name[30];
//	float sub1;
//}stud;
//
//void print(stud s)
//{
//	printf("-----------------------\n");
//	printf("学生编号：%3d\n", s.number);
//	printf("学生姓名：%s\n", s.name);
//	printf("Python成绩：	%f\n", s.sub1);
//}
//
//void scan(int num,stud* s)
//{
//	s->number = num;
//	printf("请输入姓名：");
//	scanf("%s", &(s->name));
//	printf("请输入成绩：");
//	scanf("%f", &(s->sub1));
//}
//
//int main()
//{
//	int n = 0;
//	stud arr[10] = { 0 };
//	printf("输入几组数据？");
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++)
//	{
//		scan(i,&arr[i]);
//	}
//	for (int i = 0;i < n;i++)
//	{
//		print(arr[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <math.h>
//typedef struct coor
//{
//	float x;
//	float y;
//	float z;
//}coor;
//int main()
//{
//	coor s1 = { 0,0,0 };
//	coor s2 = { 0,0,0 };
//	printf("请输入第一个坐标：");
//	scanf("%f %f %f", &s1.x, &s1.y, &s1.z);
//	printf("请输入第二个坐标：");
//	scanf("%f %f %f", &s2.x, &s2.y, &s2.z);
//	float sum = sqrt((s1.x + s2.x) * (s1.x + s2.x) + 
//					 (s1.y + s2.y) * (s1.y + s2.y) + 
//			         (s1.z + s2.z) * (s1.z + s2.z));
//	printf("两点间距离=%f", sum);
//
//	return 0;
//}

#include <stdio.h>
typedef struct stud
{
	int number;
	char name[30];
	float en;
	float math;
	float phy;
	float sum;
}stud;

void bubblesort(stud* arr, int arrlen)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < arrlen - 1;i++)
	{
		for (j = 0;j < arrlen - 1 - i;j++)
		{
			if (arr[j].sum > arr[j + 1].sum)
			{
				stud tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	stud arr[10] = { 0 };
	for (i = 0;i < 10;i++)
	{
		printf("--------------------\n");
		arr[0].number = i;
		printf("请输入姓名：");
		scanf("%s", &(arr[i].name));
		printf("请输入成绩：");
		scanf("%f", &(arr[i].en));
		printf("请输入成绩：");
		scanf("%f", &(arr[i].math));
		printf("请输入成绩：");
		scanf("%f", &(arr[i].phy));
		arr[i].sum = arr[i].en + arr[i].math + arr[i].phy;
	}

	bubblesort(arr, 10);
	printf("最高分学生数据：\n");
	printf("学生编号：%3d\n", arr[9].number);
	printf("学生姓名：%s\n", arr[9].name);
	printf("数学成绩：	%f\n", arr[9].math);
	printf("英语成绩：	%f\n", arr[9].en);
	printf("物理成绩： % f\n", arr[9].phy);

	return 0;
}