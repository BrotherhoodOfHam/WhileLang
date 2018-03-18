/*
	Expression Builder
*/

#include "wl/AST/ExpressionBuilder.h"

#include "wl/AST/Operation.h"
#include "wl/AST/Literal.h"
#include "wl/AST/Variable.h"

ASTNode ExpressionBuilder::construct(Tokenizer& tokens)
{
	//todo: implement expression
	while (!tokens.isNext(TOKEN_THEN) && !tokens.isNext(TOKEN_DO) && !tokens.isNext(TOKEN_COMMA) && !tokens.isNext(TOKEN_SEPARATOR) && !tokens.isNext(TOKEN_CLOSE_BRACKET))
	{
		tokens.next();
	}

	return nullptr;

	//(<expression>)
	if (tokens.isNext(TOKEN_OPEN_BRACKET))
	{
		tokens.next();
		ASTNode n(ExpressionBuilder::construct(tokens));
		tokens.nextAssert(TOKEN_CLOSE_BRACKET);
		return std::move(n);
	}

	ASTNode node;

	//<literal>
	if (Literal::hasNext(tokens))
	{
		node.reset(new Literal(tokens));
	}
	
	//<variable>
	else if (tokens.isNext(TOKEN_IDENTIFIER))
	{
		node.reset(new Variable(tokens));
	}

	return ASTNode(nullptr);
}

