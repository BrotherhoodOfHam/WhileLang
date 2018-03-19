/*
	Skip Statement
*/

#pragma once

#include "wl/AST.h"

class SkipStatement : public AST
{
public:
	
	SkipStatement(Tokenizer& tokens) { tokens.nextAssert(TOKEN_SKIP); }
	
	void evaluate(Context& ctx) override
	{
		//no-op
	}
	
	void print(std::ostream& out, uint32_t i) override
	{
		indent(out, i);
		out << "SKIP\n";
	}
};
