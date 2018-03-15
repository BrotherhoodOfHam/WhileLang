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

	virtual void evalutate(Context& ctx) = 0;

	virtual ~AST() {}
};
