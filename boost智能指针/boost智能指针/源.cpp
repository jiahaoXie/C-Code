//����ָ�뱾��˼�룺
//���Ѷ������������ջ������������newһ���Ѷ����ʱ������������ָ�����ӹܣ�
	//�����������ڹ��캯�����г�ʼ������һ��ָ��ָ��Ѷ��󣩣������������е���delete���ͷŶѶ���
//��������ָ�뱾����һ��ջ�������������������ʱ���Զ���������������
	//�Ӷ�������delete�ͷ��˶Ѷ���


//scoped_ptr<X>����Ȩ����ת�ƣ����ܽ���
#include<boost/scoped_ptr.hpp>
#include <iostream>

using namespace std;

class X
{
public:
	X()
	{
		cout << "X ..." << endl;
	}
	~X()
	{
		cout << "~X ..." << endl;
	}

};
int main(void)
{
	cout << "Entering main ..." << endl;
	{
		boost::scoped_ptr<X> p(new X);
		//scoped_ptr<X>��ʵ����һ�����󣬵����ܵ��ÿ������캯��
	}
	cout << "Exiting main ..." << endl;
	system("pause");

	return 0;
}