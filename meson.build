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

libwl_inc = include_directories('libwl/include')

libwl = static_library('wl',
	sources : files(
		'libwl/include/Tokenizer.h',
		'libwl/src/CharTypes.h',
		'libwl/src/Tokenizer.cpp',
		'libwl/src/TokenEnum.cpp'
	),
	include_directories : libwl_inc
)

executable('wlc',
	sources : files(
		'wlc/main.cpp'
	),
	link_with : libwl,
	include_directories : libwl_inc
)

wltest = executable('wltest',
	sources : files(
		'wltest/test_tokenizer.h',
		'wltest/test.cpp'
	),
	link_with : libwl,
	include_directories : libwl_inc,
	dependencies : gtest
)

test('test', wltest)

########################################################################