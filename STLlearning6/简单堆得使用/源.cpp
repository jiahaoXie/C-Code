#include<iostream>
#include<functional>
#include<queue>
#include<iterator>
using namespace std;

void main()
{
	int a[] = {5,1,2,4,3};
	make_heap(a,a+5);	//默认为小根堆
	
	copy(a,a+5,ostream_iterator<int>(cout," "));
	cout << endl;

	sort_heap(a,a+5/*,less<int>()*/);
	copy(a,a+5,ostream_iterator<int>(cout," "));
	cout << endl;

	make_heap(a, a + 5, greater<int>());	//greater()方法为大根堆
	sort_heap(a, a + 5,greater<int>());
	copy(a, a + 5, ostream_iterator<int>(cout, " "));
	cout << endl;
	system("pause");
}