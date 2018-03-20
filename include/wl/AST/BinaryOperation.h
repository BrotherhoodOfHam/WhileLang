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
		m_left(std::move(left)), m_right(std::move(right))
	{
		switch (op)
		{
		case TOKEN_OP_PLUS:  m_op = Operator::ADD; break;
		case TOKEN_OP_MINUS: m_op = Operator::SUB; break;
		case TOKEN_OP_MOD:   m_op = Operator::MOD; break;
		case TOKEN_OP_DIV:   m_op = Operator::DIV; break;
		case TOKEN_OP_MUL:   m_op = Operator::MUL; break;
		case TOKEN_OP_GT:    m_op = Operator::GT;  break;
		case TOKEN_OP_LT:    m_op = Operator::LT;  break;
		case TOKEN_OP_GE:    m_op = Operator::GE;  break;
		case TOKEN_OP_LE:    m_op = Operator::LE;  break;
		case TOKEN_OP_NEQ:   m_op = Operator::NEQ; break;
		case TOKEN_OP_EQ:    m_op = Operator::EQ;  break;
		}
	}

	void evaluate(Context& ctx) override
	{
		m_left->evaluate(ctx);
		const Context::Variable left = ctx.loadValue();

		m_right->evaluate(ctx);
		const Context::Variable right = ctx.loadValue();

		ctx.storeValue(ctx.binaryOperation(left, m_op, right));
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "OPERATION " << Context::operatorToString(m_op) << std::endl;
		m_left->print(out, i + 1);
		m_right->print(out, i + 1);
	}

private:

	ASTNode m_left;
	ASTNode m_right;
	Operator m_op;
};
