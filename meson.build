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
		'include/wl/AST/ProgramStart.h',
		'include/wl/AST/CommandBuilder.h',
		'include/wl/AST/CommandList.h',
		'include/wl/AST/ExpressionBuilder.h',
		'include/wl/AST/Variable.h',
		'include/wl/AST/Literal.h',
		'include/wl/AST/BinaryOperation.h',
		'include/wl/AST/AssignmentStatement.h',
		'include/wl/AST/SkipStatement.h',
		'include/wl/AST/IfElseStatement.h',
		'include/wl/AST/WhileStatement.h',
		'include/wl/AST/IOReadCommand.h',
		'include/wl/AST/IOWriteCommand.h',
		'include/wl/AST/VariableDeclaration.h',
		'include/wl/AST/VariableDeclarationList.h',
		'src/AST/ExpressionBuilder.cpp',
		'src/AST/CommandBuilder.cpp',
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
		'tests/utils.h',
		'tests/test_control.cpp',
		'tests/test_expr.cpp',
		'tests/test_tokenizer.cpp',
		'tests/test.cpp'
	),
	link_with : libwl,
	include_directories : libwl_inc,
	dependencies : gtest
)

test('test', wltest)

########################################################################