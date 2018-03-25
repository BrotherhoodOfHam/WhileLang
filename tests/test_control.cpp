/*
	Test control structures
*/

#include <gtest/gtest.h>

#include "utils.h"
#include "wl/AST/WhileStatement.h"
#include "wl/AST/IfElseStatement.h"

/*
	Test cases
*/

TEST(ASTtests, ifTrue)
{
	auto stream(wrapStream("if (true) then x := 10; else x := 20; fi"));
	Tokenizer tokens(stream);
	Context ctx;

	ctx.declareVariable("x", "nat");

	IfElseStatement statement(tokens);
	statement.evaluate(ctx);

	ASSERT_EQ(10, ctx.getVariable("x").value);
}

TEST(ASTtests, ifFalse)
{
	auto stream(wrapStream("if (false) then x := 10; else x := 20; fi"));
	Tokenizer tokens(stream);
	Context ctx;

	ctx.declareVariable("x", "nat");

	IfElseStatement statement(tokens);
	statement.evaluate(ctx);

	ASSERT_EQ(20, ctx.getVariable("x").value);
}

TEST(ASTtests, whileDo)
{
	auto stream(wrapStream("while (x < 5) do x := x + 1; od"));
	Tokenizer tokens(stream);
	Context ctx;

	ctx.declareVariable("x", "nat");
	ctx.setVariable("x", 0);

	WhileStatement statement(tokens);
	statement.evaluate(ctx);

	ASSERT_EQ(5, ctx.getVariable("x").value);
}
