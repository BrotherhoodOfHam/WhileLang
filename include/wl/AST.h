/*
	Abstract Syntax Tree
*/

#pragma once

#include <memory>

#include "Context.h"
#include "Tokenizer.h"

/*
	Abstract Node in the Syntax Tree
*/
class AST
{
public:

	virtual void evaluate(Context& ctx) = 0;

	virtual ~AST() {}
};

using ASTNode = std::unique_ptr<AST>;
//todo: replace with unique ptr
using ASTNodeList = std::vector<std::shared_ptr<AST>>;
