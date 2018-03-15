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

	}

	void evalutate(Context& ctx) override
	{

	}

private:

	std::vector<VariableDeclaration> m_variables;
};
