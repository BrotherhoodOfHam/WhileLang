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
		ctx.storeValue(ctx.getVariable(m_identifier));
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "VARIABLE " << m_identifier << std::endl;
	}

private:

	std::string m_identifier;
};
