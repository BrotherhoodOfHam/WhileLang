project('WhileLang', 'cpp')

gtest = dependency('gtest', main : true, required : false)
if gtest.found()
	print('gtest found')
endif

src = files(
	'src/main.cpp',
	'src/CharTypes.h',
	'src/Tokenizer.h',
	'src/Tokenizer.cpp'
)

executable('wl',
	sources : src
)
