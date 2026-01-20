#pragma once
#include <iostream>
#include <fstream>
#include <string>

class PasswordManager
{
public:
    PasswordManager();
    bool IsPasswordCorrect(const std::string& inputPassword);
    void ChangePassword();
    void SavePasswordToFile();

private:
    std::string password;
    const std::string passwordFileName = "password.txt"; // 存储密码的文件名

    bool LoadPasswordFromFile();
};
