//֮ǰ˵��auto_ptr<T>���ܷ���vector��
//��shared_ptr<T>���Է���vector��

#include <boost/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <vector>

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
void main(void)
{
	//vector<auto_ptr<X> > v;//auto_ptr<t>���ܷ���vector��
	//auto_ptr<X> p(new X);//auto_ptr<>���ÿ���ʵ�ֹ��캯������������
	//	//��Ϊauto_ptr<>�г�������û�о���ָ�봦�� �����޷��ı�
		//auto_ptr<>���صĵȺ����������const ��vetor�����Ͳ�ƥ��

	vector<boost::shared_ptr<X> >v;//shared_ptr<t>���Է���vector��
	boost::shared_ptr<X> p(new X);//��Ϊshared_ptr<>���صĵȺ��������const ��vector��ƥ��
	v.push_back(p);
	cout << p.use_count() << endl;

	system("pause");
}