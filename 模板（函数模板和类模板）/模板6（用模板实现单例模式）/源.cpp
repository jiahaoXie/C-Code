//����ģʽ��������һ����ֻ�ܴ���һ������

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
	//Singleton s3(*s1);//��ֹ����������������Ͳ��ǵ���ģʽ

	system("pause");
	return 0;
}