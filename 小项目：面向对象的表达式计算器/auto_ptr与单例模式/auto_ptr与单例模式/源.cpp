#include <iostream>
#include <memory>
using namespace std;

//单例模式 是保证一个类在程序中只有一个对象 一个实例
//单例模式对象关键在于对象禁止拷贝
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
		if (!instance_.get())//获得裸指针
		{
			instance_ = auto_ptr<Singleton>(new Singleton);
		}

		return instance_.get();//返回原生指针，但是还保留所有权
							  //get()方法与release()方法最大的不同就是在于所有权是否保留 release释放了所有权
	}

	~Singleton()
	{
		cout << "~Singleton ..." << endl;
	}
private:
	Singleton(const Singleton& other);//禁止拷贝
	Singleton& operator=(const Singleton& other);
	//将构造函数声明为私有
	Singleton()
	{
		cout << "Singleton ..." << endl;
	}
	static auto_ptr<Singleton> instance_;
	//裸指针用智能指针来进行管理
};

auto_ptr<Singleton> Singleton::instance_;

void main(void)
{
	//Singleton s1;
	//Singleton s2;

	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	//Singleton s3(*s1);        // 调用拷贝构造函数
	system("pause");
}