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

private:

	ASTNode m_left;
	ASTNode m_right;
	TokenCode m_op;
};
