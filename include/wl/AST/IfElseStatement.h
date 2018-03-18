/*
	If Statement:

	<if-statement> ::= if <boolean-expression> then <command-list> else <command-list> fi
*/

#pragma once

#include "wl/AST.h"

#include "CommandList.h"

class IfElseStatement : public AST
{
public:

	IfElseStatement(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_IF);

		while (!tokens.isNext(TOKEN_THEN)) //bool expr
			tokens.next();

		tokens.nextAssert(TOKEN_THEN);

		m_true = CommandList(tokens);

		tokens.nextAssert(TOKEN_ELSE);

		m_false = CommandList(tokens);

		tokens.nextAssert(TOKEN_FI);
	}

	void evaluate(Context& ctx) override
	{

	}

private:

	CommandList m_true;
	CommandList m_false;
};
