//#include <vector>
//namespace bit
//{
//	template<class T,class Container=std::vector<T>>
//	class priority_queue
//	{
//	public:
//		priority_queue()
//		{}
//
//		void adjust_up(int child)
//		{
//			int parent = (child - 1) / 2;
//			while (child > 0)
//			{
//				if (_con[child] > _con[parent])
//				{
//					swap(_con[child] > _con[parent]);
//					child = parent;
//					parent = (parent - 1) / 2;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//
//		void push(const T& x)
//		{
//			_con.push_back(x);
//			adjust_up(_con.size() - 1);
//		}
//
//		void adjust_down(int parent)
//		{
//			int child = parent * 2 + 1;
//			while (child < _con.size())
//			{
//				if (child < _con.size()
//					&& _con[child + 1]>_con.[child])
//				{
//					++child;
//				}
//
//				if (_con[child] > _con[parent])
//				{
//					swap(_con[child], _con[parent]);
//					parent = child;
//
//				}
//			}
//		}
//
//		void pop()
//		{
//			swap(_con[0], _con[_con.size() - 1]);
//			_con.pop_back();
//			adjust_down(0);
//		}
//
//		const T& top()
//		{
//			return con[0];
//		}
//
//		bool empty()
//		{
//			return _con.empty();
//		}
//
//
//	private:
//		Container _con;
//	};
//}