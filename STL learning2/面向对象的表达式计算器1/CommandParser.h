//�½�һ���� ����ʵ���������
#ifndef _COMMMAND_PARSER_H
#define _COMMMAND_PARSER_H
#include<string>
#include"Parser.h"
class Scnner;//ǰ������
class Calc;

class CommandParser
{
	enum ECommand
	{//�Լ�����һ��ö������
		CMD_HELP,
		CMD_QUIT,
		CMD_VAR,
		CMD_FUN,
		CMD_LOAD,
		CMD_SAVE,
		CMD_ERROR
	};
public:
	CommandParser(Scanner& scanner, Calc& calc);
	STATUS Execute();
private:
	void Help() const;
	void ListVar() const;
	void ListFun() const;
	STATUS Load(const std::string& fileName);
	STATUS Save(const std::string& fileName);
	Scanner& scanner_;
	Calc& calc_;//���һ������calc  
	ECommand cmd_;
	std::string cmdName_;
};
#endif//_COMMMAND_PARSER_H
