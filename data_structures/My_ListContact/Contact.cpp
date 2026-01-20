#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

Contact::Contact()
{}

Contact::~Contact()
{}

void Contact::AddContact()
{
	ContactNode d;

	cout << "请输入姓名:" << endl;
	cin >> d.name;
	cout << "请输入年龄:" << endl;
	cin >> d.age;
	cout << "请输入性别:" << endl;
	cin >> d.sex;
	cout << "请输入电话:" << endl;
	cin >> d.tele;

	con.push_back(d);
	cout << "添加成功\n";
}

void Contact::ShowContact()
{
	//姓名      年龄      性别     电话 
	//zhangsan 20        男      123456 
	
	//打印标题
	printf("\n---------------------------------------------------\n");
	printf("| %-4s | %-10s | %-4s | %-5s | %-12s |\n", "序号", "姓名", "年龄", "性别", "电话");


	//打印数据
	int i = 0;
	for (auto& node:con)
	{
		printf("| %-4d | %-10s | %-4d | %-5s | %-12s |\n", i+1, node.name.c_str(), node.age, node.sex.c_str(), node.tele.c_str());
		i++;
	}
	printf("---------------------------------------------------\n\n");
}

void Contact::DelContact()
{
	std::string name;
	if (con.size() == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	//删除
	//1. 找到要删除的人 - 位置（节点）
	printf("输入要删除人的名字:>");
	cin>>name;

	bool flag = false;
	for (auto it=con.begin();it!=con.end();it++)
	{
		if (name == it->name)
		{
			con.erase(it);
			printf("删除成功\n");
			flag = true;
			break;
		}
	}

	if (flag==false)
	{
		printf("要删除的人不存在\n");
		return;
	}
}

list<ContactNode>::iterator Contact::FindByName(list<ContactNode>::iterator begin,
								 list<ContactNode>::iterator end,string name)
{
	auto it = begin;
	for (; it != end;it++)
	{
		if ((*it).name == name)
		{
			return it;
		}
	}
	return it;
}

void Contact::SearchContact()
{
	string name;
	printf("请输入要查找人的名字:>");
	cin >> name;
	//查找
	auto delnodeiter = FindByName(this->con.begin(), this->con.end(),name);
	if (delnodeiter == this->con.end())
	{
		printf("要查找的人不存在\n");
		return;
	}
	//打印
	printf("%-10s %-4s %-5s %-12s\n", "姓名", "年龄", "性别", "电话");
	//打印数据
	printf("%-10s %-4d %-5s %-12s\n",
			delnodeiter->name.c_str(),
			delnodeiter->age,
			delnodeiter->sex.c_str(),
			delnodeiter->tele.c_str());
}

void Contact::ModifyContact()
{
	string name;
	printf("请输入要查找人的名字:>");
	cin >> name;
	//查找
	auto delnodeiter = FindByName(this->con.begin(), this->con.end(), name);
	if (delnodeiter == this->con.end())
	{
		printf("要查找的人不存在\n");
		return;
	}
	//修改
	printf("请输入名字:>");
	scanf("%s", (delnodeiter->name.c_str()));
	printf("请输入年龄:>");
	scanf("%d", &(delnodeiter->age));
	printf("请输入性别:>");
	scanf("%s", (delnodeiter->sex.c_str()));
	printf("请输入电话:>");
	scanf("%s", (delnodeiter->tele.c_str()));

	printf("修改成功\n");
}


////按照名字来排序
//int cmp_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
//}
//
//void SortContact(Contact* pc)
//{
//	qsort(pc->data, pc->sz, sizeof(PeoInfo), cmp_by_name);
//	printf("排序成功\n");
//}

//void SaveContact(Contact* pc)
//{
//	FILE* pf = fopen("contact.dat", "wb");
//	if (pf == NULL)
//	{
//		perror("SaveContact::fopen");
//		return;
//	}
//	//写数据
//	int i = 0;
//	for (i = 0; i < pc->sz; i++)
//	{
//		fwrite(pc->data + i, sizeof(struct PeoInfo), 1, pf);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	printf("保存成功...\n");
//}