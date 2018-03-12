/*
	Entry point
*/

#include <iostream>

#include "Tokenizer.h"

int main(int argc, char** argv)
{
	Tokenizer tokenizer(std::cin);

	while (tokenizer.hasNext())
	{
		Token t = tokenizer.peek();

		std::cout
			<< t.code
			<< " -> \""
			<< t.symbol
			<< "\""
			<< std::endl;

		tokenizer.next();
	}

	return 0;
}
