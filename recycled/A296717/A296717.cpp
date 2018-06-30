// From Marcin Barylski 
// C++ source code that generates A296717.

#include <iostream>
#include <set>
#include <conio.h>

using namespace std;

typedef long long unsigned int LLUINT;

void add_nums_to_be_verified (LLUINT num);
void remove_nums_to_be_verified (LLUINT num, LLUINT max_num);
LLUINT get_ith_prime (LLUINT i);
bool is_prime (LLUINT n);

set<LLUINT> set_to_be_verified;
set<LLUINT> set_already_verified;
LLUINT num_where_all_verified = 4;

int main()
{
	LLUINT ip1 = 1;
	LLUINT ip2 = 0;
	LLUINT p1 = 0;
	LLUINT p2 = 0;
	LLUINT num = 0;
	
	cout << "Press <Enter> to stop calculations..." << endl;

	// first term is given fo free
	cout << 1 << ", ";
	while (1)
	{	
		p1 = get_ith_prime (ip1);
		add_nums_to_be_verified (2*p1);
    
		for (ip2 = 1; ip2 <= ip1 + 1; ip2++)
		{
			p2 = get_ith_prime(ip2);
			num = p1 + p2;
			remove_nums_to_be_verified (num, 2*p1);
		}

		if ( set_to_be_verified.empty() )
		{
			// print index of prime - must add 1 because internally we start counting primes from index 0
			cout << ip1 + 1 << ", ";
		}
		
		ip1++;
		
		if (_kbhit())
		{
			cout << endl << "Breaking calculations at " << ip1 << endl;
			break;
		}
	}
	return 0;
}

// Add number to a set of numbers to be verified 
// if number is above threshold where all numbers were already verified
void add_nums_to_be_verified (LLUINT num)
{
	if (num > num_where_all_verified)
	{
		for (LLUINT k = num_where_all_verified + 2; k <= num; k = k + 2)
		{
			auto search = set_already_verified.find(k);
			if (search != set_already_verified.end())
			{
				// found, do nothing
			}
			else
			{
				// not found
				set_to_be_verified.insert(k);
			}
		}
	}
}

// Remove number from a set of already verified numbers
void remove_nums_to_be_verified (LLUINT num, LLUINT max_num)
{	
	set_already_verified.insert(num);

	auto search = set_to_be_verified.find(num);
	if ( search != set_to_be_verified.end() )
	{
		set_to_be_verified.erase(search);
	}
	
	// update number below which all numbers were already verified
	LLUINT min_num = 0;
	if ( !set_to_be_verified.empty() )
	{
		set<LLUINT>::iterator it;
		for (it = set_to_be_verified.begin(); it != set_to_be_verified.end(); ++it)
		{
			if (min_num == 0) min_num = *it;
			else if (min_num > *it) min_num = *it;
		}
		
		if (min_num > num_where_all_verified + 2)
		{
			num_where_all_verified = min_num;
		}
	}
	else
	{
		num_where_all_verified = max_num;
	}
	
	// remove all numbers below num_where_all_verified from further analysis
	set<LLUINT>::iterator itt = set_already_verified.begin();
	for (itt = set_already_verified.begin(); itt != set_already_verified.end(); ) 
	{
		if (*itt < num_where_all_verified)
		{
			itt = set_already_verified.erase(itt++);
		}
		else
		{
			++itt;
		}
	}
}

// returns ith prime
LLUINT get_ith_prime (LLUINT i)
{
	LLUINT n = 2;
	while (i > 0)
	{
		n++;
		if (is_prime(n)) i--;
	}
	return n;
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