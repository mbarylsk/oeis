// From Marcin Barylski 
// C++ source code that generates A294186.

#include <iostream>
#include <set>

using namespace std;

typedef long long unsigned int LLUINT;

LLUINT no_of_unique_greater_twin_primes_in_gp (LLUINT n);
bool is_prime (LLUINT n);
bool is_greater_twin_prime (LLUINT n);

int main()
{
	LLUINT max_i;
	cout << "Enter number of even numbers to be examined: ";
	cin >> max_i;
	for (LLUINT i=1; i<max_i; i++)
	{
		cout << no_of_unique_greater_twin_primes_in_gp(2*i) << ", ";
	}
	return 0;
}

// note: n should be even
LLUINT no_of_unique_greater_twin_primes_in_gp (LLUINT n)
{
	set<LLUINT> setprimes;
	set<LLUINT>::iterator it;
	
	// first looks for possible Goldbach partitions of n and collects unique primes
	for (LLUINT i=2; i <= n-2; i++)
	{
		if (is_prime(n-i) && (is_prime(i)))
		{
			setprimes.insert(n-i);
			setprimes.insert(i);
		}
	}
	
	// counts distinct greater twin primes in Goldbach partitions
	LLUINT c = 0;
	for (it=setprimes.begin(); it!=setprimes.end(); ++it)
	{
		if (is_greater_twin_prime(*it)) c++;
	}
	return c;
}

// returns true if n is greater twin prime; otherwise false
bool is_greater_twin_prime (LLUINT n)
{
	if (is_prime(n) && is_prime(n-2)) return true;
	return false;
}

// returns true if n is prime; otherwise false
bool is_prime (LLUINT n)
{
	if (n < 2) return false;
	else if (n <= 3) return true;
	else if ((n%2 == 0) || (n%3 == 0)) return false;
	LLUINT i = 5;
	while (i*i <= n)
	{
		if  ((n%i == 0) || (n%(i+2)) == 0) return false;
		i += 6;
	}
	return true;
}