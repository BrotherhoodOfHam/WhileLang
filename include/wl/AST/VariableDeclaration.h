/*
	Variable Declaration:

	<type> ::= <identifier>
	<variable-decl> ::= var <identifier-list> : <type>
*/

#pragma once

#include <string>

#include "wl/AST.h"

class VariableDeclaration : public AST
{
public:

	VariableDeclaration() {}
	~VariableDeclaration() {}

	VariableDeclaration(Tokenizer& tokens)
	{
		tokens.nextAssert(TOKEN_VAR);
		
		while (!tokens.isNext(TOKEN_COLON))
		{
			m_identifiers.push_back(tokens.nextAssert(TOKEN_IDENTIFIER).symbol);
			
			if (tokens.isNext(TOKEN_COMMA))
			{
				tokens.next();
			}
			else
			{
				break;
			}
		}
		
		tokens.next();
		
		m_type = tokens.nextAssert(TOKEN_IDENTIFIER).symbol;
	}

	void evaluate(Context& ctx) override
	{
		
	}

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "VARDECL ";

		for (auto& v : m_identifiers)
		{
			out << v << ", ";
		}

		out << "TYPE ";
		out << m_type;
		out << std::endl;
	}

private:

	std::string m_type;
	std::vector<std::string> m_identifiers;
};
