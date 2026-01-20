//题目3：学生档案管理系统
//该系统实现了对学生信息的存储和管理。学生信息包括学号、姓名、性别和生日等信息。系统可以对学生信息进行查询、添加、删除和备份。系统进入时还包括一个密码验证的过程，也可以对密码进行管理。请以C++语言为工具，运用面向对象方法学，开发一个学生档案管理系统。系统必须至少提供以下几种功能：
//（1）	提供简单的操作菜单；
//（2）	能完成对学会信息的基本操作，包括输入、输出、修改、追加等操作；
//（3）	使学生的某一项（一般为学号）取值唯一，添加学生信息时能够及时给出提示；
//（4）	至少能按一种方式对学生信息进行查询和删除；
//（5）	实现密码检测和管理；
//（6）	实现学生信息的备份。

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>

struct ContactNode
{
	std::string name;
	int age = 0;
	std::string sex;
	std::string tele;
};

class Contact
{
public:

	// 默认构造函数 用于初始化通讯录
	Contact();

	// 销毁通讯录
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

private:
	std::list<ContactNode> con;
};



////排序通讯录元素
//void SortContact();
