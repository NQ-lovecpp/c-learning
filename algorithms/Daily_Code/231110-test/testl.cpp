#include <iostream>
#include <fstream>
#include <stack>
#include <string>

// 美化源代码的函数
void beautifySourceCode(const std::string& inputFilePath, const std::string& outputFilePath) 
{
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath);
    std::stack<char> bracketsStack; // 用于检查括号匹配的栈
    int indentLevel = 0; // 缩进级别
    std::string line;

    if (!inputFile.is_open()) 
    {
        std::cerr << "打开输入文件时出错！" << std::endl;
        return;
    }

    if (!outputFile.is_open()) 
    {
        std::cerr << "打开输出文件时出错！" << std::endl;
        return;
    }

    // 读取每一行
    while (getline(inputFile, line)) 
    {
        for (char& ch : line) 
        {
            switch (ch) 
            {
            case '{':
                bracketsStack.push(ch);
                outputFile << std::string(indentLevel, '\t') << ch << std::endl;
                indentLevel++; // 增加缩进级别
                break;
            case '}':
                if (!bracketsStack.empty() && bracketsStack.top() == '{') {
                    bracketsStack.pop();
                    indentLevel--; // 减少缩进级别
                }
                else 
                {
                    std::cerr << "发现不匹配的闭合括号 '}'。" << std::endl;
                    return;
                }
                outputFile << std::string(indentLevel, '\t') << ch << std::endl;
                break;
                // 默认情况下，直接写入字符
            default:
                outputFile << ch;
                break;
            }
        }
        // 结束当前行
        outputFile << std::endl;
    }

    // 如果栈不为空，说明有未匹配的括号
    if (!bracketsStack.empty()) 
    {
        std::cerr << "发现未匹配的括号。" << std::endl;
    }
}

// 主函数
int main() 
{
    std::string inputFilePath = "input.cpp"; // 输入文件路径
    std::string outputFilePath = "output.cpp"; // 输出文件路径

    beautifySourceCode(inputFilePath, outputFilePath); // 调用美化函数

    return 0;
}
