#include<iostream>
#include<algorithm>
#include<functional>
#include"vector.hpp"
/*int main()
{
	std::vector<int> v;
	std::cout << v.capacity() << std::endl;
	return 0;
}*/

//using namespace std;
//int main()
//{
//	int a[] = { 1,2,3,4,5,6 };
//	vector<int, allocator<int>> v(a, a + 6);
//	
//	cout << count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 4)));
//	return 0;
//}

using namespace mystl;
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(2);

	v.push_back(4);
	v.push_back(11);
	v.push_back(0);
	v.push_back(3);
	v.pop_back();
	vector<int> v2(v);
	v2.swap(v);
	std::sort(v.begin(), v.end());
	for (auto& e : v)
		std::cout << e<<" ";
	return 0;
}

