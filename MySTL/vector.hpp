#pragma once
namespace mystl
{
	template<class T>
	class vector
	{
	public:
		//vector�ĵ�������ԭ��ָ��
		typedef T* iterator;
		typedef const T* citerator;
	public:
		//������
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
			//���С�ڵ�ǰ��ЧԪ�أ�ֱ����С
			if (n <= size()) {
				_end = _begin + n;
				return;
			}
			//������ڵ�ǰ����������
			if (n > capacity()) {
				reserve(n);
			}
			//����size;
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