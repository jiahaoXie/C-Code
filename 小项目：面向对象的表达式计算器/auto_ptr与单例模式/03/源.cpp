#include<iostream>
using namespace std;
//��д���� �Լ��궨��һ��sizeof_v sizeof_t

#define sizeof_v(x) (char*)(&x+1)-(char*)(&x)
//�궨���� ����ָ����� �õ�����ƫ�������������Ԫ�أ�
//������������ĳ������ռ�����ֽ�

#define sizeof_t(t) ((size_t)((t*)0+1))
//���ͨ������ƫ�����õ�һ��������ռ���ֽ�

//ʵ�ֶ��루���õ�����λ���㣩  ���ַ�����Ҫ�������ڴ�أ��ڴ���ǹ���ģ�
#define ALLGN(v,b) ((v+b-1)&~(b-1))
//bΪ16ʱ ��Ϊĳ����Ҫ���뵽16����������16��������ĩβΪ0000 32��������ĩβΪ00000��
class Empty {

};

void main()
{
	Empty e;
	int n;
	cout<<sizeof_v(e)<<endl;
	cout << sizeof(e) << endl;

	cout<<sizeof_v(n)<<endl;
	cout << sizeof(n) << endl;

	cout << sizeof_t(Empty) << endl;
	cout << sizeof(Empty) << endl;

	cout << sizeof_t(int) << endl;
	cout << sizeof(int) << endl;

	cout << ALLGN(15, 16) << endl;
	cout << ALLGN(0, 16) << endl;
	cout << ALLGN(35, 16) << endl;

	system("pause");

}

