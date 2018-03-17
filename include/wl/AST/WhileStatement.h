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

	}

	void evaluate(Context& ctx) override
	{

	}

private:


};
