//新建一个类 用来实现命令解析
#ifndef _COMMMAND_PARSER_H
#define _COMMMAND_PARSER_H
#include<string>
#include"Parser.h"
class Scnner;//前向声明
class Calc;

class CommandParser
{
	enum ECommand
	{//自己定义一个枚举类型
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
	Calc& calc_;//添加一个变量calc  
	ECommand cmd_;
	std::string cmdName_;
};
#endif//_COMMMAND_PARSER_H
