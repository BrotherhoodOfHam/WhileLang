program
var x, y : nat;
var i : nat;
begin
	x := 2 * 3;
	y := 2 + 4;
	
	if (x == y) then
		write(x);
	else
		skip;
	fi;
	
	i := 0;
	while (i < 5) do
		i := i + 1;
		write(i);
	od;
	
end
