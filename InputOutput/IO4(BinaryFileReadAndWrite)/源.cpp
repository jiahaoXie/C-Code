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
{	//1.文本形式(或者二进制形式)打开创建一个文件，用二进制进行读写
	//Test test = {100,200};
	////ofstream fout("test4.txt");//以文本形式打开（创建）一个文件
	//ofstream fout("test4.txt",ios::out|ios::binary);//以二进制的形式
	//fout.write(reinterpret_cast<char*>(&test),sizeof(Test));
	////以二进制的形式向文件中写入sizeof(Test)(8个字节)的数据
	//fout.close();

	//Test test2;
	////ifstream fin("test4.txt");
	//ifstream fin("test4.txt", ios::in | ios::binary);//以二进制的形式
	//fin.read(reinterpret_cast<char*>(&test2), sizeof(Test));
	////以二进制的形式从文件中读入sizeof(Test)数据
	//cout << test2.a << "  " << test2.b << endl;

	////2.二进制形式打开创建文件，，文本形式进行读写
	//ofstream fout("test5.txt",ios::out|ios::binary);
	//fout << "abc" << 200;
	////插入运算符<<是以文本形式写入数据的
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
	//二进制进行对文件的写入，当结构体中有string 类型的数据。
							//应该把结构体中的成员变量逐个进行读写。而不是将结构体对象进行直接读写
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
	ms2.b.resize(len);//调整字符串大小
	fin.read(&ms2.b[0],len);
	fin.read((char*)&len,sizeof(int));
	ms2.c.resize(len);
	fin.read(&ms2.c[0], len);
	cout << ms2.a << " " << ms2.b << " " << ms2.c << endl;
	fin.close();
	system("pause");

}