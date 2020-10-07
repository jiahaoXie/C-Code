//实现PARSER类 其实就是对输入串的一个分析，基于扫描器的基础之上

#ifndef _PARSER_H_  
#define _PARSER_H_  

class Scanner;
class Node;

enum STATUS
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};

class Parser
{
public:
	Parser(Scanner& scanner);
	void Parse();
	Node* Expr();
	Node* Term();
	Node* Factor();
	//表达式：Expressoin； 项：Term；因子：Factor;
	double Calculate() const;
private:
	Scanner& scanner_;
	Node* tree_;
	STATUS status_;
};

#endif // _PARSER_H_  

