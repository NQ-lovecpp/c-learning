#include <list>

namespace bit
{
	template<class T,class Container=std::list<T>>
	class queue
	{
	public:
		queue()
		{}

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		T& back()
		{
			return _con.back();
		}

		const T& back()const
		{
			return _con.back();
		}

		T& front()
		{
			return _con.fornt();
		}

		const T& front()const
		{
			return _con.fornt();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};



}