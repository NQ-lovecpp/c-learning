#include "PasswordManager.h"

PasswordManager::PasswordManager()
{
    if (!LoadPasswordFromFile())
    {
        // 如果密码文件不存在或无法读取，则设置默认密码
        password = "12345"; // 你可以设置自己的默认密码
        SavePasswordToFile();
    }
}

bool PasswordManager::IsPasswordCorrect(const std::string& inputPassword)
{
    return inputPassword == password;
}

void PasswordManager::ChangePassword()
{
    std::string newPassword;
    std::cout << "请输入新密码: ";
    std::cin >> newPassword;
    password = newPassword;
    SavePasswordToFile();
    std::cout << "密码修改成功！" << std::endl;
}

void PasswordManager::SavePasswordToFile()
{
    std::ofstream outFile(passwordFileName);
    if (outFile.is_open())
    {
        outFile << password;
        outFile.close();
    }
    else
    {
        std::cerr << "无法保存密码到文件。" << std::endl;
    }
}

bool PasswordManager::LoadPasswordFromFile()
{
    std::ifstream inFile(passwordFileName);
    if (inFile.is_open())
    {
        inFile >> password;
        inFile.close();
        return true;
    }
    return false;
}
