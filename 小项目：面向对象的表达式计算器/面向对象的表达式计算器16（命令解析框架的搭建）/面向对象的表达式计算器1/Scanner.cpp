#include "Scanner.h"
#include <cctype>  
#include<iostream>

//Scanner::Scanner(const std::string& buf) : buf_(buf), curPos_(0)
//{//这里是从缓冲区获取数据
//	Accept();
//	isEmpty_ = (token_ == TOKEN_END);
//}
Scanner::Scanner(std::istream& in) : in_(in)/*, curPos_(0)*/
{//这里直接采用输入流获取数据
	Accept();
	isEmpty_ = (token_ == TOKEN_END);
}

bool Scanner::IsEmpty() const
{
	return isEmpty_;
}
bool Scanner::IsDone()const
{
	return token_ == TOKEN_END;
}

bool Scanner::IsCommand() const
{
	return token_ == TOKEN_COMMMAND;
}


double Scanner::Number() const
{
	return number_;
}

std::string  Scanner::GetSymbol() const
{
	return symbol_;
}
EToken Scanner::Token() const
{
	return token_;
}
void  Scanner::ReadChar()
{
	look_ = in_.get();//逐个获取字符
	while (look_ == ' ' || look_ == '\t')
		look_ = in_.get();
	//遇到空格或者\t（无效的字符） 则重新获取新的字符

}


//void Scanner::SkipWhite()
//{
//	while (isspace(buf_[curPos_]))
//		++curPos_;
//}

void Scanner::Accept()
{
	//SkipWhite();
	ReadChar();
	//switch (buf_[curPos_])
	switch (look_)
	{//多条件判断 直接用look_
	case'!':
		token_ = TOKEN_COMMMAND;
		break;
	case '+':
		token_ = TOKEN_PLUS;
		//++curPos_; 
		break;
	case '-':
		token_ = TOKEN_MINUS;
		//++curPos_;
		break;
	case '*':
		token_ = TOKEN_MULTIPLY;
		//++curPos_;
		break;
	case '/':
		token_ = TOKEN_DIVIDE;
		//++curPos_;
		break;
	case '=':
		token_ = TOKEN_ASSIGN;
		//++curPos_;
		break;
	case '(':
		token_ = TOKEN_LPARENTHESIS;
		//++curPos_;
		break;
	case ')':
		token_ = TOKEN_RPARENTHESIS;
		//++curPos_;
		break;
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		token_ = TOKEN_NUMBER;
		//char* p;
		//number_ = strtod(&buf_[curPos_], &p);
		////这里 利用到的是c中的库函数strtod() 直接将字符串转换为浮点型   
		//curPos_ = p - &buf_[0];
		in_.putback(look_);//先归还这个字符，然后提取
		in_ >> number_;//直接提取到number_变量当中
		break;
	case '\0': case '\n': case '\r': case EOF:
		token_ = TOKEN_END;
		break;
	default:
		if (isalpha(look_) || look_ == '_')
		{
			token_ = TOKEN_IDENTIFIER;
			symbol_.erase();
			do
			{
				symbol_ += look_;
				look_ = in_.get();
			} while (isalnum(look_) || look_ == '_');
			in_.putback(look_);
		}
		/*if (isalpha(buf_[curPos_]) || buf_[curPos_] == '_')
		{
			token_ = TOKEN_IDENTIFIER;
			symbol_.erase();
			char ch = buf_[curPos_];
			do
			{
				symbol_ += ch;
				++curPos_;
				ch = buf_[curPos_];
			} while (isalnum(ch) || ch == '_');
		}*/
		else
		 token_ = TOKEN_ERROR;
		  break;
	}
}

void Scanner::AcceptCommand()
{
	ReadChar();//获取字符
	symbol_.erase();//擦除空白字符
	while (!isspace(look_))
	{
		symbol_ += look_;//存入符号表当中
		look_ = in_.get();//接着读取下一个字符

	}
}
