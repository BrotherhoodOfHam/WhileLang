/*
	Variable
	
	<variable> ::= <identifier>
*/

#pragma once

#include <string>
#include "wl/AST.h"

class Variable : public AST
{
public:

	Variable(Tokenizer& tokens)
	{
		m_identifier = tokens.nextAssert(TOKEN_IDENTIFIER).symbol;
	}

	void evaluate(Context& ctx) override
	{

	}

private:

	std::string m_identifier;
};
