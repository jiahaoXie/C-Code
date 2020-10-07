//ɨ����scanner
#ifndef _SCANNER_H_  
#define _SCANNER_H_  
#include <string>  

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
//�Ӽ��˳�
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	//������ ������
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner
{
public:
	//Scanner(const std::string& buf);
	Scanner(std::istream& in);
	void Accept();
	bool IsEmpty() const;
	bool IsDone()const;
	double Number() const;
	EToken Token() const;
	std::string  GetSymbol() const;
private:
	void ReadChar();//���￩��ReadChar() ����SkipWhite()���������ַ�
	int look_;
	//void SkipWhite();
	//const std::string buf_;
	std::istream& in_;
	//unsigned int curPos_;
	EToken token_;
	double number_;
	std::string symbol_;
	bool isEmpty_;
};

#endif // _SCANNER_H_ 

