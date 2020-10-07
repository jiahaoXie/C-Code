#include "Exception.h"

const char* Exception::what() const throw()
{
	return message_.c_str();
}
const char*  Exception::StackTrace() const throw()//�쳣������ջ��Ϣ���л���
{
	return stackTrace_.c_str();
}
void Exception::FillStackTrace()//ջ��Ϣд��
{
	////���´���������linux����ջ����
	///��windowsϵͳ����backtrace_��һ���ú���
	//const int len = 200;
	//void* buffer[len];
	//int nptrs = ::backtrace_symbols(buffer,nptrs);
	//if (strings)
	//{
	//	for (int i = 0; i < nptrs; i++)
	//	{
	//		stackTrace_.append(strings[i]);
	//		stackTrace_.push_back('\n');
	//	}
	//	free(strings);
	//}
}
