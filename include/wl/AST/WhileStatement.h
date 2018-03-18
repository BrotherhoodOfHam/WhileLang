/*
	While Statement:

	<while-statement> ::= while <boolean-expression> do <command-list> od
*/

#pragma once

#include "wl/AST.h"

class WhileStatement : public AST
{
public:

	WhileStatement(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_WHILE);

		while (!tokens.isNext(TOKEN_DO)) //bool expr
			tokens.next();

		tokens.nextAssert(TOKEN_DO);

		m_loop = CommandList(tokens);

		tokens.nextAssert(TOKEN_OD);
	}

	void evaluate(Context& ctx) override
	{

	}

private:

	CommandList m_loop;
};
