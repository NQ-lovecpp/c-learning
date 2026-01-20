#include <iostream>
#include <string>

using namespace std;

// 前置声明，用于实现递归
int evaluate(string::iterator& it, string::iterator end);

// 解析因子（数字或括号内的表达式）
int evaluateFactor(string::iterator& it, string::iterator end)
{
    int factor = 0;
    // 判断是否是括号内的表达式
    if (it != end && *it == '(')
    {
        ++it; // 跳过 '('
        factor = evaluate(it, end);
        if (it != end)
        {
            ++it; // 跳过 ')'
        }
    }
    else
    {
        // 解析数字
        while (it != end && isdigit(*it))
        {
            factor = factor * 10 + (*it - '0');
            ++it;
        }
    }
    return factor;
}

// 解析项（由乘法和除法组成）
int evaluateTerm(string::iterator& it, string::iterator end)
{
    int term = evaluateFactor(it, end);
    // 循环处理乘法和除法
    while (it != end && (*it == '*' || *it == '/'))
    {
        char op = *it;
        ++it; // 跳过运算符
        int factor = evaluateFactor(it, end);
        if (op == '*')
        {
            term *= factor;
        }
        else
        {
            term /= factor;
        }
    }
    return term;
}

// 解析完整表达式（由加法和减法组成）
int evaluate(string::iterator& it, string::iterator end)
{
    int expressionValue = evaluateTerm(it, end);
    // 循环处理加法和减法
    while (it != end && (*it == '+' || *it == '-'))
    {
        char op = *it;
        ++it; // 跳过运算符
        int term = evaluateTerm(it, end);
        if (op == '+')
        {
            expressionValue += term;
        }
        else
        {
            expressionValue -= term;
        }
    }
    return expressionValue;
}

int main()
{
    // string expression = "22+15*(33-27)/3";
    string expression = "10+2*(6/2)";
    string::iterator it = expression.begin();
    // 输出计算结果
    cout << evaluate(it, expression.end()) << endl;

    return 0;
}
