//������������ĸ�ʽ�� ʹ��ϵͳͷ�ļ�<iomanip>

#include<iostream>
#include<iomanip>

using namespace std;
//����ͨ�������ӷ�ʽ���и�ʽ����� ��ȻҲ�����Գ�Ա������ʽ���и�ʽ�����
//��ȿ��� ������� ������ ���ȿ��� �������
void main()
{
	int n = 100;
	double d = 12.345;
	double d2 = 234.4567;
	cout << "=============��ȿ���==================" << endl;
	//��ȿ������õ�setw()���� ����setw(10)��ʾÿ������ռ10λ
	cout << n << "#" << endl;
	cout << setw(10) << n << "#" << endl;
	//ע�⣺��ȿ��Ʋ���Ӱ����һ�����

	cout << "=============�������==================" << endl;
	//ϵͳ�ڲ�Ĭ������� Ϊ�Ҷ���
	cout << setw(10) << setiosflags(ios::left) << n << "#" << endl;
	//setiosflags(ios::left)��������Ϊ�����
	cout << setw(10) << resetiosflags(ios::left) << n << "#" << endl;
	//resetiosflags(ios::left)���������Ĳ��� ��ϵͳ�ָ�Ĭ��ֵ�Ҷ���
	//ע�⣺������ƻ�Ӱ����һ�����

	cout << "=============������==================" << endl;
	cout << setw(10) <<setfill('!') << n << "#" << endl;
	//������ ϵͳĬ��Ϊ�ո� ��䣬����setfill('!')����Ϊ��̾�����
	//ע�⣺�����ƻ�Ӱ����һ�����

	cout << "=============���ȿ���==================" << endl;
	cout << setprecision(4) << d << endl;
	cout << setprecision(6) << d2 << endl;
	//setprecision(n)�����ʾ������Ч����Ϊnλ ���

	//��Ҫ���ó�С�����λ��������������cout << setiosflags(ios::fixed);
	cout << setiosflags(ios::fixed);
	cout << setprecision(4) << d << endl;
	cout << setprecision(6) << d2 << endl;

	cout << "=============�������==================" << endl;
	cout << setiosflags(ios::showbase);//ios::showbase��ʾ���ʱ ��ʾ���Ƶ�ǰ׺
	cout << n << endl;
	cout << oct << n << endl;
	cout << hex << n << endl;

	system("pause");
}