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
	////�ļ�λ�ôӵڶ����±꿪ʼ
	//char ch;
	//fin.get(ch);//�õ��±�ڶ������ַ�
	//cout<<ch<<endl;

	//fin.seekg(-1, ios::end);//�õ��ļ����Ժ�һ���ַ�
	//fin.get(ch);
	//cout << ch << endl;

	////�����������õ��ļ��Ĵ�С
	//fin.seekg(0,ios::end);
	//streampos pos = fin.tellg();//tellg�õ���ǰָ���λ��
	//cout << pos << endl;

	ifstream in("test8.txt");
	assert(in);
	in.seekg(0, ios::end);       //����ַΪ�ļ���������ƫ�Ƶ�ַΪ0������ָ�붨λ���ļ�������
	streampos sp = in.tellg(); //spΪ��λָ�룬��Ϊ�����ļ�������������Ҳ�����ļ��Ĵ�С
	cout << "filesize:" << endl << sp << endl;

	in.seekg(-sp / 3, ios::end); //����ַΪ�ļ�ĩ��ƫ�Ƶ�ַΪ����������ǰ�ƶ�sp/3���ֽ�
	streampos sp2 = in.tellg();
	cout << "from file topoint:" << endl << sp2 << endl;

	in.seekg(0, ios::beg);        //����ַΪ�ļ�ͷ��ƫ����Ϊ0�����Ƕ�λ���ļ�ͷ
	cout << in.rdbuf();            //��ͷ�����ļ�����
	in.seekg(sp2);

	cout << in.rdbuf() << endl; //��sp2��ʼ�����ļ�����

	system("pause");
}