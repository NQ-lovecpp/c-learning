//#include <iostream>
//using namespace std;
//
//struct DATA
//{
//    int a[2];//两个数
//    int c;   //两个数的和
//    
//    //返回两数中的最大数
//    int max()
//    {
//        return a[0] > a[1] ? a[0] : a[1];
//    };
//}data_a[5];
//
//DATA data_b = { {15, 20}, 35 };
//
//int main()
//{
//    cout << data_b.max() << endl;
//    //输入
//    for (int i = 0;i < 5;++i)
//    {
//        cin >> data_a[i].a[0] >> data_a[i].a[1];
//        data_a[i].c = data_a[i].a[0] + data_a[i].a[1];
//    }
//    //输出
//    for (int i = 0;i < 5;++i)
//        cout << data_a[i].max() << " " << data_a[i].c << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class rectangular
//{
//public:
//	rectangular(float len = 0, float wid = 0, float hei = 0)
//		:length(len)
//		,width(wid)
//		,height(hei)
//	{}
//	float calc_volume()
//	{
//		return length * width * height;
//	}
//
//	float length;
//	float width;
//	float height;
//};
//
//int main()
//{
//	rectangular rec_arr[3];
//	for (auto& e : rec_arr)
//	{
//		cout << "输入长宽高：";
//		cin >> e.height >> e.length >> e.width;
//	}
//	for (auto& e : rec_arr)
//	{
//		cout << e.calc_volume() << endl;
//	}
//
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class student
//{
//public:
//	student(int nu = 0, string s = "", int ag = 0)
//		:num(nu)
//		,name(s)
//		,age(ag)
//	{}
//
//	void setvalue()
//	{
//		cout << "输入编号";
//		cin >> num;
//		cout << "输入姓名";
//		cin >> name;
//		cout << "输入年龄";
//		cin >> age;
//	}
//
//	void print()
//	{
//		cout << "编号:" << num << "	 ";
//		cout << "姓名:" << name << "	 ";
//		cout << "年龄:" << age << "	 " << endl;
//	}
//
//private:
//	int num;
//	string name;
//	int age;
//};
//
//int main()
//{
//	student s1(001, "chen", 19);
//	s1.print();
//	s1.setvalue();
//	s1.print();
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <functional> // greater算法的头文件
using namespace std;
void TestPriorityQueue()
{
	// 默认情况下，创建的是大堆，其底层按照小于号比较
	vector<int> v{3, 2, 7, 6, 0, 4, 1, 9, 8, 5};
	priority_queue<int> q1;
	for (auto& e : v)
		q1.push(e);
	cout << q1.top() << endl;
	// 如果要创建小堆，将第三个模板参数换成greater比较方式
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;
}

int main()
{
	TestPriorityQueue();
	return 0;
}