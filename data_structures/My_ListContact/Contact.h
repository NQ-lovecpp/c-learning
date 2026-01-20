#pragma once
#include <iostream>
#include <string>
#include <list>

struct ContactNode
{
	std::string name;
	int age;
	std::string sex;
	std::string tele;
};

class Contact
{
public:

	//初始化通讯录 构造函数
	Contact();

	//销毁通讯
	~Contact();

	//增加指定联系人
	void AddContact();

	//显示联系人信息
	void ShowContact();

	//找到删除位置
	std::list<ContactNode>::iterator FindByName(std::list<ContactNode>::iterator begin,
							std::list<ContactNode>::iterator end, std::string name);
	//删除指定联系人
	void DelContact();

	//查找指定联系人
	void SearchContact();

	//修改通讯录
	void ModifyContact();

	////排序通讯录元素
	//void SortContact();

	////保存数据到文件
	//void SaveContact();
private:
	std::list<ContactNode> con;
};
