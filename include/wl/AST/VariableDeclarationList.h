/*
	Variable Declaration List:

	<variable-decl-list> ::= <empty> | <variable-decl>; | <variable-decl>; <variable-decl-list>
*/

#pragma once

#include <vector>

#include "wl/AST.h"

#include "VariableDeclaration.h"

class VariableDeclarationList : public AST
{
public:

	VariableDeclarationList() {}
	~VariableDeclarationList() {}

	VariableDeclarationList(Tokenizer& tokens)
	{
		while (!tokens.isNext(TOKEN_BEGIN))
		{
			m_variables.push_back(VariableDeclaration(tokens));
			
			tokens.nextAssert(TOKEN_SEPARATOR);
		}
	}

	void evaluate(Context& ctx) override
	{

	}

private:

	std::vector<VariableDeclaration> m_variables;
};
