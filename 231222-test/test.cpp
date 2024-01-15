//#include <iostream>
//using namespace std;
//#include <string>
//class teacher 
//{
//public:
//	teacher(const char* _n, int a, const char* s, const char* adr, const char* ph, const char* ti)
//		:name(_n),
//		age(a),
//		sex(s),
//		adress(adr),
//		phonenummber(ph),
//		title(ti) {}
//	void display();
//private:
//	string name;
//	int age;
//	string sex;
//	string adress;
//	string phonenummber;
//	string title;
//};
//
//void teacher::display() 
//{
//	cout << "老师的名字，年龄，性别，职称，地址，电话分别是" << name << " " << age << " " << sex << " " << title << " " << adress << " " << phonenummber << endl;
//}
//
//class cadre 
//{
//public:
//	cadre(const char* _n, int a, char s, char adr, char ph, char po)
//		:name(_n),
//		age(a),
//		sex(s),
//		adress(adr),
//		phonenummber(ph),
//		post(po)
//	{}
//	void display2();
//private:
//	string name;
//	int age;
//	char sex;
//	char adress;
//	char phonenummber;
//	char post;
//};
//
//void cadre::display2() 
//{
//	cout << "他的职位是：" << post << endl;
//}
//
//class teacher_cadre :public teacher, public cadre 
//{
//public:
//	teacher_cadre(const char* _n, int a, char s, char adr, char ph, char ti, char po, int wa)
//		:teacher(_n, a, s, adr, ph, ti),
//		cadre(_n, a, s, adr, ph, po),
//		wages(wa) {}
//	void show();
//private:
//	int wages;
//};
//
//void teacher_cadre::show() 
//{
//	display();
//	display2();
//	cout << "他的工资是：" << wages << endl;
//}
//int main()
//{
//	teacher t1("葛博闻", 20, "男", "上海杨浦", "18916641390", "B W Ge");
//
//}

#include <vector>
#include <iostream>
#include <utility>

typedef std::vector<int> Sqlist;

int Partition(Sqlist& L, int low, int high)
{
    int KeyIndex = low;
    int  privotkey = L[low];
    while (low < high)
    {
        while (L[high] >= privotkey && low < high)
        {
            high--;
        }
        while (L[low] <= privotkey && low < high)
        {
            low++;
        }
        std::swap(L[low], L[high]);
    }
    std::swap(L[KeyIndex], L[low]);
    return low;
}
void QSort(Sqlist& L, int low, int high)
{
    if (low < high)
    {
        int k = Partition(L, low, high);
        QSort(L, low, k - 1);
        QSort(L, k + 1, high);
    }
    else
    {
        return;
    }
}

int main()
{
    std::vector<int> array = { 421,5,3,46,78,68,6324,75,8623,432 };
    QSort(array, 0, array.size() - 1);

    for (int elem : array)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}