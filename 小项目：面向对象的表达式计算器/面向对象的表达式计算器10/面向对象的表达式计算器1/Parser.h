//ʵ��PARSER�� ��ʵ���Ƕ����봮��һ������������ɨ�����Ļ���֮��
//Parser������
#ifndef _PARSER_H_  
#define _PARSER_H_  

class Scanner;
class Node;
class Calc;

enum STATUS
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};

//class Parser
//{
//public:
//	Parser(Scanner& scanner);
//	void Parse();
//	Node* Expr();
//	Node* Term();
//	Node* Factor();
//	//���ʽ��Expressoin�� �Term�����ӣ�Factor;
//	double Calculate() const;
//private:
//	Scanner& scanner_;
//	Node* tree_;
//	STATUS status_;
//};
class Parser
{
public:
	Parser(Scanner& scanner, Calc& calc);
	STATUS Parse();
	Node* Expr();
	Node* Term();
	Node* Factor();
	double Calculate() const;
private:
	Scanner& scanner_;
	Calc& calc_;//���һ������calc  
	Node* tree_;
	STATUS status_;
};

#endif // _PARSER_H_  

