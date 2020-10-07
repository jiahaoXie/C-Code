#include "Exception.h"

const char* Exception::what() const throw()
{
	return message_.c_str();
}
const char*  Exception::StackTrace() const throw()//异常发生的栈信息进行回馈
{
	return stackTrace_.c_str();
}
void Exception::FillStackTrace()//栈信息写入
{
	////以下代码适用于linux进行栈回溯
	///在windows系统中无backtrace_这一内置函数
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
