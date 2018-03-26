#
#	test if a number is prime
#

program

	var x, i : nat;
	var isprime : bool;

begin

	read(x);
	
	# 0 is not prime
	if (x == 0) then
		write(false);
	else
		# 1 is prime
		if (x == 1) then
			write(false);
		else

			i := 2;
			# assume x is prime
			isprime := true;
			
			# try every possible factor
			while (i < x) do
				
				# if i is a factor of x
				if ((x % i) == 0) then
					# x cannot be prime
					isprime := false;
				else skip; fi;
				
				i := i + 1;
			od;
			
			write(isprime);
		fi;
	fi;

end