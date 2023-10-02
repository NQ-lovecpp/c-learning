//void menu()
//{
//	printf("********************************\n");
//	printf("*****    1. add     2. del   ***\n");
//	printf("*****    3. search  4. modify***\n");
//	printf("*****    5. show    6. sort  ***\n");
//	printf("*****    0. exit             ***\n");
//	printf("********************************\n");
//}

namespace chen
{
	struct ContactNodeData
	{
		std::string name;
		int age;
		std::string sex;
		std::string tele;
	};
	class Contact
	{
		//初始化通讯录 构造函数
		Contact()
		{}

		//销毁通讯
		~Contact()
		{}

		//增加指定联系人
		void AddContact()
		{
			ContactNodeData d;

			cout << "请输入姓名:" << endl;
			cin >> d.name;
			cout << "请输入年龄:" << endl;
			cin >> d.age;
			cout << "请输入性别:" << endl;
			cin >> d.sex;
			cout << "请输入电话:" << endl;
			cin >> d.tele;

			con.push_back(d);
		}

		//显示联系人信息
		void ShowContact()
		{
			int i = 1;
			for (auto e : con)
			{

			}
		}

		//删除指定联系人
		void DelContact();

		//查找指定联系人
		void SearchContact();

		//修改通讯录
		void ModifyContact();

		//排序通讯录元素
		void SortContact();

		//保存数据到文件
		void SaveContact();
	private:
		std::list<ContactNodeData> con;
	};
}