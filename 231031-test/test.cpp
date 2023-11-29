#include <iostream>
#include <string>
using namespace std;

class Student
{
	struct Grade
	{
		Grade(int oop, int poc, int dl)
			:GradesOfOOP(oop)
			, PrincipleOfComputerOrganization(poc)
			, DigitalLogic(dl)
		{}

		int GradesOfOOP;
		int PrincipleOfComputerOrganization;
		int DigitalLogic;
	};
public:
	Student(int id, const char* name, int oop, int poc, int dl)
		:_ID(id)
		, _name(name)
		, _StuG(oop, poc, dl)
	{}

	void ShowAvgGrade()
	{
		cout << "学生: " << _name << " 的平均成绩是：";
		cout << (_StuG.DigitalLogic
			+ _StuG.GradesOfOOP
			+ _StuG.PrincipleOfComputerOrganization) / 3 << endl;
	}
public:
	int _ID;
	string _name;
	Grade _StuG;
};

int main()
{
	const int numStudents = 3;
	Student students[numStudents] = {
		Student(1, "小明", 90, 85, 88),
		Student(2, "小红", 78, 92, 87),
		Student(3, "小李", 85, 80, 91)
	};

	for (int i = 0; i < numStudents; ++i)
	{
		cout << "学生ID: " << students[i]._ID << endl;
		cout << "学生姓名: " << students[i]._name << endl;
		students[i].ShowAvgGrade();
		cout << "--------------------------" << endl;
	}

	return 0;
}