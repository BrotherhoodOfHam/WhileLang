/*
	Abstract Syntax Tree
*/

#pragma once

#include <memory>
#include <ostream>

#include "Context.h"
#include "Tokenizer.h"

/*
	Abstract Node in the Syntax Tree
*/
class AST
{
public:

	virtual void evaluate(Context& ctx) = 0;

	void print(std::ostream& out) { print(out, 0); }
	virtual void print(std::ostream& out, uint32_t i) = 0;

	virtual ~AST() {}

protected:

	void indent(std::ostream& out, uint32_t i)
	{
		for (uint32_t x = 0; x < (i * 2); x++)
			out << ' ';
	}
};

using ASTNode = std::unique_ptr<AST>;
//todo: replace with unique ptr
using ASTNodeList = std::vector<std::shared_ptr<AST>>;
