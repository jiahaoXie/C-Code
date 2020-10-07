#include<iostream>
using namespace std;
/*
class Q {
	int x, y;
public:
	Q(int a = 0, int b = 0)
	{
		cout << "�����˹��캯��" << endl;
		x = a; y = b;
	}
	void P()
	{
		cout << x << "\t" << y << endl;
	}
	~Q()
	{
		cout << "��������������" << endl;
	}
};

void main()
{
	Q q(50, 100);
	q.P();
	cout << "�˳���������" << endl;
//	system("pause");
}*/

#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		/*if (instacne_ == NULL)
		{
		instacne_ = new Singleton;
		}
		return instacne_;*/
		if (!instance_.get())//�����ָ��
		{
			instance_ = auto_ptr<Singleton>(new Singleton);
		}

		return instance_.get();//����ԭ��ָ�룬���ǻ���������Ȩ
							  //get()������release()�������Ĳ�ͬ������������Ȩ�Ƿ��� release�ͷ�������Ȩ
	}

	~Singleton()
	{
		cout << "~Singleton ..." << endl;
	}
private:
	Singleton(const Singleton& other);//��ֹ����
	Singleton& operator=(const Singleton& other);
	//�����캯������Ϊ˽��
	Singleton()
	{
		cout << "Singleton ..." << endl;
	}
	static auto_ptr<Singleton> instance_;
	//��ָ��������ָ�������й���
};

auto_ptr<Singleton> Singleton::instance_;

void main(void)
{
	//Singleton s1;
	//Singleton s2;

	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	//Singleton s3(*s1);        // ���ÿ������캯��
	system("pause");
}