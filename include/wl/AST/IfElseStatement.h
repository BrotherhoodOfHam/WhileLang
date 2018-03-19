/*
	If Statement:

	<if-statement> ::= if <boolean-expression> then <command-list> else <command-list> fi
*/

#pragma once

#include "wl/AST.h"

#include "ExpressionBuilder.h"
#include "CommandList.h"

class IfElseStatement : public AST
{
public:

	IfElseStatement(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_IF);

		m_condition.swap(ExpressionBuilder::construct(tokens));

		tokens.nextAssert(TOKEN_THEN);

		m_true = CommandList(tokens);

		tokens.nextAssert(TOKEN_ELSE);

		m_false = CommandList(tokens);

		tokens.nextAssert(TOKEN_FI);
	}

	void evaluate(Context& ctx) override
	{

	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "IF" << std::endl;

		indent(out, i + 1);
		out << "CONDITION" << std::endl;
		m_condition->print(out, i + 2);

		indent(out, i + 1);
		out << "THEN" << std::endl;
		m_true.print(out, i + 2);

		indent(out, i + 1);
		out << "ELSE" << std::endl;
		m_false.print(out, i + 2);
	}

private:

	ASTNode m_condition;
	CommandList m_true;
	CommandList m_false;
};
