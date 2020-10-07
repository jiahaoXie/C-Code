#include "Parser.h"  
#include "Scanner.h"  
#include "Node.h"  
#include"Calc.h"
#include <cassert>  
#include <iostream> 


Parser::Parser(Scanner& scanner, Calc& calc)
	:scanner_(scanner),calc_(calc), tree_(0),status_(STATUS_OK)
{
}

STATUS Parser::Parse()
{
	tree_ = Expr();
	if (!scanner_.IsDone())
	{
		status_ = STATUS_ERROR;
	}
	return status_;
}

//���ʽ��Expressoin��
Node* Parser::Expr()
{
	Node* node = Term();
	EToken token = scanner_.Token();
	//if (token == TOKEN_PLUS)
	//{
	//	//Accept����˼->ɨ����һ����Ԫ  
	//	scanner_.Accept();
	//	Node* nodeRight = Expr();
	//	node = new AddNode(node, nodeRight);
	//}
	//else if (token == TOKEN_MINUS)
	//{
	//	scanner_.Accept();
	//	Node* nodeRight = Expr();
	//	node = new SubNode(node, nodeRight);
	//}
	if (token == TOKEN_PLUS || token == TOKEN_MINUS)
	{
		// Expr := Term { ('+' | '-') Term }  
		MultipleNode* multipleNode = new SumNode(node);
		do
		{
			scanner_.Accept();
			Node* nextNode = Term();
			multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));
			token = scanner_.Token();
		} while (token == TOKEN_PLUS || token == TOKEN_MINUS);
		node = multipleNode;
	}
	else if (token == TOKEN_ASSIGN)
	{
		// Expr := Term = Expr  
		scanner_.Accept();
		Node* nodeRight = Expr();
		if (node->IsLvalue())
		{
			node = new AssignNode(node, nodeRight);
		}
		else
		{
			status_ = STATUS_ERROR;
			std::cout << "The left-hand side of an assignment must be a variable" << std::endl;
			// Todo �׳��쳣  
		}
	}
	return node;
}

//�Term��
Node* Parser::Term()
{
	Node* node = Factor();
	EToken token = scanner_.Token();
	/*if (token == TOKEN_MULTIPLY)
	{
		scanner_.Accept();
		Node* nodeRight = Term();
		node = new MultiplyNode(node, nodeRight);
	}
	else if (token == TOKEN_DIVIDE)
	{
		scanner_.Accept();
		Node* nodeRight = Term();
		node = new DivideNode(node, nodeRight);
	}*/
	if (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
	{
		// Term := Factor { ('*' | '/') Factor }  
		MultipleNode* multipleNode = new ProductNode(node);
		do
		{
			scanner_.Accept();
			Node* nextNode = Factor();
			multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
			token = scanner_.Token();
		} while (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE);
		node = multipleNode;
	}
	return node;
}

//���ӣ�Factor
Node* Parser::Factor()
{
	Node* node = 0;
	EToken token = scanner_.Token();
	if (token == TOKEN_LPARENTHESIS)
	{
		scanner_.Accept();      // accept '('  
		node = Expr();
		if (scanner_.Token() == TOKEN_RPARENTHESIS)
		{
			scanner_.Accept();  // accept ')'  
		}
		else
		{
			status_ = STATUS_ERROR;
			// Todo:�׳��쳣  
			std::cout << "missing parenthesis" << std::endl;
			node = 0;
		}
	}
	else if (token == TOKEN_NUMBER)
	{
		node = new NumberNode(scanner_.Number());
		scanner_.Accept();
	}
	else if (token == TOKEN_IDENTIFIER)
	{
		std::string symbol = scanner_.GetSymbol();
		unsigned int id = calc_.FindSymbol(symbol);
		scanner_.Accept();
		if (id == SymbolTable::IDNOTFOUND)
		{
			id = calc_.AddSymbol(symbol);
		}
		node = new VariableNode(id, calc_.GetStorage());
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();      // accept minus  
		node = new UMinusNode(Factor());
	}

	else
	{
		status_ = STATUS_ERROR;
		// Todo:�׳��쳣  
		std::cout << "not a valid expression" << std::endl;
		node = 0;
	}
	return node;
}

double Parser::Calculate() const
{
	assert(tree_ != 0);
	return tree_->Calc();
}
