#pragma once
namespace mystl
{
	template<class T>
	class vector
	{
	public:
		//vector的迭代器是原生指针
		typedef T* iterator;
		typedef const T* citerator;
	public:
		//迭代器
		iterator begin() { return _begin; }
		iterator end() { return _end; }
		iterator rbegin() { return _end; }
		iterator rend() { return _begin; }
		citerator cbegin() { return _begin; }
		citerator cend() { return _end; }
		citerator crbegin() { return _end; }
		citerator crend() { return _begin; }


		vector(){}
		size_t size() { return _end - _begin; }
		size_t capacity() { return _endOfstorage - _begin; }
		vector(size_t n, const T& value = T())
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		iterator insert(iterator pos, const T& value)
		{

		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t N = size();
				T* tmp = new T[n];

				if (_begin) 
				{
					for(int i = 0; i<N; ++i)
					{
						tmp[i] = _begin[i];
					}
					delete[] _begin;
				}

				_begin = tmp;
				_end = _begin + N;
				_endOfstorage = _begin + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			//如果小于当前有效元素，直接缩小
			if (n <= size()) {
				_end = _begin + n;
				return;
			}
			//如果大于当前容量，扩容
			if (n > capacity()) {
				reserve(n);
			}
			//扩大size;
			iterator end = _start + n;
			while (_end != end)
			{
				*_end = value;
				++_end;
			}

		}
		
		~vector()
		{
			if(_begin != nullptr)
				delete[]_begin;
			_begin = _end = _endOfstorage = nullptr;
		}
	private:
		iterator _begin = nullptr;
		iterator _end = nullptr;
		iterator _endOfstorage = nullptr;
	};
}//mystl