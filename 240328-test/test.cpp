//#include <iostream>
//#include <utility>
//
//struct My_String
//{
//	My_String(const char* s)
//		:_str(s)
//	{}
//
//	const char* _str;
//};
//
//const std::string& foo1(const std::string& s)
//{
//	return s;
//}
//
//const My_String& foo2(const My_String& s)
//{
//	return s;
//}
//
//int main()
//{
//	int a = 10; 
//	int b = 20;
//
//	auto [a, b] = std::pair<int, int>(a, b);
//
//	//auto str1 = "hello world 1";
//	//const std::string& str2 = static_cast<const std::string&>("hello world 2");
//
//	//const My_String& str3 = static_cast<const My_String&>("hello world 3");
//
//	//std::cout << str2 << std::endl;
//	//std::cout << str3._str << std::endl;
//
//	auto& result_std = foo1("hello world 4");
//	std::cout << result_std.c_str() << std::endl;
//
//	auto& result_mystring = foo2("hello world 5");
//	std::cout << result_mystring._str << std::endl;
//
//	return 0;
//}



//#include <iostream>
//#include <tuple>
//
//// C++14
//auto returnValues14()
//{
//    return std::make_tuple(1, 2);
//}
//
//int main()
//{
//    // C++17
//    auto [a, b] = returnValues14();
//    std::cout << "a:" << a << ", b:" << b << std::endl;
//    return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct BindTest
{
    int field1 = 1;
    std::string field2 = "hello";
};

int main()
{
    std::unique_ptr<const char *> usvr = std::make_unique<const char *>("0.0.0.0");
    auto t = std::make_tuple(1, "hi");
    auto [x, ignore] = t;
    auto [y, ignore] = t;  // 编译错误，ignore无法重复声明

    // std::vector<BindTest> btVec = { {1, "this is 1"}, {2, "this is 2"}, {3, "this is 3"} };
    std::vector<std::pair<int, std::string>> btVec = { {1, "this is 1"}, {2, "this is 2"}, {3, "this is 3"} };

    for (const auto& [x, y] : btVec)
    {
        std::cout << "x:" << x << ", y:" << y << std::endl;
    }
    return 0;
}
