/*
	Test Assignment
*/

#include <gtest/gtest.h>

#include "utils.h"
#include "wl/AST/AssignmentStatement.h"

TEST(ASTtest, assignment)
{
	auto stream(wrapStream("x := 2"));
	
	//Literal
	Tokenizer tokens(stream);
	
	AssignmentStatement assign(tokens);
}
