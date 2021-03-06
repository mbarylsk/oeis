// From Marcin Barylski 
// C++ source code that generates A303691.

#include <iostream>

using namespace std;

typedef long long unsigned int LLUINT;

LLUINT min_diff_in_all_gp (LLUINT n);
bool is_prime (LLUINT n);

int main()
{
	LLUINT max_i;
	cout << "Enter number of even numbers to be examined: ";
	cin >> max_i;
	for (LLUINT i = 1; i < max_i; i++)
	{
		cout << min_diff_in_all_gp(2*i) << ", ";
	}
	return 0;
}

// note: n should be even > 2
LLUINT min_diff_in_all_gp (LLUINT n)
{
	LLUINT min_diff = 0;

	// go through possible Goldbach partitions and break on first one
	for (LLUINT i = n/2; i >= 2; i--)
	{
		if (is_prime(n-i) && (is_prime(i)) && (n - 2*i >= 0))
		{
			min_diff = n - 2*i;
			break;
		}
	}
	// return min diff
	return (min_diff);
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