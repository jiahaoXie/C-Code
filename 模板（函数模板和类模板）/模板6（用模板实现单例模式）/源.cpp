//单例模式（程序中一个类只能创建一个对象）

#include <iostream>
#include "Singleton.h"
using namespace std;

class ApplicationImp1
{
public:
	ApplicationImp1() { cout << "ApplicationImp1 ..." << endl; }
	~ApplicationImp1() { cout << "~ApplicationImp1 ..." << endl; }
	void Run() { cout << "Run ..." << endl; }
};

typedef Singleton<ApplicationImp1> Application;

int main(void)
{
	Application::GetInstance().Run();
	Application::GetInstance().Run();
	//Singleton s3(*s1);//禁止拷贝，如果拷贝，就不是单例模式

	system("pause");
	return 0;
}