// From Marcin Barylski 
// C++ source code that generates A333779.

#include <iostream>
#include <set>
#include <conio.h>

using namespace std;

typedef long long unsigned int LLUINT;

bool is_prime (LLUINT n);
bool is_prime_marked (LLUINT n);
void mark_prime (LLUINT n);

set<LLUINT> set_primes_marked;

int main()
{
	bool found;
	int a;
	int k;
	bool stop = false;
	
	cout << "Press <Enter> to stop calculations..." << endl;

	k = 0;
	while (1)
	{
		a = 2; // always starts from the first prime to include all previously primes left
		found = false;
		while (!found)
		{
			if (a-k > 1 and is_prime(a-k) and is_prime (a+k) and !is_prime_marked (a-k) and !is_prime_marked (a+k))
			{
				if (k == 0)
				{
					mark_prime (a);
				}
				else
				{
					mark_prime (a-k);
					mark_prime (a+k);
				}
				cout << a << ", ";
				found = true;
			}
			a++;
			
			if (_kbhit())
			{
				cout << endl << "Breaking calculations at term " << k << endl;
				stop = true;
				break;
			}
		}
		k++;
		if (stop)
		{
			break;
		}
	}
	return 0;
}

// returns true if prime is already marked; otherwise false
bool is_prime_marked (LLUINT n)
{
	auto search = set_primes_marked.find(n);
	if ( search != set_primes_marked.end() )
	{
		// found
		return true;
	}
	// not found
	return false;
}

// marks prime to exclude it from further analysis
void mark_prime (LLUINT n)
{
	auto search = set_primes_marked.find(n);
	if (search == set_primes_marked.end())
	{
		// not found
		set_primes_marked.insert(n);
	}
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