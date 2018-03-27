# WhileLang

*While* is a simple imperative programming language, built purely for educational purposes.

It consists of 2 single data-types:
* Unsigned integers (Natural numbers).
* Booleans

It has 5 main commands:
* If statements.
* While statements.
* Assignment statements.
* IO read.
* IO write.

More information about the grammar can be found in grammar.bnf located in the root directory.

### Installation
This project is built using the [meson build system](http://mesonbuild.com/).
Build example:
```bash
cd project/dir
mkdir build && pushd build
meson ..
ninja
```
### Example Usage
square.w
```
program
    var x : nat;
begin
    read(x);
    write(x*x);
end
```
The program can be executed from the command line using the interpreter *wlc*:
```bash
wlc square.w
<< 2
>> 4
```
Or analysed,
```bash
wlc -print-ast square.w
PROGRAM
  VARDECL-LIST:
    VARDECL x, TYPE nat
  COMMAND-LIST:
    IO-READ x, 
    IO-WRITE
      OPERATION *
        VARIABLE x
        VARIABLE x
        
wlc -print-tokens square.w
(1:1)[program]                -> "program"
(1:2)[var]                    -> "var"
(1:3)[Identifier]             -> "x"
(1:4)[:]                      -> ":"
(1:5)[Identifier]             -> "nat"
(1:6)[;]                      -> ";"
(1:7)[begin]                  -> "begin"
(1:8)[read]                   -> "read"
(1:9)[(]                      -> "("
(1:10)[Identifier]            -> "x"
(1:11)[)]                     -> ")"
(1:12)[;]                     -> ";"
(1:13)[write]                 -> "write"
(1:14)[(]                     -> "("
(1:15)[Identifier]            -> "x"
(1:16)[*]                     -> "*"
(1:17)[Identifier]            -> "x"
(1:18)[)]                     -> ")"
(1:19)[;]                     -> ";"
(1:20)[end]                   -> "end"
```

## TODO
* More unit tests
* Proper type-safety at the language level.
* Logical connectives (and/or/not).
* General code cleanup
* Proper CLI
* Operator precedence
