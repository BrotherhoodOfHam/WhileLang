program
var x, y : nat;
var b : bool;
begin
	x := 2 * 3;
	y := 2 + 4;
	b := x == y;
	if b then write x; else y; fi;
end
