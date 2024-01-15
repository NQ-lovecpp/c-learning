#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
const int MAX = 100;

// 登陆系统
struct DataType // 数据结构体，有账号和密码两个部分
{
	char *name;
	char *password;
};
class keynode
{
	DataType data;
	keynode *next;

public:
	keynode() // 节点默认构造函数；
	{
		data.password = (char *)malloc(sizeof(char) * 8);
		data.name = (char *)malloc(sizeof(char) * 12);
		next = NULL;
	}
	friend class keylist;
};
class keylist
{
	keynode *head; // 头节点不储存数据，仅作为链表接口
	int length;

public:
	keylist()
	{

		head = new keynode;
		length = 0;
	}
	void createlist(const char *);
	void listdisplay();
	string listcheck(string &s);		// 登录函数，如果成功就返回1不成功返回0
	int FileRefresh(const char *);		// 更新文档的函数
	int ListPasswordModify();			// 修改密码
	int ListPasswordModify(string num); // 学生系统中的密码修改
	int ListDelete(string n);			// 删除表中的账号
	int ListAdd(string n);				// 增加账号
};
void keylist::createlist(const char *filename) // 创建密码链表
{
	fstream txt;
	txt.open(filename);
	string n;
	char *_name = (char *)malloc(sizeof(char) * 13);
	char *_password = (char *)malloc(sizeof(char) * 9);
	keynode *p = head;

	while (getline(txt, n))
	{
		keynode *newnode = new keynode;
		int i = 0, j = 0;
		while (n[i] != '#')
		{
			_name[i] = n[i];
			i++;
		}

		i++;
		i = 0;
		getline(txt, n); // 移到下一行读取密码
		while (i < strlen(n.c_str()) - 1)
		{
			_password[j] = n[i];
			i++;
			j++;
		}

		strcpy_s(newnode->data.name, strlen(_name) + 1, _name);
		strcpy_s(newnode->data.password, strlen(_password) + 1, _password);

		// strcpy(newnode->data.name, _name);
		// strcpy(newnode->data.password, _password);

		p->next = newnode;
		p = p->next;
		length++;
	} // while
	txt.close();
}
void keylist::listdisplay() // 展示密码
{
	if (!head->next)
	{
		cout << "List is empty" << endl;
		return;
	}
	keynode *p = head->next;
	while (p != NULL)
	{
		cout << "账号：";
		for (int i = 0; i < 12; i++)
		{
			cout << p->data.name[i];
		}
		cout << " 密码：";
		for (int i = 0; i < 8; i++)
		{
			cout << p->data.password[i];
		}
		cout << endl;
		p = p->next;
	}
}
string keylist::listcheck(string &s) // 登录系统，如果登录成功就返回1，不成功就返回0
{
	string s1, s2;
	cout << "====账号:";
	cin >> s1;
	cout << endl
		 << "====密码:";
	cin >> s2;
	keynode *target = head->next;
	int f1 = 1, f2 = 1;

	while (target)
	{
		f1 = 1;
		for (int i = 0; i < 12; i++) // 依次识别这一条账号的每个字符
		{
			if (s1[i] != target->data.name[i])
			{
				f1 = 0;
				break;
			}
		}
		if (f1 == 0) // 如果标识符-==0说明这条账号不匹配，寻找下一个账号
			target = target->next;
		else // 如果当前账号与输入账号匹配就停止循环
			break;
	}
	if (!target) // 如果遍历完指向空说明没有找到账号
	{
		cout << endl
			 << "====请输入正确的账号！" << endl;
		return "Error";
	}
	else
	{
		for (int i = 0; i < 8; i++) // 识别这一条的密码和输入的密码是否相同
		{
			if (s2[i] != target->data.password[i])
			{
				f2 = 0;
				break;
			}
		}
		if (f2)
		{
			cout << endl
				 << "====账号密码正确" << endl;
			return s1;
		}
		else
		{
			cout << endl
				 << "====密码错误！" << endl;
			return "Error";
		}
	}
}
int keylist::FileRefresh(const char *filename)
{
	ofstream txt(filename);
	keynode *p = head->next;
	int i;
	while (p)
	{
		for (i = 0; i < 12; i++)
			txt << p->data.name[i];
		txt << '#' << endl;
		for (i = 0; i < 8; i++)
			txt << p->data.password[i];
		txt << '#' << endl;
		p = p->next;
	}
	cout << "账号文件" << filename << "更新成功\n";
	return 1;
}
int keylist::ListPasswordModify() // 修改密码的函数，会将修改账户的下标存在修改表的第一行
{
	string target; // 目标账号
	string n;	   // 旧密码
	string np;	   // 新的密码
	cout << "====目标账号：";
	cin >> target;
	cout << endl;
	cout << "====原密码：";
	cin >> n;
	cout << endl;
	keynode *p = head->next;

	while (p) // 找到需要修改的账号;
	{
		int f = 1;
		for (int i = 0; i < 12; i++)
		{
			if (target[i] != p->data.name[i])
			{
				f = 0;
				break;
			}
		}
		if (f == 0)
			p = p->next;
		else
		{
			break;
		}
	}
	if (!p)
	{
		cout << "====账号输入错误！" << endl;
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		if (p->data.password[i] != n[i])
		{
			cout << "====密码输入错误！" << endl;
			return 0;
		}
	}
	cout << "====新密码：";
	cin >> np;
	cout << endl;
	while (np == n)
	{
		cout << "====新密码不能与旧密码一样！" << endl;
		cin >> np; // 修：输入少于8个字符有问题
		cout << endl;
	}
	for (int i = 0; i < 8; i++)
	{
		p->data.password[i] = np[i];
	}
	cout << "新密码修改成功\n";
	return 1;
}
int keylist::ListPasswordModify(string target)
{
	string n;  // 旧密码
	string np; // 新的密码
	cout << endl;
	cout << "====原密码：";
	cin >> n;
	cout << endl;
	keynode *p = head->next;

	while (p) // 找到需要修改的账号;
	{
		int f = 1;
		for (int i = 0; i < 12; i++)
		{
			if (target[i] != p->data.name[i])
			{
				f = 0;
				break;
			}
		}
		if (f == 0)
			p = p->next;
		else
		{
			break;
		}
	}
	if (!p)
	{
		cout << "无此账号\n";
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		if (p->data.password[i] != n[i])
		{
			cout << "====密码输入错误！" << endl;
			return 0;
		}
	}
	cout << "====新密码：";
	cin >> np;
	cout << endl;
	while (np == n)
	{
		cout << "====新密码不能与旧密码一样！" << endl;
		cin >> np;
		cout << endl;
	}

	// 待修改（或限制输入为8位）（或将p->data.password的内容先清空）
	for (int i = 0; i < 8; i++)
	{
		p->data.password[i] = np[i];
	}
	cout << "新密码修改成功\n";
	return 1;
}
int keylist::ListDelete(string n)
{
	keynode *p = head->next;
	keynode *pre = head;
	int f;
	while (p)
	{
		f = 1;
		for (int i = 0; i < 12; i++)
		{
			if (p->data.name[i] != n[i])
			{
				f = 0;
				break;
			}
		}
		if (f == 1)
		{
			pre->next = p->next;
			free(p);
			break;
		}
		else
		{
			pre = pre->next;
			p = p->next;
		}
	}
	if (!pre->next && f != 1)
	{
		cout << "====账号不存在！" << endl;
		return 0;
	}
	return 1;
	cout << "该人员账号信息删除成功\n";
}
int keylist::ListAdd(string n) // 添加账号默认密码是12345678
{
	keynode *p = head;
	while (p->next)
	{
		int i = 0;
		for (i; i < 12; i++)
		{
			if (p->data.name[i] != n[i])
				break;
		}
		if (i > 12)
		{
			cout << "====账号已存在！" << endl;
			return 0;
		}
		p = p->next;
	}
	keynode *newnode = new keynode;
	for (int i = 0; i < 12; i++)
		newnode->data.name[i] = n[i];
	string temp = "12345678";
	for (int i = 0; i < 8; i++)
		newnode->data.password[i] = temp[i];
	p->next = newnode;
	return 1;
}

class person
{
public:
	string num;
	string name;
	string sex;
	string course;
};

// 管理者学生信息系统
class Student : virtual public person
{
public:
	string classes;
	string situation;
	void Input(string n)
	{
		// 此函数调用前都会先输入编号，查看是否编号重复，故无需再次输入编号
		num = n;
		cout << "输入学生姓名 : ";
		cin >> name;
		cout << "输入学生性别 : ";
		cin >> sex;
		cout << "输入学生专业 : ";
		cin >> course;
		cout << "输入学生班级 : ";
		cin >> classes;
	}
	void Output()
	{
		cout << "编号: " << num << " "
			 << "姓名: " << name << " "
			 << "性别: " << sex << " "
			 << "专业: " << course << " "
			 << "班级: " << classes << endl;
	}
};
Student Stu[MAX];
static int Stumax;
class StuManagement // 管理学生的类
{
public:
	string Add();
	int Search();
	int Search(string n);
	void Revise();
	void Save();
	void Read();
	string Delete();
	void Showout();
};
void StuManagement::Save()
{
	ofstream it("Stumax.txt");
	for (int i = 0; i < Stumax; i++)
	{
		it << Stu[i].num << "\t" << Stu[i].name << "\t" << Stu[i].sex
		   << "\t" << Stu[i].course << "\t" << Stu[i].classes << endl;
	}
	it.close();
	cout << "学生信息文件Stumax更新成功\n";
}
void StuManagement::Read()
{
	string num;
	string name;
	string sex;
	string course;
	string classes;
	ifstream it("Stumax.txt");
	int i = 0;
	while (!it.eof())
	{
		it >> num >> name >> sex >> course >> classes;
		Stu[i].num = num;
		Stu[i].name = name;
		Stu[i].sex = sex;
		Stu[i].course = course;
		Stu[i].classes = classes;
		++i;
	}
	Stumax = i - 1;

	it.close();
}
void StuManagement::Showout()
{
	if (Stumax == 0)
	{
		cout << "记录为空" << endl;
	}
	for (int i = 0; i < Stumax; i++)
		Stu[i].Output();
}
string StuManagement::Add()
{
	Student t;
	int i;
	string num;
	if (Stumax == MAX)
	{
		cout << "学生人数已满，无法添加" << endl;
		return "ERROR";
	}
	// 修
	cout << "请输入要添加的学生编号 : ";
	cin >> num;
	for (i = 0; i < Stumax; i++)
	{
		if (num == Stu[i].num)
		{
			cout << "学生已有该编号" << endl;
			return "ERROR";
		}
	}
	t.Input(num);
	Stu[Stumax] = t;
	Stumax++;
	cout << "该学生信息添加成功！" << endl;
	Save();
	return num;
}
int StuManagement::Search(string num)
{
	int j;
	char name[20];
	for (j = 0; j < Stumax; j++)
	{
		if (num == Stu[j].num)
			break;
	}
	if (j == Stumax)
	{
		cout << "没有此学生！" << endl;
	}
	else
	{
		Stu[j].Output();
	}
	return 1;
}
int StuManagement::Search()
{
	int j, way;
	string num;
	char name[20];
	cout << "选择查找学生方式，按编号查找(0)|按姓名查找(1):";
	cin >> way;
	switch (way)
	{
	case 0:
		cout << "请输入学生编号:";
		cin >> num;
		for (j = 0; j < Stumax; j++)
		{
			if (num == Stu[j].num)
				break;
		}
		if (j == Stumax)
		{
			cout << "没有此学生！" << endl;
		}
		else
		{
			Stu[j].Output();
		}
		break;
	case 1:
		cout << "请输入姓名:";
		cin >> name;
		for (j = 0; j < Stumax; j++)
		{
			if (Stu[j].name == name)
				break;
		}
		if (j == Stumax)
			cout << "没有此学生！" << endl;
		else
			Stu[j].Output();
		break;
	}
	return 1;
}
void StuManagement::Revise()
{
	Student t1;
	int j;
	string num;
	cout << "请输入要修改信息的学生编号：";
	cin >> num;
	for (j = 0; j < Stumax; j++)
	{
		if (num == Stu[j].num)
			break;
	}
	if (j == Stumax)
	{
		cout << "没有此学生！" << endl;
		return;
	}
	cout << "正在修改编号为" << num << "学生的信息" << endl;
	t1.Input(num);
	Stu[j] = t1;
	Save();
	cout << "该学生信息修改成功！" << endl;
}
string StuManagement::Delete()
{
	int j;
	string num;
	cout << "请输入要删除的学生的编号：";
	cin >> num;
	for (j = 0; j < Stumax; j++)
	{
		if (num == Stu[j].num)
			break;
	}
	if (j == Stumax)
	{
		cout << "没有此学生！" << endl;
		return "ERROR";
	};
	for (j; j < Stumax; j++)
	{
		Stu[j] = Stu[j + 1];
	}
	Stumax--;
	cout << "该学生信息删除成功！" << endl;
	Save();
	return num;
}

// 学生操作菜单
void Stu_mune(StuManagement S, keylist Student, string num)
{
	int choice;
	do
	{
		cout << endl;
		cout << endl;
		cout << "学生管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "  1.查询信息    ";
		cout << "  2.修改密码    ";
		cout << "  0.保存并退出 | " << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择：";
		cin >> choice;
		switch (choice)
		{
		case 1:
			S.Search(num);
			break;
		case 2:
			if (Student.ListPasswordModify(num) == 1)
				Student.FileRefresh("StudentPassword.txt");
			break;
		case 0:
			break;
		default:
			cout << "\n 操作数错误，请重新输入：" << endl;
			break;
		}

		char ch;
		if (choice != 0)
		{
			// 界面停留查看信息
			cout << "\n\n输入回车以继续: ";
			rewind(stdin);
			ch = getchar();
			rewind(stdin);
		}
		else
		{
			break;
		}

	} while (1);
}

// 管理者信息系统
class Administrator : virtual public person
{
public:
	void Input(string n)
	{
		// 此函数调用前都会先输入编号，查看是否编号重复，故无需再次输入编号
		num = n;
		cout << "输入教师姓名 : ";
		cin >> name;
		cout << "输入教师性别: ";
		cin >> sex;
		cout << "输入教师科目: ";
		cin >> course;
	}
	void Output()
	{
		cout << "编号: " << num << " "
			 << "姓名: " << name << " "
			 << "性别: " << sex << " "
			 << "教学科目: " << course << endl;
	}
};
Administrator Adm[MAX];
static int Admmax;
class AdmManagement
{
public:
	string Add();
	int Search();
	void Revise();
	string Delete();
	void Save();
	void Read();
	void show();
};
void AdmManagement::Save()
{
	ofstream it("Admmax.txt");
	for (int i = 0; i < Admmax; i++)
	{
		it << Adm[i].num << "\t" << Adm[i].name << "\t" << Adm[i].sex
		   << "\t" << Adm[i].course << endl;
	}
	it.close();
	cout << "教师信息文件Admmax更新成功\n";
}
void AdmManagement::Read()
{
	string num;
	string name;
	string sex;
	string course;
	ifstream it("Admmax.txt");
	int i = 0;
	while (!it.eof())
	{
		it >> num >> name >> sex >> course;
		Adm[i].num = num;
		Adm[i].name = name;
		Adm[i].sex = sex;
		Adm[i].course = course;
		++i;
	}
	Admmax = i - 1;

	it.close();
}
void AdmManagement::show()
{
	if (Admmax == 0)
	{
		cout << "记录为空" << endl;
	}
	for (int i = 0; i < Admmax; i++)
	{
		Adm[i].Output();
	}
}
string AdmManagement::Add()
{
	Administrator t;
	int i;
	string num;
	if (Admmax == MAX)
	{
		cout << "教师人数已满，无法添加" << endl;
		return "ERROR";
	}
	cout << "请输入要添加的教师编号 : ";
	cin >> num;
	for (i = 0; i < Admmax; i++)
	{
		if (num == Adm[i].num)
		{
			cout << "教师已有该编号" << endl;
			return "ERROR";
		}
	}
	t.Input(num);
	Adm[Admmax] = t;
	Admmax++;
	cout << "该教师信息添加成功！" << endl;
	Save();
	return num;
}
int AdmManagement::Search()
{
	int j, way;
	string num;
	char name[20];
	cout << "选择查找教师方式，按编号查找(0)|按姓名查找(1):";
	cin >> way;
	switch (way)
	{
	case 0:
		cout << "请输入教师编号:";
		cin >> num;
		for (j = 0; j < Admmax; j++)
		{
			if (num == Adm[j].num)
				break;
		}
		if (j == Admmax)
			cout << "没有此人！" << endl;
		else
			Adm[j].Output();
		break;
	case 1:
		cout << "请输入姓名:";
		cin >> name;
		for (j = 0; j < Admmax; j++)
		{
			if (Adm[j].name == name)
				break;
		}
		if (j == Admmax)
			cout << "没有此教师！" << endl;
		else
			Adm[j].Output();
		break;
	}
	return 1;
}
void AdmManagement::Revise()
{
	Administrator t1;
	int j;
	string num;
	cout << "请输入要修改信息的教师编号：";
	cin >> num;
	for (j = 0; j < Admmax; j++)
	{
		if (num == Adm[j].num)
			break;
	}
	if (j == Admmax)
	{
		cout << "没有此教师！" << endl;
		return;
	}
	cout << "正在修改编号为" << num << "教师的信息" << endl;
	t1.Input(num);
	Adm[j] = t1;
	Save();
	cout << "该教师信息修改成功！" << endl;
}
string AdmManagement::Delete()
{
	int j;
	string num;
	cout << "请输入要删除的教师的编号：";
	cin >> num;
	for (j = 0; j < Admmax; j++)
	{
		if (num == Adm[j].num)
			break;
	}
	if (j == Admmax)
	{
		cout << "没有此教师！" << endl;
		return "ERROR";
	};
	for (j; j < Admmax; j++)
	{
		Adm[j] = Adm[j + 1];
	}
	Admmax--;
	cout << "该教师信息删除成功！" << endl;
	Save();
	return num;
}

// 备份/文件操作功能类
class Backup
{
public:
	void Backup_To_Ano_File(keylist Teacher, keylist Student);
	void Recover_To_Ex_File(StuManagement Stume, AdmManagement Admme, keylist Teacher, keylist Student);
	void recordTime();
	int checkBackupFile();
	void readTime();
	void sortStu(StuManagement Stume);
};

// 管理者菜单界面
void Adm_mune(AdmManagement A, StuManagement S, keylist Teacher, keylist Student)
{
	int choice;
	char ch;
	string num;
	Backup B;
	do
	{
		cout << endl;
		cout << endl;
		cout << "教师管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.录入教师  ";
		cout << "  2.查询教师    ";
		cout << "  3.修改教师信息    ";
		cout << "  4.删除教师    ";
		cout << "  5.读取教师信息    " << endl;
		cout << "==========================================================================================" << endl;
		cout << "学生管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 6.录入学生  ";
		cout << "  7.查询学生    ";
		cout << "  8.修改学生信息    ";
		cout << "  9.删除学生    ";
		cout << "  10.读取学生信息    " << endl;
		cout << "==========================================================================================" << endl;
		cout << "账号管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 11.修改教师密码    ";
		cout << "  12.修改学生密码    ";
		cout << "  13.展示教师账号密码    ";
		cout << "  14.展示学生账号密码    " << endl;
		cout << "==========================================================================================" << endl;
		cout << "文件管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| -1.备份文件   ";
		cout << "-2.恢复上一次备份文件信息	";
		cout << "-3.学生信息按学号排序并保存	" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 0.保存并退出 | " << endl;
		cout << "请选择：";
		cin >> choice;
		switch (choice)
		{
		case 1:
			num = A.Add();
			if (num == "ERROR")
				break;
			Teacher.ListAdd(num);
			cout << "此教师账号添加成功，默认密码为12345678\n";
			Teacher.FileRefresh("TeacherPassword.txt");
			break;
		case 2:
			A.Search();
			break;
		case 3:
			A.Revise();
			break;
		case 4:
			num = A.Delete();
			if (num == "ERROR")
				break;
			Teacher.ListDelete(num);
			Teacher.FileRefresh("TeacherPassword.txt");
			break;
		case 5:
			A.show();
			break;
		case 6:
			num = S.Add();
			if (num == "ERROR")
				break;
			Student.ListAdd(num);
			cout << "此学生账号添加成功，默认密码为12345678\n";
			Student.FileRefresh("StudentPassword.txt");
			break;
		case 7:
			S.Search();
			break;
		case 8:
			S.Revise();
			break;
		case 9:
			num = S.Delete();
			if (num == "ERROR")
				break;
			Student.ListDelete(num);
			Student.FileRefresh("StudentPassword.txt");
			break;
		case 10:
			S.Showout();
			break;
		case 11:
			if (Teacher.ListPasswordModify() == 1)
				Teacher.FileRefresh("TeacherPassword.txt");
			break;
		case 12:
			if (Student.ListPasswordModify() == 1)
				Student.FileRefresh("StudentPassword.txt");
			break;
		case 13:
			Teacher.listdisplay();
			break;
		case 14:
			Student.listdisplay();
			break;
		case 0:
			break;
		case -1:
			B.Backup_To_Ano_File(Teacher, Student);
			B.recordTime();
			break;
		case -2:
			if (B.checkBackupFile())
			{
				B.readTime();
				B.Recover_To_Ex_File(S, A, Teacher, Student);
			}
			else
			{
				cout << "*******恢复失败！！！" << endl;
				cout << "错误原因：未在此设备备份过文件!" << endl;
			}
			break;
		case -3:
			B.sortStu(S);
			break;
		default:
			cout << "\n 操作数错误，请重新输入：" << endl;
			break;
		}

		if (choice != 0)
		{
			// 界面停留查看信息
			cout << "\n\n输入回车以继续: ";
			rewind(stdin);
			ch = getchar();
			rewind(stdin);
		}
		else
		{
			break;
		}

	} while (1);
}

// 选择登入界面（教师or学生）
int choose(int a)
{
	while (1)
	{
		cout << "输入1进入教师登入界面  ||  输入2进入学生登入界面\n";
		cin >> a;
		if (a == 1)
		{
			cout << "教师登入界面\n";
			return a;
		}
		else if (a == 2)
		{
			cout << "学生登入界面\n";
			return a;
		}
		else
			cout << "重新输入,";
	}
}

// 进入登入界面
string login(int &a, keylist Teacher, keylist Student)
{
	a = choose(a);
	while (1)
		if (a == 1)
		{
			Teacher.createlist("TeacherPassword.txt");
			string name;
			name = Teacher.listcheck(name);
			if (name != "Error")
			{
				cout << "====教师登入成功\n";
				Student.createlist("StudentPassword.txt");
				return name;
			}
		}
		else
		{
			Student.createlist("StudentPassword.txt");
			string name;
			name = Student.listcheck(name);
			if (name != "Error")
			{
				cout << "====学生登入成功\n";
				return name;
			}
		}
}
void ChooseOperation(int a, string account, StuManagement Stume, AdmManagement Admme, keylist Teacher, keylist Student)
{
	if (a == 1)
	{
		Stume.Read();
		Admme.Read();
		Adm_mune(Admme, Stume, Teacher, Student); // 教师能够对教师和学生的信息进行更改
	}
	else
	{
		Stume.Read();
		Stu_mune(Stume, Student, account);
	}
}

// Backup成员函数定义
void Backup::Backup_To_Ano_File(keylist Teacher, keylist Student)
{
	ofstream Tit("AdmmaxBackup.txt");
	for (int i = 0; i < Admmax; i++)
	{
		Tit << Adm[i].num << "\t" << Adm[i].name << "\t" << Adm[i].sex
			<< "\t" << Adm[i].course << endl;
	}
	Tit.close();
	cout << "教师信息文件AdmmaxBackup.txt更新成功\n";
	ofstream Sit("StumaxBackup.txt");
	for (int i = 0; i < Stumax; i++)
	{
		Sit << Stu[i].num << "\t" << Stu[i].name << "\t" << Stu[i].sex
			<< "\t" << Stu[i].course << "\t" << Stu[i].classes << endl;
	}
	Sit.close();
	cout << "学生信息文件StumaxBackup.txt更新成功\n";
	Teacher.FileRefresh("TeacherPasswordBackup.txt");
	Student.FileRefresh("StudentPasswordBackup.txt");
}
void Backup::Recover_To_Ex_File(StuManagement Stume, AdmManagement Admme, keylist Teacher, keylist Student)
{
	Teacher.createlist("TeacherPasswordBackup.txt");
	Teacher.FileRefresh("TeacherPassword.txt");
	Student.createlist("StudentPasswordBackup.txt");
	Student.FileRefresh("StudentPassword.txt");
	//
	string num, name, sex, course, classes;
	ifstream it("AdmmaxBackup.txt");
	int i = 0;
	while (!it.eof())
	{
		it >> num >> name >> sex >> course;
		Adm[i].num = num;
		Adm[i].name = name;
		Adm[i].sex = sex;
		Adm[i].course = course;
		++i;
	}
	Admmax = i - 1;
	it.close();
	Admme.Save();

	//
	ifstream t("StumaxBackup.txt");
	i = 0;
	while (!t.eof())
	{
		t >> num >> name >> sex >> course >> classes;
		Stu[i].num = num;
		Stu[i].name = name;
		Stu[i].sex = sex;
		Stu[i].course = course;
		Stu[i].classes = classes;
		++i;
	}
	Stumax = i - 1;
	it.close();
	Stume.Save();
}
int Backup::checkBackupFile()
{
	ifstream it("recordTime.txt");
	if (!it)
	{
		return 0;
	}
	char ch;
	it >> ch;
	it >> ch;
	if (!ch || ch < 0)
	{
		return 0;
	}
	return 1;
}
void Backup::recordTime()
{
	ofstream ot("recordTime.txt");
	ot << __DATE__ << "\t" << __TIME__;
	ot.close();
}
void Backup::readTime()
{
	string date1, date2, time1, time2;
	ifstream it("recordTime.txt");
	it >> date1 >> date2 >> time1 >> time2;
	it.close();
	cout << "备份版本号: " << date1 << " " << date2 << " " << time1 << " " << time2 << endl;
}

// 学生信息排序并保存
void Backup::sortStu(StuManagement Stume)
{
	int i = Stumax - 1, lastExchangeIndex, j;
	Student t;
	while (i > 0)
	{
		lastExchangeIndex = 0;
		for (j = 0; j < i; j++)
		{
			if (Stu[j + 1].num.compare(Stu[j].num) < 0)
			{
				t = Stu[j]; // 浅拷贝
				Stu[j] = Stu[j + 1];
				Stu[j + 1] = t;
				lastExchangeIndex = j; // 记下进行交换的记录位置
			}
		}
		i = lastExchangeIndex;
	}
	Stume.Save();
	cout << "操作成功！" << endl;
}

// 主函数
int main()
{
	int a = 0;									// a判断是教师还是学生，1是老师，2是学生
	keylist AccTeacher, AccStudent;				// 教师和学生的账号密码
	string account;								// 用来后续返回账号
	StuManagement Stume;						// 学生的信息
	AdmManagement Admme;						// 教师的信息
	account = login(a, AccTeacher, AccStudent); // 返回账号
	ChooseOperation(a, account, Stume, Admme, AccTeacher, AccStudent);

	return 0;
}