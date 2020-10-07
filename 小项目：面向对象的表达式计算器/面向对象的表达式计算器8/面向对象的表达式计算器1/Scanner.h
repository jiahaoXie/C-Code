//É¨ÃèÆ÷scanner
#ifndef _SCANNER_H_  
#define _SCANNER_H_  
#include <string>  

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
//¼Ó¼õ³Ë³ý
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	//×óÀ¨ºÅ ÓÒÀ¨ºÅ
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner
{
public:
	Scanner(const std::string& buf);
	void Accept();
	double Number() const;
	EToken Token() const;
	std::string  GetSymbol() const;
private:
	void SkipWhite();
	const std::string buf_;
	unsigned int curPos_;
	EToken token_;
	double number_;
	std::string symbol_;
};

#endif // _SCANNER_H_ 

