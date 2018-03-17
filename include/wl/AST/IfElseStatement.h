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

	}

	void evaluate(Context& ctx) override
	{

	}

private:

};
