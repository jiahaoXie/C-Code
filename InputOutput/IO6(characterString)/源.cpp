//�ַ�����
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

string doubleToString(double value)
{
	ostringstream oss;
	oss << value;
	//����ostringstream�ַ������������oss ����������������ת��Ϊ�ַ�������

	return oss.str();
}

double stringToDouble(const string& str)
{
	istringstream iss(str);
	double value;
	iss >> value;
	//����istringstream�ַ�������������iss ��������ת��Ϊ����������
	return value;
}
void main()
{	
	//�ַ�������������ʹ��
	//string line;
	//string word;
	//while (getline(cin, line))
	//{//���ȴӱ�׼�����л�ȡһ�����ݸ�line

	//	istringstream iss(line);
	//	//�����ַ�������������iss �õ�line �е�����
	//	while (iss>>word)
	//	{//��iss�е�������ȡ��word����
	//		cout << word << "#";
	//	}
	//	cout << endl;
	//}
	////�����ڿ���̨ windowsϵͳ��ctr+z����

	double value = 66.6666;
	string  str = doubleToString(value);
	cout << str << endl;

	str = "2333.3333";
	value = stringToDouble(str);
	cout << value << endl;


	system("pause");
}