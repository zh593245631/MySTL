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
		iterator begin()const { return _begin; }
		iterator end()const { return _end; }
		iterator rbegin()const { return _end; }
		iterator rend()const { return _begin; }
		citerator cbegin()const { return _begin; }
		citerator cend()const { return _end; }
		citerator crbegin()const { return _end; }
		citerator crend()const { return _begin; }


		size_t size()const { return _end - _begin; }
		size_t capacity()const { return _endOfstorage - _begin; }


		vector():_begin(nullptr),_end(nullptr),_endOfstorage(nullptr){}

		vector(size_t n, const T& value = T())
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		template<class inputiterator>
		vector(inputiterator beg, inputiterator end)
		{
			reserve(end - beg);
			while (beg != end)
			{
				push_back(*beg);
				++beg;
			}
		}
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			citerator cur = v.cbegin();
			iterator vit = begin();
			while (cur != v.cend())
			{
				*vit = *cur;
				++cur;
				++vit;
			}
			_end = _begin + v.size();


		}
		void push_back(const T& value)
		{
			insert(_end, value);
		}
		void pop_back()
		{
			erase(_end - 1);
		}
		T& operator[](int n)
		{
			return _begin[n];
		}
		vector<T>& operator=(vector<T>& v)
		{
			vector<T> tmp(v);
			swap(tmp);
			return *this;
		}
		void swap(vector<T>& v)
		{
			std::swap(_begin, v._begin);
			std::swap(_end, v._end);
			std::swap(_endOfstorage, v._endOfstorage);
		}
		iterator insert(iterator pos, const T& value)
		{
			if (_end == _endOfstorage) {
				size_t size = pos - _begin;
				size_t n = capacity() == 0 ? 10 : 2 * capacity();
				check(n);
				pos = _begin + size;
			}

			iterator end = _end;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = value;
			++_end;
			return pos;
		}

		iterator erase(iterator pos)
		{
			iterator cur = pos + 1;
			while (cur != _end)
			{
				*(cur-1) = *cur;
				++cur;
			}
			--_end;
			return pos;
		}
		void reserve(const size_t n)
		{
			if (n > capacity())
			{
				check(n);
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
			iterator end = _begin + n;
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
		void check(const int n)
		{
			
			size_t Size = size();
			T* tmp = new T[n];

			if (_begin) {
				for (size_t i = 0; i < Size; ++i)
				{
					tmp[i] = _begin[i];
				}
				delete[] _begin;
			}
			_begin = tmp;
			_end = _begin + Size;
			_endOfstorage = _begin + n;
		}
	private:
		iterator _begin = nullptr;
		iterator _end = nullptr;
		iterator _endOfstorage = nullptr;
	};
}//mystl