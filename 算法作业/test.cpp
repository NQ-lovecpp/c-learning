//#include <iostream>
//#include <vector>
//#include <ctime>
//#include <algorithm>
//#include <chrono>
//#include <functional>
//#include <random>  
//
//using namespace std;
//
//// 用于生成指定范围内的随机整数  
//int GenerateRandomInt(int min, int max) 
//{
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dis(min, max);
//    return dis(gen);
//}
//
//// 打印数组
//void PrintArray(vector<int>& arr)
//{
//    cout << "Array: ";
//    for (auto e : arr)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//}
//
//// 目标：找到子数组的首尾下标
//// 说明：返回值是一个vector，返回最大子数组区间和总和
//// 1. dp（只能找到最大长度，不能确定子数组首尾下标）
//vector<int> FindMaxSubarray1(vector<int>& arr)
//{
//    // dp[i]表示，以i位置为结尾的所有子数组中，最大的元素和
//    vector<int> dp(arr.size() + 1, 0);
//    dp[0] = arr[0];
//    int ret = INT_MIN;
//    for (int i = 1; i < dp.size(); i++)
//    {
//        dp[i] = max(dp[i - 1] + arr[i - 1], arr[i - 1]);
//        ret = max(ret, dp[i]);
//    }
//    return { -1, -1 ,ret }; // 这里返回-1是因为这个方法不知道具体下标
//}
//
// // 2. 分治法
//vector<int> FindMaxSubarrayRecursive(vector<int>& arr, int low, int high);
//vector<int> FindMaxCrossingSubarray(vector<int>& arr, int low, int mid, int high);
//vector<int> FindMaxSubarray2(vector<int>& arr)
//{
//    return FindMaxSubarrayRecursive(arr, 0, arr.size() - 1);
//}
//
//vector<int> FindMaxSubarrayRecursive(vector<int>& arr, int low, int high)
//{
//    if (high == low)
//        return { low, high, arr[low] };
//
//    int mid = (low + high) / 2;
//
//    // 递归解决左右两边的子问题
//    vector<int> left_max_subarray = FindMaxSubarrayRecursive(arr, low, mid);
//    vector<int> right_max_subarray = FindMaxSubarrayRecursive(arr, mid + 1, high);
//    vector<int> cross_max_subarray = FindMaxCrossingSubarray(arr, low, mid, high);
//
//    // 返回三个中的最大值
//    if (left_max_subarray[2] >= right_max_subarray[2] && left_max_subarray[2] >= cross_max_subarray[2])
//        return left_max_subarray;
//    else if (right_max_subarray[2] >= left_max_subarray[2] && right_max_subarray[2] >= cross_max_subarray[2])
//        return right_max_subarray;
//    else
//        return cross_max_subarray;
//}
//
//vector<int> FindMaxCrossingSubarray(vector<int>& arr, int low, int mid, int high)
//{
//    int left_sum = INT_MIN;
//    int sum = 0;
//    int max_left, max_right;
//
//    // 左半部分，从mid向low扫描
//    for (int i = mid; i >= low; i--)
//    {
//        sum += arr[i];
//        if (sum > left_sum)
//        {
//            left_sum = sum;
//            max_left = i;
//        }
//    }
//
//    int right_sum = INT_MIN;
//    sum = 0;
//
//    // 右半部分，从mid+1向high扫描
//    for (int j = mid + 1; j <= high; j++)
//    {
//        sum += arr[j];
//        if (sum > right_sum)
//        {
//            right_sum = sum;
//            max_right = j;
//        }
//    }
//
//    return { max_left, max_right, left_sum + right_sum };
//}
//
//
//// 3. 暴力枚举（枚举所有子数组）
//vector<int> FindMaxSubarray3(vector<int>& arr)
//{
//    int max_sum = INT_MIN;
//    int start_index, end_index;
//
//    for (int i = 0; i < arr.size(); ++i)
//    {
//        int sum = 0;
//        for (int j = i; j < arr.size(); ++j)
//        {
//            sum += arr[j];
//            if (sum > max_sum)
//            {
//                max_sum = sum;
//                start_index = i;
//                end_index = j;
//            }
//        }
//    }
//
//    return { start_index, end_index, max_sum };
//}
//
//
//// 随机生成数组并调用测试代码
//void TestTime(size_t size, function<vector<int>(vector<int>&)> func, int min, int max)
//{
//    std::vector<int> nums(size);
//    // std::generate(nums.begin(), nums.end(), std::rand);
//    std::generate(nums.begin(), nums.end(), [&]() { return GenerateRandomInt(min, max); });
//
//    // PrintArray(nums);
//
//    auto start = std::chrono::high_resolution_clock::now();
//
//    vector<int> ret = func(nums);
//    
//    auto end = std::chrono::high_resolution_clock::now();
//
//    std::cout << "Array Size: " << size 
//              << "\nTime: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" 
//              << "\nMax Subarray Size: " << ret[2]
//              << "\nMax Subarray Section: [" << ret[0] << ", " << ret[1] << "]"
//              << std::endl;
//}
//
//int main()
//{
//    std::cout << "开始测试最大子数组问题的算法性能：" << std::endl;
//
//    std::cout << "\n方法1：动态规划法" << std::endl;
//    TestTime(5000, FindMaxSubarray1, -100, 100);
//    TestTime(10000, FindMaxSubarray1, -100, 100);
//    TestTime(100000, FindMaxSubarray1, -100, 100);
//    TestTime(1000000, FindMaxSubarray1, -100, 100);
//
//    cout << endl;
//
//    std::cout << "\n方法2：分治法" << std::endl;
//    TestTime(5000, FindMaxSubarray2, -100, 100);
//    TestTime(10000, FindMaxSubarray2, -100, 100);
//    TestTime(100000, FindMaxSubarray2, -100, 100);
//    TestTime(1000000, FindMaxSubarray2, -100, 100);
//
//    cout << endl;
//
//    std::cout << "\n方法3：暴力枚举法" << std::endl;
//    TestTime(5000, FindMaxSubarray3, -100, 100);
//    TestTime(10000, FindMaxSubarray3, -100, 100);
//    TestTime(100000, FindMaxSubarray3, -100, 100);
//    TestTime(1000000, FindMaxSubarray3, -100, 100);
//
//    std::cout << "\n测试结束。" << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// 动态规划求解最优乘法顺序
void matrixChainOrder(vector<int> p, vector<vector<int>>& m, vector<vector<int>>& s) {
    int n = p.size() - 1;
    for (int i = 1; i <= n; ++i)
        m[i][i] = 0;

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// 输出矩阵最优乘法顺序
void printOptimalParentheses(vector<vector<int>>& s, int i, int j) 
{
    if (i == j)
        cout << "A" << i;
    else 
    {
        cout << "(";
        printOptimalParentheses(s, i, s[i][j]);
        printOptimalParentheses(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    vector<int> p = { 5, 10, 3, 12, 5, 50, 6 };
    int n = p.size() - 1;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    matrixChainOrder(p, m, s);
    end = clock();
    cpu_time_used = ((double)(end - start));
    cout << "矩阵最优乘法顺序：";
    printOptimalParentheses(s, 1, n);
    cout << endl;
    cout << "运行时间：" << cpu_time_used << " 毫秒" << endl;

    // 随机生成矩阵规模数组，运行算法求解矩阵最优乘法顺序，并输出运行时间
    for (int size : {50, 100}) 
    {
        p.clear();
        p.push_back(size);
        for (int i = 0; i < size; ++i)
            p.push_back(rand() % 100 + 1); // 随机生成矩阵规模

        n = p.size() - 1;
        m = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        s = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

        start = clock();
        matrixChainOrder(p, m, s);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        cout << "矩阵规模为 " << size << " 时，运行时间：" << cpu_time_used << " 秒" << endl;
    }

    return 0;
}

