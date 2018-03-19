/*
	Literal
	
	<literal> ::= <boolean> | <integer>
*/

#pragma once

#include <string>

#include "wl/AST.h"
#include "wl/SyntaxError.h"

class Literal : public AST
{
public:

	static bool hasNext(Tokenizer& tokens)
	{
		switch (tokens.peek().code)
		{
			case TOKEN_BOOL:       return true;
			case TOKEN_INTEGER:    return true;
		}

		return false;
	}

	Literal(Tokenizer& tokens)
	{
		Token tok = tokens.next();
		
		switch (tok.code)
		{
		case TOKEN_BOOL:    m_value = tok.symbol; return;
		case TOKEN_INTEGER: m_value = tok.symbol; return;
		}
		
		throw SyntaxError(TOKEN_INTEGER, tok.code);
	}

	void evaluate(Context& ctx) override
	{
		
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "LITERAL " << m_value << std::endl;
	}

private:

	std::string m_value;
};
