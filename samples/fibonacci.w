#
#	Compute the nth fibonacci number
#
#	fib(0) = 0
#	fib(1) = 1
#	fib(2) = 1
#	fib(3) = 2
#

program

	var n, i : nat;
	var a, b : nat;
	var f : nat;

begin

	read(n);

	# handle base cases
	if (n == 0) then
		write(0);
	else
		if (n == 1) then
			write(1);
		else

			# set counter
			i := 1;
			# initialize previous two fibonacci numbers in sequence
			a := 0;
			b := 1;

			while (i < n) do
			
				# current number is sum of previous two
				f := a + b;
				# update previous values
				a := b;
				b := f;
				# increment counter
				i := i + 1;
			od;

			# print result
			write(f);

		fi;
	fi;
	
end
