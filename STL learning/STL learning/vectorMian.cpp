#include<iostream>
#include<vector>
using namespace std;

void main()
{
	vector<int> v;
	//�ڲ��ܹ����ɵ�Ԫ�ظ���[����] capacity() 
	//vector�ڲ�����ŵ�Ԫ�ظ��� size()	    capacity()>=size()
	//һ������£� ����������һ�����ڴ�ռ䣨�������ɸ����Ԫ�أ���
		//��������һ�β���Ԫ�ص�ʱ�򣬾Ͳ������·����ڴ棬��߲����ٶ�.
			//һ������� ����vector��ǰ����������ڴ�ռ�� �����ȡ����50%���ڴ�ռ�
	/*capacity   size
		0		0			��ʼ��������Ϊ0��Ԫ�ظ���ҲΪ0
		1		1			��������֮ǰ��50%����Ϊ0����ŵ�һ��Ԫ������������Ϊ1��Ԫ�ظ���Ϊ1
		2		2			��������ڶ���Ԫ�أ���������֮ǰ��50%��1+1/2=1,����������2��Ԫ�أ�,������Ϊ2��Ԫ�ظ���Ϊ2
		3		3			�������������Ԫ�أ���������֮ǰ��50%��2+ 2 / 2 = 3������Ϊ3��Ԫ�ظ���Ϊ3
		4		4			����������ĸ�Ԫ�أ���������֮ǰ��50%��3+ 3 / 2 = 4������Ϊ4��Ԫ�ظ���Ϊ4
		6		5			������������Ԫ�أ���������֮ǰ��50%��4+ 4 / 2 = 6������Ϊ6��Ԫ�ظ���Ϊ5
		6		6			�������������Ԫ�أ�����Ϊ6������Ҫ���䣩	����Ϊ6��Ԫ�ظ���ҲΪ6
		9		7
		*/

	//ע��vector�ڲ�����ָ��_Myfirst _Mylast _Mysecond
	//pointer _Myfirst;	// pointer to beginning of array
		//_Myfirst��begin������Ӧ
	//pointer _Mylast;	// pointer to current end of sequence
		//_Mylast��end()��Ӧ
	//pointer _Myend;	// pointer to end of array
	
	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;

	v.push_back(1);
	cout << v.capacity() << endl;
	system("pause");
}