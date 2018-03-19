/*
	Expression Builder
*/

#include "wl/AST/ExpressionBuilder.h"

#include "wl/AST/BinaryOperation.h"
#include "wl/AST/Literal.h"
#include "wl/AST/Variable.h"

ASTNode ExpressionBuilder::construct(Tokenizer& tokens)
{
	ASTNode left;

	//(<expression>)
	if (tokens.isNext(TOKEN_OPEN_BRACKET))
	{
		tokens.next();
		left.swap(ExpressionBuilder::construct(tokens));
		tokens.nextAssert(TOKEN_CLOSE_BRACKET);
	}

	//<literal>
	if (Literal::hasNext(tokens))
	{
		left.reset(new Literal(tokens));
	}
	//<variable>
	else if (tokens.isNext(TOKEN_IDENTIFIER))
	{
		left.reset(new Variable(tokens));
	}
	
	//<operator>
	if (BinaryOperation::hasNext(tokens))
	{
		const TokenCode op = tokens.next().code;

		//<expression>
		ASTNode right(ExpressionBuilder::construct(tokens));

		return ASTNode(new BinaryOperation(std::move(left), op, std::move(right)));
	}
	else
	{
		return left;
	}
}

