#
#	compute the factorial of a number
#

program

	var x, f, i : nat;

begin

	read(x);

	f := 1;
	i := 1;
	
	while (i <= x) do
		f := f * i;
		i := i + 1;
	od;
	
	write(f);
	
end