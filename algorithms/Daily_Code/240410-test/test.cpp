//#include <iostream>  
//#include <vector>  
//#include <algorithm>  
//
//int findElementIndex(const std::vector<int>& arr, int target) 
//{
//    // 首先检查元素是否存在于数组中  
//    if (std::binary_search(arr.begin(), arr.end(), target)) 
//    {
//        // 使用std::lower_bound找到元素的第一个可能位置  
//        auto it = std::lower_bound(arr.begin(), arr.end(), target);
//        // 由于我们已经知道元素存在，所以it指向的就是元素的位置  
//        return std::distance(arr.begin(), it);
//    }
//    else 
//    {
//        return -1; // 元素不存在于数组中  
//    }
//}
//
//int main() {
//    std::vector<int> arr = { 1, 3, 5, 7, 9 };
//    int target = 5;
//    int index = findElementIndex(arr, target);
//
//    if (index != -1) 
//    {
//        std::cout << "Element found at index: " << index << std::endl;
//    }
//    else 
//    {
//        std::cout << "Element not found in the array" << std::endl;
//    }
//
//    return 0;
//}

#include <unordered_map>
#include <iostream>

int main()
{
	std::unordered_map<int, std::string> myMap;
	std::unordered_map<int, std::string>::const_iterator it = myMap.find(3);
	if (it != myMap.end())
	{
		std::cout << it->second << std::endl; // 输出找到的元素的值  
	}
}
