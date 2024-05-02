#pragma once
#include <iostream>

namespace chen
{

	template<class Mutex>
	class lock_guard
	{
	public:
		lock_guard(Mutex& mtx)
			:_mtx(mtx)
		{
			std::cout << "lock_guard(Mutex& mtx)" << std::endl;
			_mtx.lock();
		}
		~lock_guard()
		{
			std::cout << "~lock_guard()" << std::endl;
			_mtx.unlock();
		}

		lock_guard& operator=(lock_guard<Mutex>&) = delete;
		lock_guard(lock_guard<Mutex>&) = delete;

	private:
		Mutex& _mtx;
	};

}