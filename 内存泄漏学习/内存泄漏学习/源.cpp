//Windowsƽ̨����Visual Studio �������� C ����ʱ(CRT) ��Ϊ�����ṩ�˼���ʶ���ڴ�й©����Ч������
//ԭ��������£��ڴ����Ҫͨ��CRT������ʱʵ�֣�ֻҪ�ڷ����ڴ���ͷ��ڴ�ʱ�ֱ����ü�¼��
//�������ʱ�Աȷ����ڴ���ͷ��ڴ�ļ�¼�Ϳ���ȷ���ǲ������ڴ�й©

//ͨ������ crtdbg.h���� malloc �� free ����ӳ�䵽���ǵĵ��԰汾��
//�� _malloc_dbg �� _free_dbg�������������������ڴ������ͷš�
//��ӳ��ֻ�ڵ��԰汾�������ж�����_DEBUG���з����� �����汾ʹ����ͨ�� malloc �� free ������
//
//#define ��佫 CRT �Ѻ����Ļ��汾ӳ�䵽��Ӧ�ġ�Debug���汾�� 
//���Ǿ�����Ҫ����䣻�����û�и���䣬�ڴ�й©ת��������������Ϣ�����١�

#define _CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>

#include<iostream>
using namespace std;

//_CrtMemState s1, s2, s3;
//��λ�ڴ�й©����һ�ּ����漰�ڹؼ����Ӧ�ó�����ڴ�״̬�Ŀ��ա� 
//CRT ���ṩһ�ֽṹ���� _CrtMemState�����������洢�ڴ�״̬�Ŀ���

void GetMemory(char *p, int num)
{
	p = (char *)malloc(sizeof(char *)*num);
}

void main()
{
	//_CrtMemCheckpoint(&s1);

	char *str = NULL;
	GetMemory(str,100);
	
	/*_CrtMemCheckpoint(&s2);
	if (_CrtMemDifference(&s3, &s2, &s1))
		_CrtMemDumpStatistics(&s3);*/

	cout << "Memory leak test!" << endl;
	_CrtDumpMemoryLeaks();
	//ͨ���ڳ�����ִ����� 	_CrtDumpMemoryLeaks()��ͨ��Ӧǡ�÷��ڳ����˳�λ��֮ǰ����ת���ڴ�й©��Ϣ��
	
	system("pause");
}