#include<iostream>
#include<map>
using namespace std;
using std::map;

	

class  MyGreater {		//����Ľṹ��������map�е�Ԫ�ذ�key�Ӵ�С������Ч���
public:
		bool operator()(int left, int right)
	{
		return left > right;
	}
};
int main()
{
	map<int, int, MyGreater> m1;
	map<int, int, MyGreater>::iterator it;
	map<int, int>m2;
	map<int, int>::iterator it2;
	m2[0]=m1[0] = 1;
	m2[1]=m1[1] = 2;
	m2[4]=m1[4] = 5;
	m2[2]=m1[2] = 3;
	m2[3]=m1[3] = 4;	

	//cout << "m1.at(0)=" << m1.at(0) << endl;	//map.at()���� ���Ҿ���ָ����ֵ��Ԫ�ء�
	//cout << "m1.at(2)=" << m1.at(2) << endl;
	//cout << "m1.at(3)=" << m1.at(3) << endl;
	//cout << "m1.at(4)=" << m1.at(4) << endl;
	for (it2 = m2.begin(); it2 != m2.end(); it2++)
		cout << it2->first << ": " << it2->second << endl;
	//Ĭ������� map�ĵ���������keyֵ��С����[less(key)]�����������
	cout << "=============================================";
	for (it = m1.begin(); it != m1.end(); it++)
		cout << it->first << "�� " << it->second << endl;
	

	system("pause");

	
	return 0;
}