//表达式计算器增加异常处理功能

#ifndef _EXCEPTION_H
#define _EXCEPTION_H
  
#include<exception>	//增加异常处理的头文件
#include<string>

class Exception:public std::exception
{
public:
	explicit Exception(const char* message)
		:message_(message)
	{
		FillStackTrace();//栈信息写入
	}
	explicit Exception(const std::string& message)
		:message_(message)
	{
		FillStackTrace();//栈信息写入
	}
	virtual ~Exception()throw()//函数后面加上 throw() 表示不抛出异常
	{

	}
	virtual const char* what() const throw();
	const char* StackTrace() const throw();//异常发生的栈信息进行回馈
	
private:
	void FillStackTrace();//栈信息写入
	std::string message_;
	std::string stackTrace_;
};
class SyntaxError :public Exception
{
public:	
	explicit SyntaxError(const char* message)
		: Exception(message)
	{

	}
	explicit SyntaxError(const std::string& message)
		: Exception(message)
	{

	}
	virtual ~SyntaxError() throw()//函数后面加上 throw() 表示不抛出异常
	{

	}
};
class FileStreamError :public Exception
{
public:
	explicit FileStreamError(const char* message)
		: Exception(message)
	{

	}
	explicit FileStreamError(const std::string& message)
		: Exception(message)
	{

	}
	virtual ~FileStreamError() throw()//函数后面加上 throw() 表示不抛出异常
	{

	}
};


#endif //_EXCEPTION_H
