//ʵ��PARSER�� ��ʵ���Ƕ����봮��һ������������ɨ�����Ļ���֮��

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
	//���ʽ��Expressoin�� �Term�����ӣ�Factor;
	double Calculate() const;
private:
	Scanner& scanner_;
	Node* tree_;
	STATUS status_;
};

#endif // _PARSER_H_  

