////���ʽ������11�������ܣ�  �����쳣������


//�ñ��ʽ������֧�ֱ�����ֵ
//FunctionTableʵ��
//�ñ��ʽ������֧�ֺ�������
//����һ���õĿ�ѧ�����������ú����Ǳ���ġ������������ܼ���ƽ���������������Ǻ����ȵȡ�
//�������Ҫ�ý�����ʶ����Щ����, �������ʵ�����ѧ�⺯����
//FunctionTableʵ��

#include <iostream>
#include<string>
#include"Scanner.h"
#include"Parser.h"
#include"Calc.h"
#include "Exception.h"
using namespace std;
void main()
{
	Calc calc;
	STATUS status= STATUS_OK;
	do
	{
		cout << ">";
		string buf;
		getline(cin, buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		if (!scanner.IsEmpty())
		{
			Parser parser(scanner, calc);
			try 
			{
				status = parser.Parse();//�����ɻ�����쳣
				//��Ϊ����status��ֵ 
				//���Ǻ������������г����쳣���̶������쳣�������ܻ�������do..while()ѭ������
				//����status��Ҫ��mian�����и���ֵ STATUS status = STATUS_OK;
				
				if (status == STATUS_OK)
				{
					std::cout << parser.Calculate() << std::endl;
				}

			}
			catch (SyntaxError& se)//�����﷨�쳣
			{
				cout << se.what() << endl;
			}
			catch (Exception& e)//�����������͵��쳣 �û���ĳ�Ա����������
			{
				cout << e.what() << endl;
			}
			catch (...)
			{
				cout << "Internl Error!" << endl;
			}
		
		}
		else
		{
			std::cout << "Expression is empty!" << std::endl;
		}
	} while (status!= STATUS_QUIT);
	system("pause");
}

