#include<iostream>
#include<vector>
using namespace std;

void main()
{
	vector<int> v;
	//内部能够容纳的元素个数[容量] capacity() 
	//vector内部所存放的元素个数 size()	    capacity()>=size()
	//一般情况下， 向量缓存了一部分内存空间（用来容纳更多的元素），
		//这样在下一次插入元素的时候，就不必重新分配内存，提高插入速度.
			//一般情况下 向量vector在前期逐个缓存内存空间后 后面采取缓冲50%的内存空间
	/*capacity   size
		0		0			初始化：容量为0，元素个数也为0
		1		1			容量扩充之前的50%还是为0，存放第一个元素所以容量设为1，元素个数为1
		2		2			继续插入第二个元素，容量扩充之前的50%（1+1/2=1,不足以容纳2个元素）,容量设为2，元素个数为2
		3		3			继续插入第三个元素，容量扩充之前的50%（2+ 2 / 2 = 3）容量为3，元素个数为3
		4		4			继续插入第四个元素，容量扩充之前的50%（3+ 3 / 2 = 4）容量为4，元素个数为4
		6		5			继续插入第五个元素，容量扩充之前的50%（4+ 4 / 2 = 6）容量为6，元素个数为5
		6		6			继续插入第六个元素，容量为6（不需要扩充）	容量为6，元素个数也为6
		9		7
		*/

	//注意vector内部三个指针_Myfirst _Mylast _Mysecond
	//pointer _Myfirst;	// pointer to beginning of array
		//_Myfirst与begin（）对应
	//pointer _Mylast;	// pointer to current end of sequence
		//_Mylast与end()对应
	//pointer _Myend;	// pointer to end of array
	
	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;
	system("pause");
}