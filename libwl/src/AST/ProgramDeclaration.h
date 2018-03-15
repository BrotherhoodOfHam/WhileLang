/*
	Program declaration

	<program> ::= program <
*/

#pragma once

#include "wl/AST.h"

#include "VariableDeclarationList.h"
#include "CommandList.h"

class ProgramDeclaration : public AST
{
public:

	ProgramDeclaration(Tokenizer& tokens)
	{

	}

	~ProgramDeclaration() {}

	void evalutate(Context& ctx) override
	{

	}
};
