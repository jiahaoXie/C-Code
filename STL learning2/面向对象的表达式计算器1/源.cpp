///*********************************************************************
///�������������ʽ����������С��Ŀ����Ҫ������ʵ�� 
//1.�ܹ�������ͨ���ʽ
//2.֧�ֱ���
//3.֧�ֺ���
//4.֧�ֱ�������ͺ���
//**********************************************************************/




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
#include"CommandParser.h"
using namespace std;
void main()
{
	Calc calc;
	STATUS status= STATUS_OK;
	do
	{
		cout << ">";
		//string buf;
		//getline(cin, buf);//1���ӿ���̨�ϻ�ȡһ�����ݸ�buf
		//		//cout << buf << endl;
		//Scanner scanner(buf);//2������õ��⴮���ݴ��ݵ�scanner����ȥ
		Scanner scanner(std::cin);//��������ǽ�����1 2����������װ��scanner�� ��Ӧ��Scanner���еĹ��캯��ҲҪ�����ı�
		//ɨ����ɨ���ַ�
		if (!scanner.IsEmpty())
		{
			if (scanner.IsCommand())
			{//�����ǰɨ�赽��̾�ţ����ʾΪ�������
				CommandParser parser(scanner,calc);
				status = parser.Execute();//ִ���������

			}
			else
			{//����Ϊ���ʽ
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
					status = STATUS_QUIT;

					cout << se.what() << endl;
				}
				catch (Exception& e)//�����������͵��쳣 �û���ĳ�Ա����������
				{
					status = STATUS_QUIT;

					cout << e.what() << endl;
				}
				catch (std::bad_alloc& c)
				{//�ڴ����ʧ��
					status = STATUS_QUIT;
					cout << "Internal error" << endl;
				}
				catch (...)
				{
					status = STATUS_QUIT;

					cout << "Internl Error!" << endl;
				}
			}
		}
			
		else
		{
			status = STATUS_QUIT;
			std::cout << "Expression is empty!" << std::endl;
		}
	} while (status!= STATUS_QUIT);
	system("pause");
}

