#include<iostream>
#include<memory>
using namespace std;

class Noncopyable {
protected:
	Noncopyable() {}
	~Noncopyable() {}
private:
	Noncopyable(const Noncopyable&);
	const Noncopyable& operator=(const Noncopyable&);
};

class  Parent :private Noncopyable
{//����˽�м̳и���
	//���������޹��캯�� �����ʽ���ø���Ĺ��캯��
public:
	Parent():Noncopyable() {}
	Parent(const Parent&):Noncopyable() {}
	~Parent() {}
	
};



void main()
{
	Parent p1;
	Parent p2(p1);
	//��һ��� ����ִ��ʧ�ܣ���ΪҪ���ÿ������캯�����������в�δ����

	
	system("pause");
}
 