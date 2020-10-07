#include<iostream>
using namespace std;
//编写程序 自己宏定义一个sizeof_v sizeof_t

#define sizeof_v(x) (char*)(&x+1)-(char*)(&x)
//宏定义中 两个指针相减 得到的是偏移量（相隔几个元素）
//这里用来计算某个变量占几个字节

#define sizeof_t(t) ((size_t)((t*)0+1))
//这个通过计算偏移量得到一个类型所占的字节

//实现对齐（利用到的是位运算）  这种方法主要利用于内存池（内存块是规则的）
#define ALLGN(v,b) ((v+b-1)&~(b-1))
//b为16时 则为某个数要对齐到16的整数倍（16的整数倍末尾为0000 32的整数倍末尾为00000）
class Empty {

};

void main()
{
	Empty e;
	int n;
	cout<<sizeof_v(e)<<endl;
	cout << sizeof(e) << endl;

	cout<<sizeof_v(n)<<endl;
	cout << sizeof(n) << endl;

	cout << sizeof_t(Empty) << endl;
	cout << sizeof(Empty) << endl;

	cout << sizeof_t(int) << endl;
	cout << sizeof(int) << endl;

	cout << ALLGN(15, 16) << endl;
	cout << ALLGN(0, 16) << endl;
	cout << ALLGN(35, 16) << endl;

	system("pause");

}

