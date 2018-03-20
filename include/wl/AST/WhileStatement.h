/*
	While Statement:

	<while-statement> ::= while <boolean-expression> do <command-list> od
*/

#pragma once

#include "wl/AST.h"

#include "ExpressionBuilder.h"

class WhileStatement : public AST
{
public:

	WhileStatement(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_WHILE);

		m_condition.swap(ExpressionBuilder::construct(tokens));

		tokens.nextAssert(TOKEN_DO);

		m_loop = CommandList(tokens);

		tokens.nextAssert(TOKEN_OD);
	}

	void evaluate(Context& ctx) override
	{
		while (true)
		{
			m_condition->evaluate(ctx);
			bool result = ctx.loadValue().value;

			if (result)
			{
				m_loop.evaluate(ctx);
			}
			else
			{
				return;
			}
		}
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "WHILE" << std::endl;

		indent(out, i + 1);
		out << "CONDITION" << std::endl;
		m_condition->print(out, i + 2);

		indent(out, i + 1);
		out << "DO" << std::endl;
		m_loop.print(out, i + 2);
	}

private:

	ASTNode m_condition;
	CommandList m_loop;
};
