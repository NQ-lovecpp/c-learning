#pragma once

template<class Iterator>
class ReverseIterator
{
public:
	typedef ReverseIterator<Iterator> Self;

	ReverseIterator(Iterator it)
		:_it(it)
	{}


	Self& operator++()
	{
		--_it;
		return *this;
	}

private:
	Iterator _it;
};