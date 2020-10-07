//���ʽ�����������쳣������

#ifndef _EXCEPTION_H
#define _EXCEPTION_H
  
#include<exception>	//�����쳣�����ͷ�ļ�
#include<string>

class Exception:public std::exception
{
public:
	explicit Exception(const char* message)
		:message_(message)
	{
		FillStackTrace();//ջ��Ϣд��
	}
	explicit Exception(const std::string& message)
		:message_(message)
	{
		FillStackTrace();//ջ��Ϣд��
	}
	virtual ~Exception()throw()//����������� throw() ��ʾ���׳��쳣
	{

	}
	virtual const char* what() const throw();
	const char* StackTrace() const throw();//�쳣������ջ��Ϣ���л���
	
private:
	void FillStackTrace();//ջ��Ϣд��
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
	virtual ~SyntaxError() throw()//����������� throw() ��ʾ���׳��쳣
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
	virtual ~FileStreamError() throw()//����������� throw() ��ʾ���׳��쳣
	{

	}
};


#endif //_EXCEPTION_H
