// From Marcin Barylski 
// C++ source code that generates A321221.

#include <iostream>
#include <conio.h>

using namespace std;

typedef long long unsigned int LLUINT;

bool is_lesser_twin_prime (LLUINT n);
bool is_prime (LLUINT n);

int main()
{
	LLUINT num = 4;
	bool found;
	
	cout << "Press <Enter> to stop calculations..." << endl;

	while (1)
	{	
		// first if num has Goldbach Partition with both lesser twin primes
		found = false;
		for (LLUINT i=2; i <= num-2; i++)
		{
			if (is_lesser_twin_prime(num-i) && (is_lesser_twin_prime(i)))
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			cout << num << ", ";
		}
		
		num+= 6;
		
		if (_kbhit())
		{
			cout << endl << "Breaking calculations at " << num << endl;
			break;
		}
	}
	return 0;
}

// returns true if n is lesser twin prime; otherwise false
bool is_lesser_twin_prime (LLUINT n)
{
	if (is_prime(n) && is_prime(n+2)) return true;
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