/*
	Test Expression Evaluation
*/

#include <gtest/gtest.h>

#include "utils.h"
#include "wl/AST/ExpressionBuilder.h"

/*
	Assert that the evaluated expression is equal to a given value
*/
inline void assertExprValue(const char* expr, Context::Value value)
{
	auto stream(wrapStream(expr));
	Tokenizer tokens(stream);
	Context ctx;

	ExpressionBuilder::construct(tokens)->evaluate(ctx);
	auto result = ctx.loadValue().value;

	ASSERT_EQ(value, result);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
	Test cases
*/

TEST(ASTtests, expr0)
{
	assertExprValue("123", 123);
}

TEST(ASTtests, expr1)
{
	assertExprValue("123 + 321", 444);
}

TEST(ASTtests, expr2)
{
	assertExprValue("(123 + 321) - 100", 344);
}

TEST(ASTtests, expr3)
{
	assertExprValue("2 * (123 + 321)", 888);
}

TEST(ASTtests, expr4)
{
	assertExprValue("true",  1);
	assertExprValue("false", 0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
