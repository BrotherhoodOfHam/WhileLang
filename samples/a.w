#
#	sample program
#

program
var x, y : nat;
var i : nat;
begin
	read(x,y);
	
	x := (2 * x);
	y := 2 + y;
	
	if (x == y) then
		write(x);
	else
		skip;
	fi;
	
	i := 0;
	while (i < 5) do
		write(i);
		i := i + 1;
	od;
	
end
