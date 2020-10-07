#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;
void main()
{
	/*ofstream fout;
	fout.open("test,txt");*/
	//文件打开也可以通过构造函数打开
	ofstream fout("test.txt");
	fout.close();
	
	//判断文件创建的几种方法
	//if (fout.is_open())
	//{
	//	cout << "succeed" << endl;
	//}
	//else
	//{
	//	cout << "failed" << endl;
	//}
	//if (fout.good())//流状态是否正常
	//{
	//	cout << "succeed" << endl;
	//}
	//else
	//{
	//	cout << "failed" << endl;
	//}
	//if (fout)
	//{
	//	cout << "succeed" << endl;
	//}
	//else
	//{
	//	cout << "failed" << endl;
	//}
	//if (!fout)
	//{
	//	cout << "failed" << endl;
	//}
	//else
	//{
	//	cout << "succeed" << endl;
	//}
	assert(fout);
	system("pause");
}