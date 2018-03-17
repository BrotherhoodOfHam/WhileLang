/*
	IO Read Statement:

	<io-read-command> ::= read ( <identifier-list> )
*/

#pragma once

#include "wl/AST.h"

class IOReadCommand : public AST
{
public:

	IOReadCommand(Tokenizer& tokens)
	{

	}

	void evaluate(Context& ctx) override
	{

	}

private:


};
