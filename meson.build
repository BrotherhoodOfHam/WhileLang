########################################################################
#	WhileLang project
########################################################################

project('WhileLang', 'cpp')

#
#	Setup gtest
#
gtest = dependency('gtest', main : true, required : false)

if not gtest.found()
	gtest = subproject('gtest').get_variable('gtest_dep')
endif

########################################################################
#	Interpreter
########################################################################

libwl_inc = include_directories('include')

#
#	LibWL
#
libwl = static_library('wl',
	sources : files(
		'include/wl/Tokenizer.h',
		'include/wl/AST.h',
		'include/wl/Context.h',
		'include/wl/Interpreter.h',
		'include/wl/SyntaxError.h',
		'include/wl/AST/ProgramDeclaration.h',
		'include/wl/AST/Command.h',
		'include/wl/AST/CommandList.h',
		'include/wl/AST/ArithmeticExpression.h',
		'include/wl/AST/BooleanExpression.h',
		'include/wl/AST/AssignmentStatement.h',
		'include/wl/AST/BinaryOperator.h',
		'include/wl/AST/IfElseStatement.h',
		'include/wl/AST/WhileStatement.h',
		'include/wl/AST/IOReadCommand.h',
		'include/wl/AST/IOWriteCommand.h',
		'include/wl/AST/Literal.h',
		'include/wl/AST/Variable.h',
		'include/wl/AST/VariableDeclaration.h',
		'include/wl/AST/VariableDeclarationList.h',
		'src/CharTypes.h',
		'src/Context.cpp',
		'src/Interpreter.cpp',
		'src/Tokenizer.cpp',
		'src/TokenEnum.cpp',
	),
	include_directories : libwl_inc
)

#
#	WL executable
#
executable('wlc',
	sources : files(
		'exe/main.cpp'
	),
	link_with : libwl,
	include_directories : libwl_inc
)

########################################################################
#	Tests
########################################################################

wltest = executable('wltest',
	sources : files(
		'tests/test_tokenizer.cpp',
		'tests/test.cpp'
	),
	link_with : libwl,
	include_directories : libwl_inc,
	dependencies : gtest
)

test('test', wltest)

########################################################################