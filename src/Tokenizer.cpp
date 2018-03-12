/*
	Tokenizer
*/

#include "CharTypes.h"
#include "Tokenizer.h"

#include <unordered_map>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace
{
	//Map an identifier token to a keyword
	void mapKeyword(Token& tok)
	{
		static std::unordered_map<std::string, TokenCode> mapping
		({
			{ "program", TOKEN_PROGRAM },
			{ "var",     TOKEN_VAR     },
			{ "skip",    TOKEN_SKIP    },
			{ "read",    TOKEN_READ    },
			{ "write",   TOKEN_WRITE   },

			{ "true",  TOKEN_BOOL_TRUE  },
			{ "false", TOKEN_BOOL_FALSE },

			{ "and",  TOKEN_OP_AND },
			{ "or",   TOKEN_OP_OR  },
			{ "not",  TOKEN_OP_NOT },

			{ "if",    TOKEN_IF    },
			{ "then",  TOKEN_THEN  },
			{ "else",  TOKEN_ELSE  },
			{ "fi",    TOKEN_FI    },
			{ "while", TOKEN_WHILE },
			{ "do",    TOKEN_DO    },
			{ "od",    TOKEN_OD    },
		});

		//search
		auto it = mapping.find(tok.symbol);

		//set default token code
		tok.code = TOKEN_IDENTIFIER;

		//if a keyword was mapped
		if (it != mapping.end())
		{
			//update token code
			tok.code = it->second;
		}
	}

	void mapSymbol(Token& tok)
	{
		static std::unordered_map<char, TokenCode> mapping
		({
			{ ':', TOKEN_COLON     },
			{ ';', TOKEN_SEPARATOR },

			{ '<', TOKEN_OP_LT },
			{ '>', TOKEN_OP_GT },

			{ '*', TOKEN_OP_MUL   },
			{ '/', TOKEN_OP_DIV   },
			{ '%', TOKEN_OP_MOD   },
			{ '-', TOKEN_OP_MINUS },
			{ '+', TOKEN_OP_PLUS  },
		});

		//search
		auto it = mapping.find(tok.symbol.front());

		//if a keyword was mapped
		if (it != mapping.end())
		{
			//update token code
			tok.code = it->second;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
	Fetch the next token
*/
void Tokenizer::fetch()
{
	Token& tok = m_next;
	tok.code = TokenCode::TOKEN_STOP;
	tok.symbol.clear();
	
	//for each input character
	if (m_stream.peek() != EOF)
	{
		const CharClass cl = CharTypes::classify(m_stream.peek());

		//whitespace
		if (cl == CHAR_CLASS_WHITESPACE)
		{
			while (CharTypes::classify(m_stream.peek()) == CHAR_CLASS_WHITESPACE)
			{
				if (m_stream.get() == '\n')
				{
					tok.line++;
				}
			}
		}
		//number
		else if (cl == CHAR_CLASS_DIGIT)
		{
			tok.code = TOKEN_INTEGER;

			while (CharTypes::classify(m_stream.peek()) == CHAR_CLASS_DIGIT)
			{
				tok.symbol += m_stream.get();
			}
		}
		//identifier
		else if (m_stream.peek() == '_' || cl == CHAR_CLASS_LETTER)
		{
			tok.code = TOKEN_IDENTIFIER;

			while (
				CharTypes::classify(m_stream.peek()) == CHAR_CLASS_LETTER ||
				CharTypes::classify(m_stream.peek()) == CHAR_CLASS_DIGIT ||
				m_stream.peek() == '_')
			{
				tok.symbol += m_stream.get();
			}

			//try and map an identifier to a keyword
			mapKeyword(tok);
		}
		//symbols (operators)
		else
		{
			char c = m_stream.get();
			char n = m_stream.peek();

			tok.code = TOKEN_ERROR;
			tok.symbol += c;
			
			//assign
			if (c == ':' && n == '=')
			{
				tok.symbol += m_stream.get();
				tok.code = TOKEN_OP_ASSIGN;
			}
			//not equal
			else if (c == '!' && n == '=')
			{
				tok.symbol += m_stream.get();
				tok.code = TOKEN_OP_NEQ;
			}
			//equal
			else if (c == '=' && n == '=')
			{
				tok.symbol += m_stream.get();
				tok.code = TOKEN_OP_EQ;
			}
			//greater than or equal
			else if (c == '>' && n == '=')
			{
				tok.symbol += m_stream.get();
				tok.code = TOKEN_OP_GE;
			}
			//less than or equal
			else if (c == '<' && n == '=')
			{
				tok.symbol += m_stream.get();
				tok.code = TOKEN_OP_LE;
			}
			else
			{
				//otherwise try and map a single symbol
				mapSymbol(tok);
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////