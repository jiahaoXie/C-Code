#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Test
{
	int a;
	int b;
};
struct MyStruct
{
	int a;
	string b;
	string c;
};
void main()
{	//1.�ı���ʽ(���߶�������ʽ)�򿪴���һ���ļ����ö����ƽ��ж�д
	//Test test = {100,200};
	////ofstream fout("test4.txt");//���ı���ʽ�򿪣�������һ���ļ�
	//ofstream fout("test4.txt",ios::out|ios::binary);//�Զ����Ƶ���ʽ
	//fout.write(reinterpret_cast<char*>(&test),sizeof(Test));
	////�Զ����Ƶ���ʽ���ļ���д��sizeof(Test)(8���ֽ�)������
	//fout.close();

	//Test test2;
	////ifstream fin("test4.txt");
	//ifstream fin("test4.txt", ios::in | ios::binary);//�Զ����Ƶ���ʽ
	//fin.read(reinterpret_cast<char*>(&test2), sizeof(Test));
	////�Զ����Ƶ���ʽ���ļ��ж���sizeof(Test)����
	//cout << test2.a << "  " << test2.b << endl;

	////2.��������ʽ�򿪴����ļ������ı���ʽ���ж�д
	//ofstream fout("test5.txt",ios::out|ios::binary);
	//fout << "abc" << 200;
	////���������<<�����ı���ʽд�����ݵ�
	//fout.close();
	//ifstream fin("test5.txt");
	//string s;
	//fin >> s;
	//cout << s << endl;

	MyStruct ms;
	ms.a = 100;
	ms.b = "xxx";
	ms.c = "yyy";
	ofstream fout("test6.txt",ios::out|ios::binary);
	//fout.write((char*)&ms,sizeof(MyStruct));
	//�����ƽ��ж��ļ���д�룬���ṹ������string ���͵����ݡ�
							//Ӧ�ðѽṹ���еĳ�Ա����������ж�д�������ǽ��ṹ��������ֱ�Ӷ�д
	fout.write((char*)&ms.a,sizeof(int));
	int len;
	len = ms.b.length();
	fout.write((char*)&len,sizeof(int));
	fout.write(ms.b.data(), ms.b.length());
	len = ms.c.length();
	fout.write((char*)&len, sizeof(int));
	fout.write(ms.c.data(), ms.c.length());
	fout.close();

	ifstream fin("test6.txt",ios::in|ios::binary);
	MyStruct ms2;
	fin.read((char*)&ms2.a,sizeof(int));
	fin.read((char*)&len,sizeof(int));
	ms2.b.resize(len);//�����ַ�����С
	fin.read(&ms2.b[0],len);
	fin.read((char*)&len,sizeof(int));
	ms2.c.resize(len);
	fin.read(&ms2.c[0], len);
	cout << ms2.a << " " << ms2.b << " " << ms2.c << endl;
	fin.close();
	system("pause");

}