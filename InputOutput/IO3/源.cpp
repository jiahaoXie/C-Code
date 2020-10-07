#include<iostream>
#include<fstream>
#include<string>

using namespace std;
 
void main()
{
	////第一种文件读写的方式 >> <<
	//ofstream fout("test.txt");//建立一个文本文件
	//fout << "abc" << " " << 200;//插入运算符中插入数据
	//fout.close();

	//ifstream fin("test.txt");//打开一个文本文件
	//string s;
	//int n;
	//fin>>s >> n;//从文件读取数据给相应的变量
	//cout<<"s="<<s<<" n="<<n<<endl;
	////cout << s << " " << n << endl;

	////第二种文件读写的方式 put() get()
	////（这里代码是向文件中写入26个字母）
	//ofstream fout("test2.txt");
	//char ch;
	//for (int i = 0; i < 26; i++)
	//{
	//	ch = 'A' + i;
	//	fout.put(ch);
	//}
	//fout.close();
	//ifstream fin("test2.txt");
	//while (fin.get(ch))
	//{//fin.get(ch)从文件中逐个获取字符 
	////循环跳出的条件是访问到文件最后没有字符为空则跳出
	//	cout << ch;
	//}
	//cout << endl;

	//第三种方式 文本文件方式读取与二进制形式读取（磁盘和内存中默认为二进制 外存文件中为文本形式）
	//如果以文本形式打开文件，写入字符的时候，遇到\n会做转换，遇到\r不做转换
	   //windows平台\n转换为\r\n	
	   //linux平台 则保留不变
	//如果以二进制形式打开文件，写入字符的时候，遇到\n不会做转换（这个就是二者两个模式打开的区别）

	//以文本形式打开文件，也可以写入二进制文件；同样以二进制形式打开文件，也可以写入文本
	//写入的数据是二进制好事文本，与打开方式无关，与写入使用的函数有关
		//要写入二进制数据，应该用write，相应的读操作要用read

	ofstream fout("test3.txt",ios::out|ios::binary);
	//二进制文件读写 文件打开操作时使用枚举常量ios::binary
	//在文件编程中 系统内部默认是一文本文件形式打开的
	fout << "ABC\r\n";
	fout.close();

	system("pause");
}