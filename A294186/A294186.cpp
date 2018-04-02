// From Marcin Barylski 
// C++ source code that generates A294186.

#include <iostream>
#include <set>

using namespace std;

long long unsigned int no_of_unique_greater_twin_primes_in_gp (long long unsigned int n);
bool is_prime (long long unsigned int n);
bool is_greater_twin_prime (long long unsigned int n);

int main()
{
	long long unsigned int max_i;
	cout << "Enter number of even numbers to be examined: ";
	cin >> max_i;
	for (long long unsigned int i=1; i<max_i; i++)
	{
		cout << no_of_unique_greater_twin_primes_in_gp(2*i) << ", ";
	}
	return 0;
}

// note: n should be even
long long unsigned int no_of_unique_greater_twin_primes_in_gp (long long unsigned int n)
{
	set<long long unsigned int> setprimes;
	set<long long unsigned int>::iterator it;
	
	// first looks for possible Goldbach partitions of n and collects unique primes
	for (long long unsigned int i=2; i <= n-2; i++)
	{
		if (is_prime(n-i) && (is_prime(i)))
		{
			setprimes.insert(n-i);
			setprimes.insert(i);
		}
	}
	
	// counts distinct greater twin primes in Goldbach partitions
	long long unsigned int c = 0;
	for (it=setprimes.begin(); it!=setprimes.end(); ++it)
	{
		if (is_greater_twin_prime(*it)) c++;
	}
	return c;
}

// returns true if n is greater twin prime; otherwise false
bool is_greater_twin_prime (long long unsigned int n)
{
	if (is_prime(n) && is_prime(n-2)) return true;
	return false;
}

// returns true if n is prime; otherwise false
bool is_prime (long long unsigned int n)
{
	if (n < 2) return false;
	else if (n <= 3) return true;
	else if ((n%2 == 0) || (n%3 == 0)) return false;
	long long unsigned int i = 5;
	while (i*i <= n)
	{
		if  ((n%i == 0) || (n%(i+2)) == 0) return false;
		i += 6;
	}
	return true;
}