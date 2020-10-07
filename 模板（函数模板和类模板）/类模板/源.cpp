//类模板：将类定义中的数据类型参数化
//类模板实际上是函数模板的推广。
//类模板的实例化：用具体的数据类型替换模板的参数以得到具体的类（模板类）
//模板类也可以实例化为对象
//用下列方式创建类模板的实例：
//类名<类型实参表>对象名称；

//main.cpp
#include <iostream>
#include"Stack.h"
#include"Stack2.h"
using namespace std;
void main(void)
{
	//Stack2<int, 10> s;
	Stack<int> s(10);
	s.Push(1);
	s.Push(2);
	s.Push(3);

	while (!s.Empty())
	{
		cout << s.Top() << endl;
		s.Pop();
	}
	system("pause");
}
