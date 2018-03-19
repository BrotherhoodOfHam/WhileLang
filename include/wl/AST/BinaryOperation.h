/*
	Operation:
	
	<operation> ::= <expression> <operator> <expression>
*/

#pragma once

#include "wl/AST.h"

class BinaryOperation : public AST
{
public:

	static bool hasNext(Tokenizer& tokens)
	{
		return tokens.isNext(TOKEN_OP_PLUS)
			|| tokens.isNext(TOKEN_OP_MINUS)
			|| tokens.isNext(TOKEN_OP_MOD)
			|| tokens.isNext(TOKEN_OP_DIV)
			|| tokens.isNext(TOKEN_OP_MUL)
			|| tokens.isNext(TOKEN_OP_GT)
			|| tokens.isNext(TOKEN_OP_LT)
			|| tokens.isNext(TOKEN_OP_GE)
			|| tokens.isNext(TOKEN_OP_LE)
			|| tokens.isNext(TOKEN_OP_NEQ)
			|| tokens.isNext(TOKEN_OP_EQ);
	}

	BinaryOperation(ASTNode left, TokenCode op, ASTNode right) :
		m_left(std::move(left)), m_op(op), m_right(std::move(right))
	{}

	void evaluate(Context& ctx) override
	{

	}

	void print(std::ostream& out, uint32_t i) override
	{
		std::string symbol;

		switch (m_op)
		{
			case TOKEN_OP_PLUS: symbol = "+"; break;
			case TOKEN_OP_MINUS: symbol = "-"; break;
			case TOKEN_OP_MOD: symbol = "%"; break;
			case TOKEN_OP_DIV: symbol = "/"; break;
			case TOKEN_OP_MUL: symbol = "*"; break;
			case TOKEN_OP_GT: symbol = ">"; break;
			case TOKEN_OP_LT: symbol = "<"; break;
			case TOKEN_OP_GE: symbol = ">="; break;
			case TOKEN_OP_LE: symbol = "<="; break;
			case TOKEN_OP_NEQ: symbol = "!="; break;
			case TOKEN_OP_EQ: symbol = "=="; break;
		}

		indent(out, i);
		out << "OPERATION " << symbol << std::endl;
		m_left->print(out, i + 1);
		m_right->print(out, i + 1);
	}

private:

	ASTNode m_left;
	ASTNode m_right;
	TokenCode m_op;
};
