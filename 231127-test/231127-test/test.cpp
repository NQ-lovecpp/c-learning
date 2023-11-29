//#include <iostream>
//using namespace std;
//
//class CData
//{
//public:
//    static void Add(int a)
//    {
//        if (pCur >= data + 20)
//            cout << "内存空间不足，无法添加！" << endl;
//        else
//        {
//            *pCur = a;
//            pCur++;
//        }
//    }
//    static void Print(void);
//    static void Sort(void);
//    static void Del(int d);
//private:
//    static int data[20];
//    static int* pCur;
//};
//
//int CData::data[20];
//int* CData::pCur = data;
//
//void CData::Print(void)
//{
//    for (int i = 0; i < (pCur - data); i++)
//        cout << data[i] << ",";
//    cout << endl;
//}
//
//void CData::Sort(void)
//{
//    int n = pCur - data;
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j < n; j++)
//        {
//            if (data[i] > data[j])
//            {
//                int temp = data[i];
//                data[i] = data[j];
//                data[j] = temp;
//            }
//        }
//    }
//}
//
//void CData::Del(int d)
//{
//    int* p = data;
//    while (p < pCur)
//    {
//        if (*p == d)
//        {
//            // 如果当前元素等于指定值，将其删除
//            for (int* q = p; q < pCur - 1; q++)
//                *q = *(q + 1);
//            pCur--;
//        }
//        else
//        {
//            p++;
//        }
//    }
//}
//
//int main()
//{
//    CData::Add(40);
//    CData::Add(20);
//    CData::Add(-50);
//    CData::Add(7);
//    CData::Add(13);
//    CData::Add(7);
//    CData::Print();
//    CData::Sort();
//    CData::Print();
//    cout << "删除元素7以后:" << endl;
//    CData::Del(7);
//    CData::Print();
//    return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//class CRoot 
//{
//public:
//	int small;
//	CRoot(int n = 2) 
//	{ 
//		small = n; 
//	}
//	void showsmall() 
//	{
//		cout << "small=" << small << endl;
//	}
//};
//class CDer1 :public CRoot
//{
//public:
//	CDer1(int m) 
//		:CRoot(m) 
//	{}
//};
//class CDer2 :public CRoot 
//{
//public:
//	int small;
//	CDer2(int n = 0) 
//	{ 
//		small = n; 
//	}
//};
//
//int main() 
//{
//	CRoot A;
//	CDer1 B(3);
//	CDer2 C;
//	A.showsmall();
//	B.showsmall();
//	C.showsmall();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//// 基类
//class CPerson 
//{
//public:
//    // 数据成员
//    string name;
//    int id;
//    char gender;
//
//    // 输入函数
//    void input() 
//    {
//        cout << "Enter name: ";
//        cin >> name;
//        cout << "Enter ID: ";
//        cin >> id;
//        cout << "Enter gender (M/F): ";
//        cin >> gender;
//    }
//
//    // 输出函数
//    void output() 
//    {
//        cout << "Name: " << name << endl;
//        cout << "ID: " << id << endl;
//        cout << "Gender: " << gender << endl;
//    }
//};
//
//// 学生类，继承自CPerson
//class CStudent : public CPerson 
//{
//public:
//    // 学生特有的数据成员
//    float grade;
//
//    // 输入函数，重载基类的输入函数
//    void input() 
//    {
//        CPerson::input(); // 调用基类的输入函数获取共有信息
//        cout << "Enter grade: ";
//        cin >> grade;
//    }
//
//    // 输出函数，重载基类的输出函数
//    void output() 
//    {
//        CPerson::output(); // 调用基类的输出函数显示共有信息
//        cout << "Grade: " << grade << endl;
//    }
//};
//
//// 教师类，继承自CPerson
//class CTeacher : public CPerson 
//{
//public:
//    // 教师特有的数据成员
//    int teachingYears;
//
//    // 输入函数，重载基类的输入函数
//    void input() 
//    {
//        CPerson::input(); // 调用基类的输入函数获取共有信息
//        cout << "Enter teaching years: ";
//        cin >> teachingYears;
//    }
//
//    // 输出函数，重载基类的输出函数
//    void output() 
//    {
//        CPerson::output(); // 调用基类的输出函数显示共有信息
//        cout << "Teaching Years: " << teachingYears << endl;
//    }
//};
//
//int main() 
//{
//    // 示例使用
//    CStudent student;
//    CTeacher teacher;
//
//    cout << "Enter student information:" << endl;
//    student.input();
//    cout << "\nStudent Information:" << endl;
//    student.output();
//
//    cout << "\nEnter teacher information:" << endl;
//    teacher.input();
//    cout << "\nTeacher Information:" << endl;
//    teacher.output();
//
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

// 定义基类 Person
class Person 
{
public:
    string name;
    int age;
    char gender;
    string address;
    string phone;

    // 构造函数
    Person(string n, int a, char g, string addr, string ph) 
        : name(n), age(a), gender(g), address(addr), phone(ph) 
    {}

    // 成员函数显示个人信息
    void display() 
    {
        cout << "姓名：" << name << endl;
        cout << "年龄：" << age << endl;
        cout << "性别：" << gender << endl;
        cout << "地址：" << address << endl;
        cout << "电话：" << phone << endl;
    }
};

// 定义教师类 Teacher，继承自 Person
class Teacher : public Person 
{
public:
    string title;

    // 构造函数
    Teacher(string n, int a, char g, string addr, string ph, string t) 
        : Person(n, a, g, addr, ph), title(t) 
    {}

    // 在类外定义成员函数
    void display();  // 注意：函数声明在类内，定义在类外
};

// 在类外定义 Teacher 类的 display 成员函数
void Teacher::display() 
{
    Person::display();  // 调用基类 Person 的 display 函数
    cout << "职称：" << title << endl;
}

// 定义干部类 Cadre，继承自 Person
class Cadre : public Person 
{
public:
    string post;

    // 构造函数
    Cadre(string n, int a, char g, string addr, string ph, string p) 
        : Person(n, a, g, addr, ph), post(p) 
    {}

    // 在类外定义成员函数
    void display();  // 注意：函数声明在类内，定义在类外
};

// 在类外定义 Cadre 类的 display 成员函数
void Cadre::display() 
{
    Person::display();  // 调用基类 Person 的 display 函数
    cout << "职务：" << post << endl;
}

// 定义教师兼干部类 Teacher_Cadre，多重继承自 Teacher 和 Cadre
class Teacher_Cadre : public Teacher, public Cadre {
public:
    double wages;

    // 构造函数
    Teacher_Cadre(string n, int a, char g, string addr, string ph, string t, string p, double w)
        : Teacher(n, a, g, addr, ph, t), Cadre(n, a, g, addr, ph, p), wages(w) {}

    // 成员函数显示教师兼干部信息
    void show();
};

// 在类外定义 Teacher_Cadre 类的 show 成员函数
void Teacher_Cadre::show() 
{
    Teacher::display();  // 调用基类 Teacher 的 display 函数
    cout << "职务：" << post << endl;
    cout << "工资：" << wages << endl;
}

int main() 
{
    // 创建一个教师兼干部对象
    Teacher_Cadre teacherCadre("张三", 35, 'M', "北京", "123456789", "教授", "主任", 5000.00);

    // 调用成员函数显示信息
    teacherCadre.show();

    return 0;
}

