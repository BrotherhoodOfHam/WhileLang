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

	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "VARDECL-LIST:" << std::endl;
		for (auto& node : m_variables)
		{
			node.print(out, i + 1);
		}
	}

private:

	std::vector<VariableDeclaration> m_variables;
};
