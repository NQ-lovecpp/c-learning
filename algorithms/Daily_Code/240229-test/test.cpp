//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Mycompare
//{
//	bool operator()(int& a1, int& a2)
//	{
//		return a1 < a2;
//	}
//
//};
//
//int main()
//{
//	vector<int> array = { 1,0,9,5,423,6,23 };
//	// sort(array.begin(), array.end(), greater<int>());
//	sort(array.begin(), array.end(), [](int& a1, int& a2)-> bool {return a1 < a2;});
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//
//	return 0;
//}


//#include <iostream>
//#include <utility>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    int size;
//    cin >> size;
//    vector<pair<int, int>> arr(size);
//    for (auto& kv : arr)
//    {
//        cin >> kv.first;
//        cin >> kv.second;
//    }
//
//    int left_bound = 0;
//    int right_bound = 0;
//
//    for (int i = 1; i <= arr[0].first; i++)
//    {
//        bool flag = true;
//        for (auto kv : arr)
//        {
//            if (kv.first / i != kv.second)
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag)
//        {
//            left_bound = i;
//            break;
//        }
//    }
//
//    for (int i = arr[0].first; i >= 1; i--)
//    {
//        bool flag = true;
//        for (auto kv : arr)
//        {
//            if (kv.first / i != kv.second)
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag)
//        {
//            right_bound = i;
//            break;
//        }
//    }
//
//    cout << left_bound << " " << right_bound;
//
//    return 0;
//}


#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct MyCmp
{
    bool operator()(pair<int, int> kv1, pair<int, int> kv2)
    {
        return kv1.first < kv2.first;
    }
};

int main()
{
    int size;
    cin >> size;
    vector<pair<int, int>> arr(size);

    for (auto& kv : arr)
    {
        cin >> kv.first;
        cin >> kv.second;
    }

    int left = 1;
    int right = 100;

    while (left < right)
    {
        int mid = (left + right) / 2;

        bool flag = true;
        for (auto kv : arr)
        {
            if (kv.first / mid != kv.second)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    int left_bound = left;
    left = 1;
    right = 100;

    while (left < right)
    {
        int mid = (left + right + 1) / 2;

        bool flag = true;
        for (auto kv : arr)
        {
            if (kv.first / mid != kv.second)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }
    }


    cout << left_bound << " " << right;

    return 0;
}


