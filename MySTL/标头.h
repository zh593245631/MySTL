#pragma once
#include<new>
#include<cstdlib>
#include<cstddef>
#include<climits>
#include<iostream>
namespace mystl
{
	//allocator
	template <class T>
	inline T* _allocate(ptrdiff_t size, T*)
	{
		set_new_handler(0);
		T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
		if (tmp == 0) {
			cerr << "out of memory" << endl;
			exit(1);
		}
		return tmp;
	}

	template <class T>
	inline void deallocate(T* buffer)
	{
		::operator delete(buffer);
	}

	template<class T>
	class allocator
	{
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		pointer allocate(size_type n)
		{
			return ::alocate((difference_type)n, (pointer)0);
		}
		void deallocate(pointer p){ }
	};
}
