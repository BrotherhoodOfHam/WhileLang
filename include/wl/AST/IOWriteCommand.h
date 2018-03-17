/*
	IO Write Statement:

	<expression-list> ::= <expression> | <expression>, <expression-list>
	<io-write-command> ::= write ( <expression-list> )
*/

#pragma once

#include "wl/AST.h"

class IOWriteCommand : public AST
{
public:

	IOWriteCommand(Tokenizer& tokens)
	{

	}

	void evaluate(Context& ctx) override
	{

	}

private:


};
