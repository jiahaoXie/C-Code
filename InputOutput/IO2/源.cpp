#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;
void main()
{
	/*ofstream fout;
	fout.open("test,txt");*/
	//�ļ���Ҳ����ͨ�����캯����
	ofstream fout("test.txt");
	fout.close();
	
	//�ж��ļ������ļ��ַ���
	//if (fout.is_open())
	//{
	//	cout << "succeed" << endl;
	//}
	//else
	//{
	//	cout << "failed" << endl;
	//}
	//if (fout.good())//��״̬�Ƿ�����
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