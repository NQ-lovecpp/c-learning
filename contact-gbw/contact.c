#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//静态的版本
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
int CheckCapacity(Contact* pc);

void LoadContact(Contact* pc)
{
	//打开文件

	FILE* pf=fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//读文件
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;

}


//动态的版本
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("通讯录初始化失败:%s\n", strerror(errno));
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	LoadContact(pc);
}

void DestroyConact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("释放内存.....\n");
}

//静态的版本
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("通讯录已满，无法增加\n");
//		return;
//	}
//	printf("请输入名字:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入电话:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址:>");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("添加成功\n");
//}

//扩容失败 返回0
//扩容成功，不需要扩容 返回1
int CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("CheckCapacity:%s\n", strerror(errno));
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功，当前容量：%d\n", pc->capacity);
			return 1;
		}
	}
	return 1;
}

void AddContact(Contact* pc)
{
	if (0 == CheckCapacity(pc))
	{
		printf("空间不够，扩容失败\n");
		return;
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[pc->sz].addr);

		pc->sz++;
		printf("添加成功\n");
	}
}

void ShowContact(const Contact* pc)
{
	int i = 0;
	//姓名      年龄      性别     电话      地址
	//zhangsan 20        男      123456    北京
	//
	//打印标题
	printf("%-10s %-4s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s %-4d %-5s %-12s %-30s\n",
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

static int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void DelContact(pContact pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	//删除
	//1. 找到要删除的人 - 位置（下标）
	printf("输入要删除人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	int i = 0;
	//2. 删除 - 删除pos位置上的数据
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	//查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	//打印
	printf("%-10s %-4s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	//打印数据
	printf("%-10s %-4d %-5s %-12s %-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	//修改
	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pos].addr);

	printf("修改成功\n");
}


//按照名字来排序
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_by_name);
	printf("排序成功\n");
}


void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("Savecontact::fopen");
		return 1;
	}
	//写数据
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		fwrite(pc->data + i, sizeof(struct PeoInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
	//关闭文件
	printf("保存成功！\n");
}
