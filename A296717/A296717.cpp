// From Marcin Barylski 
// C++ source code that generates A296717.

#include <iostream>
#include <set>
#include <conio.h>

using namespace std;

void add_nums_to_be_verified (long long unsigned int num);
void remove_nums_to_be_verified (long long unsigned int num, long long unsigned int max_num);
long long unsigned int get_ith_prime (unsigned long long int i);
bool is_prime (long long unsigned int n);

set<long long unsigned int> set_to_be_verified;
set<long long unsigned int> set_already_verified;
long long unsigned int num_where_all_verified = 4;

int main()
{
	long long unsigned int ip1 = 1;
	long long unsigned int ip2 = 0;
	long long unsigned int p1 = 0;
	long long unsigned int p2 = 0;
	long long unsigned int num = 0;
	
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
void add_nums_to_be_verified (long long unsigned int num)
{
	if (num > num_where_all_verified)
	{
		for (long long unsigned int k = num_where_all_verified + 2; k <= num; k = k + 2)
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
void remove_nums_to_be_verified (long long unsigned int num, long long unsigned int max_num)
{	
	set_already_verified.insert(num);

	auto search = set_to_be_verified.find(num);
	if ( search != set_to_be_verified.end() )
	{
		set_to_be_verified.erase(search);
	}
	
	// update number below which all numbers were already verified
	long long unsigned int min_num = 0;
	if ( !set_to_be_verified.empty() )
	{
		set<long long unsigned int>::iterator it;
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
	set<long long unsigned int>::iterator itt = set_already_verified.begin();
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
long long unsigned int get_ith_prime (unsigned long long int i)
{
	unsigned long long int n = 2;
	while (i > 0)
	{
		n++;
		if (is_prime(n)) i--;
	}
	return n;
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