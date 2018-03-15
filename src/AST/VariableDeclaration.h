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

	}

	void evalutate(Context& ctx) override
	{

	}

private:

	std::string m_type;
	std::vector<std::string> m_identifiers;
};
