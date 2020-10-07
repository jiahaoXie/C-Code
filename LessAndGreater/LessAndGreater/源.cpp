//less()方法为从小到大排序
//greater()为从大到小排序

#include <vector>  
#include <algorithm>  
#include <functional>  
#include <cstdlib>  
#include <iostream>  
using namespace std;

int main()
{
	vector <int> v1;
	vector <int>::iterator Iter1;

	int i;
	for (i = 0; i < 8; i++)
	{
		v1.push_back(rand());	//rand()方法 随机数存储在vector中
	}

	cout << "Original vector v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;
	cout << endl;

	cout << "To sort in ascending order, use default binary predicate less<int>( )" << endl;
	sort(v1.begin(), v1.end());
	cout << "Sorted vector v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;
	cout << endl;

	cout << " To sort in descending order, specify binary predicate greater<int>( )" << endl;
	sort(v1.begin(), v1.end(), greater<int>());
	cout << "Resorted vector v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;

	system("pause");
}