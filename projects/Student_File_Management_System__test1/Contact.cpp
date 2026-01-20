#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

Contact::Contact()
{
	std::ifstream inFile("contacts.txt");  // 打开一个名为 "contacts.txt" 的文件用于读取
	if (inFile.is_open())  // 检查文件是否成功打开
	{
		ContactNode temp;
		while (inFile >> temp.name >> temp.age >> temp.sex >> temp.tele)  // 从文件中读取
		{
			con.push_back(temp);  // 添加到链表
		}
		inFile.close();  // 关闭文件
	}
	else
	{
		std::cout << "无文件或无法打开文件，将创建一个空的通讯录。" << std::endl;
	}
}

Contact::~Contact()
{
	std::ofstream outFile("contacts.txt");  // 打开一个名为 "contacts.txt" 的文件用于写入
	if (outFile.is_open())  // 检查文件是否成功打开
	{
		for (const auto& contact : con)  // 遍历链表
		{
			// 将链表中的每一个元素写入到文件
			outFile << contact.name << " " << contact.age << " " << contact.sex << " " << contact.tele << std::endl;
		}
		outFile.close();  // 关闭文件
	}
	else
	{
		std::cout << "无法打开文件以保存通讯录。" << std::endl;
	}
}

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

//void Contact::ShowContact()
//{
//	//姓名      年龄      性别     电话 
//	//zhangsan 20        男      123456 
//	
//	//打印标题
//	printf("\n---------------------------------------------------\n");
//	printf("| %-4s | %-10s | %-4s | %-5s | %-12s |\n", "序号", "姓名", "年龄", "性别", "电话");
//
//
//	//打印数据
//	int i = 0;
//	for (auto& node:con)
//	{
//		printf("| %-4d | %-10s | %-4d | %-5s | %-12s |\n", i+1, node.name.c_str(), node.age, node.sex.c_str(), node.tele.c_str());
//		i++;
//	}
//	printf("---------------------------------------------------\n\n");
//}


void Contact::ShowContact()
{
	// 打印彩色表头
	printf("\n\033[31m\033[1m---------------------------------------------------\n");
	printf("| %-4s | \033[32m\033[1m%-10s\033[0m\033[31m\033[1m | \033[33m\033[1m%-4s\033[0m\033[31m\033[1m | \033[34m\033[1m%-5s\033[0m\033[31m\033[1m | \033[35m\033[1m%-12s\033[0m\033[31m\033[1m |\n",
		"序号", "姓名", "年龄", "性别", "电话");
	printf("\033[31m\033[1m---------------------------------------------------\n");
	// 打印数据
	int i = 0;
	for (auto& node : con)
	{
		// 恢复默认文本颜色
		printf("\033[0m");

		printf("| %-4d | %-10s | %-4d | %-5s | %-12s |\n", i + 1, node.name.c_str(), node.age, node.sex.c_str(), node.tele.c_str());
		i++;
	}

	// 打印彩色边框
	printf("\033[31m\033[1m---------------------------------------------------\033[0m\n\n");
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
	list<ContactNode>::iterator it = begin;
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
