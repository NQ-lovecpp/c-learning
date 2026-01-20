#pragma once
#include <iostream>
#include <cstdio>
#include <list>
#include <string>
#include <thread> // 用于进度条的延迟
#include <chrono> // 用于时间延迟
#include <cstdlib> // 用于清屏操作
using namespace std;
#include "Contact.h"
#include "PasswordManager.h"

void menu()
{
	printf("***********************************\n");
	printf("***    1. Add       2. Del      ***\n");
	printf("***    3. Search    4. Modify   ***\n");
	printf("***    5. Show      6. Sort     ***\n");
	printf("***    7. ChangePwd 0. Exit     ***\n");
	printf("***********************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
    CHANGE_PASSWORD
};

// 打印进度条
void showProgressBar(const std::string& message, int progress)
{
    const int width = 30; // 进度条的总宽度
    int progressBarWidth = (progress * width) / 100; // 计算进度条的宽度
    int remainingWidth = width - progressBarWidth;

    // 打印进度条部分
    std::cout << message << " [";
    for (int i = 0; i < progressBarWidth; ++i)
    {
        std::cout << "=";
    }
    for (int i = 0; i < remainingWidth; ++i)
    {
        std::cout << " ";
    }
    std::cout << "] " << std::setw(3) << std::right << progress << "%" << "\r"; // 使用\r将光标回到行首
    std::cout.flush();
}

int main()
{
    int input = 0;
    Contact c;

    PasswordManager passwordManager; // 创建密码管理对象

    // 如果密码不正确，要求用户输入密码
    while (1)
    {
        std::cout << "请输入密码: ";
        std::string inputPassword;
        std::cin >> inputPassword;
        if (!passwordManager.IsPasswordCorrect(inputPassword))
        {
            std::cout << "密码错误！请重新输入。" << std::endl;
        }
        else
        {
            break;
        }
    }

    do
    {
        // 清屏操作
        system("cls"); // Windows下清屏
        // system("clear"); // Linux和macOS下清屏

        menu();
        std::cout << "请选择:>";
        std::cin >> input;

        switch (input)
        {
        case ADD:
            c.AddContact();
            break;
        case DEL:
            c.DelContact();
            for (int progress = 0; progress <= 100; progress += 20)
            {
                showProgressBar("删除中...", progress);
                std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 模拟加载
            }
            break;
        case SEARCH:
            c.SearchContact();
            break;
        case MODIFY:
            c.ModifyContact();
            break;
        case SHOW:
            c.ShowContact();
            break;
        case SORT:
            // 添加排序操作
            break;
        case CHANGE_PASSWORD:
            passwordManager.ChangePassword();
            break;
        case EXIT:
            for (int progress = 0; progress <= 100; progress += 10)
            {
                showProgressBar("  退出中...", progress);
                std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 模拟加载
            }
            break;
        default:
            std::cout << "无效的选择，请重新输入。" << std::endl;
            break;
        }

        if (input != EXIT)
        {
            std::cout << "按回车键继续...";
            std::cin.ignore(); // 暂停等待用户按回车键继续
            std::cin.get(); // 捕捉回车键
        }

    } while (input != EXIT);

    return 0;
}
