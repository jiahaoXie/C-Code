#include<cassert>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main()
{
	//ifstream fin("test7.txt");
	//assert(fin);
	//fin.seekg(2);
	////文件位置从第二个下标开始
	//char ch;
	//fin.get(ch);//得到下标第二个的字符
	//cout<<ch<<endl;

	//fin.seekg(-1, ios::end);//得到文件中自后一个字符
	//fin.get(ch);
	//cout << ch << endl;

	////还可以用来得到文件的大小
	//fin.seekg(0,ios::end);
	//streampos pos = fin.tellg();//tellg得到当前指针的位置
	//cout << pos << endl;

	ifstream in("test8.txt");
	assert(in);
	in.seekg(0, ios::end);       //基地址为文件结束处，偏移地址为0，于是指针定位在文件结束处
	streampos sp = in.tellg(); //sp为定位指针，因为它在文件结束处，所以也就是文件的大小
	cout << "filesize:" << endl << sp << endl;

	in.seekg(-sp / 3, ios::end); //基地址为文件末，偏移地址为负，于是向前移动sp/3个字节
	streampos sp2 = in.tellg();
	cout << "from file topoint:" << endl << sp2 << endl;

	in.seekg(0, ios::beg);        //基地址为文件头，偏移量为0，于是定位在文件头
	cout << in.rdbuf();            //从头读出文件内容
	in.seekg(sp2);

	cout << in.rdbuf() << endl; //从sp2开始读出文件内容

	system("pause");
}