/*
	Integration testing:
	
	Test the program interpreter
*/

#include <gtest/gtest.h>

#include "utils.h"
#include "wl/AST/ProgramStart.h"

#include <fstream>

///////////////////////////////////////////////////////////////////////////////////////////

void runProgram(const char* fpath, Context& ctx)
{
	std::ifstream f(fpath);
	
	ASSERT_TRUE(f.good()) << "Unable to find \"" << fpath << "\"";
	
	Tokenizer tokens(f);
	
	ProgramStart prog(tokens);
	prog.evaluate(ctx);
}

///////////////////////////////////////////////////////////////////////////////////////////

Context::Value factorial(Context::Value n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

Context::Value fibonacci(Context::Value n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

bool isprime(Context::Value x)
{
	if (x == 0 || x == 1)
	{
		return false;
	}
	
	for (Context::Value i = 2; i < x; i++)
	{
		if ((x % i) == 0)
		{
			return false;
		}
	}
	
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////

/*
	Test cases
*/

TEST(WLtest, program_factorial)
{
	//Test the factorial program
	for (Context::Value i = 0; i < 11; i++)
	{
		std::stringstream out;
		std::stringstream in;
		
		in << i;
		Context ctx(out, in);
		runProgram("samples/factorial.w", ctx);
		
		ASSERT_EQ(factorial(i), ctx.getVariable("f").value);
	}
}

TEST(WLtest, program_isprime)
{
	//Test the isprime program
	for (Context::Value i = 0; i < 100; i++)
	{
		std::stringstream out;
		std::stringstream in;
		
		in << i;
		Context ctx(out, in);
		runProgram("samples/isprime.w", ctx);
		
		ASSERT_EQ(isprime(i), ctx.getVariable("isprime").value != 0) << "where x = " << i;
	}
}

TEST(WLtest, program_fibonacci)
{	
	//Test the fibonacci program
	for (Context::Value i = 0; i < 11; i++)
	{
		std::stringstream out;
		std::stringstream in;
		
		in << i;
		Context ctx(out, in);
		runProgram("samples/fibonacci.w", ctx);
		
		ASSERT_EQ(fibonacci(i), ctx.getVariable("f").value);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
