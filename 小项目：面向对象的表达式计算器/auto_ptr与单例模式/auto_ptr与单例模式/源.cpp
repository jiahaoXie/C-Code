#include <iostream>
#include <memory>
using namespace std;

//����ģʽ �Ǳ�֤һ�����ڳ�����ֻ��һ������ һ��ʵ��
//����ģʽ����ؼ����ڶ����ֹ����
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