#include <iostream>
using namespace std;

template <typename T>
class MyClass
{
private:
	typename T::SubType * ptr_;
	//�ؼ���typename ���������Ǵ���SubType��һ������
public:


};
class Test {
public:
	typedef int SubType;
};
int main(void)
{
	MyClass<Test> mc;
	//������ģ��MyClass����ָ������

	system("pause");
	return 0;
}