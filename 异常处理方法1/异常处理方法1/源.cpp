////c������ ����setjump longjump���г���ת��ȫ����ת��
////������׳���������������������Ƚ�Զ�ĵط�
//
//#include <stdio.h>
//#include <setjmp.h>
//#include<iostream>
//jmp_buf buf;//����һ��ջ����
//
//double Divide(double a, double b)
//{
//	if (b == 0.0)
//	{
//		longjmp(buf, 1); //throw longjmp���г���ת�� ret = setjmp(buf)�����ѷ���ֵ1����ret
//	}
//	else
//		return  a / b;
//}
//
//void main()
//{
//	int ret;
//	ret = setjmp(buf);//�����������л�����buf�������У����쳣ʱ����ת���˷���ֵΪlongjmp(buf,1)�е�1
//	if (ret == 0)    //try
//	{
//		printf("divisiong....");
//		printf("a/b = %f\n", Divide(5.0, 0.0));
//	}
//	else if (ret == 1) //catch 
//	{
//		printf("divisiong by zero\n");
//	}
//	
//	system("pause");
//	
//}


//C++�쳣���� ����try..catch..finally
#include <iostream>
using namespace std;

double Divide(double a, double b)
{
	if (b == 0.0)
	{
		throw 1;
	}
	else
		return  a / b;
}

void main(void)
{
	try
	{
		cout << "division ..." << endl;
		
		cout << Divide(5.0, 1.0) << endl;
		cout << Divide(5.0, 0.0) << endl;
		cout << Divide(5.0, 2.0) << endl;
				//try...catch..����� ֻҪ����һ��������� �����ͻ�ִ��ֹͣ��������ִ�У�תȥ�쳣����
	}
	catch (int)//���������쳣
	{
		cout << "divisiong by zero\n" << endl;
	}
	system("pause");
}