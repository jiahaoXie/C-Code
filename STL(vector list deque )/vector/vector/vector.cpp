#include<iostream>
#include<vector>
#include<algorithm>	//�㷨Ҫ�����㷨��ͷ�ļ�
using namespace std;

typedef vector<int> VINT;
void output(VINT &v)
{
	VINT::iterator it;
	for(it=v.begin();it!=v.end();++it)
		cout<<*it<<" ";
	cout<<endl;
}
void main()
{
	VINT v;
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(11);
	v.push_back(14);
	v.push_back(11);

	output(v);//����ͨ���������������������
	
	/*remove(v.begin(),v.end(),11);
	output(v);*/

	v.erase(remove(v.begin(),v.end(),11),v.end());
	//��ͨ��erase��removeɾ��vector���ض���Ԫ�� 

	//���������õ���������forѭ���е�ɾ��
	//VINT::iterator it;
	//for(it=v.begin();it!=v.end();)
	//{
	//	if(*it==11)
	//		it=v.erase(it);//ɾ����ǰ�±�λ�õ�Ԫ�أ�������һ��Ԫ�ص��±��it
	//	else
	//		++it;
	//}

	//output(v);
	
	//Ҳ��ͨ�������������ʽ���vector�е�Ԫ��
	for(unsigned int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	

	system("pause");
}