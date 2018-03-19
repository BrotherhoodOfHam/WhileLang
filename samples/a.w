program
var x, y : nat;
var i : nat;
begin
	read(x,y);
	
	x := (0 * 2) + (2 * x);
	y := 2 + y;
	
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
