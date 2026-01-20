// A

//#include <iostream>
//using namespace std;
//
//using ll = long long;
//
//int main()
//{
//	int _n;
//	cin >> _n;
//	while (_n--)
//	{
//		ll n, a, b;
//		cin >> n >> a >> b;
//		if (b / 2.0 <= a)
//		{
//			if (n % 2 == 0)
//			{
//				cout << b * (n / 2) << endl;
//			}
//			else
//			{
//				cout << b * (n / 2) + a << endl;
//			}
//		}
//		else
//		{
//			cout << n * a << endl;
//		}
//	}
//	return 0;
//}

// B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void func()
{
	ll n, c, d;
	cin >> n >> c >> d;
	vector<int> src(n);
	for (int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		src[i] = tmp;
	}
	sort(src.begin(), src.end());

	int row_start = src[0];
	for (int i = 0; i < n; i++)
	{
		int to_find = row_start;
		for (int j = 0; j < n; j++)
		{
			if (!binary_search(src.begin(), src.end(), to_find))
			{
				cout << "NO" << endl;
				return;
			}
			to_find += d;
		}
		row_start += c;
	}
	cout << "YES" << endl;
}

int main()
{
	int _n;
	cin >> _n;
	while (_n--)
	{
		func();
	}

	return 0;
}
