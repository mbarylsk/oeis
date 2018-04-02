// From Marcin Barylski 
// C++ source code that generates A301776.

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
long long unsigned int num_where_all_verified = 0;

int main()
{
	long long unsigned int ip1 = 0;
	long long unsigned int ip2 = 0;
	long long unsigned int p1 = 0;
	long long unsigned int p2 = 0;
	long long unsigned int num = 0;
	
	cout << "Press <Enter> to stop calculations..." << endl;
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

        if (set_to_be_verified.empty())
		{
			cout << p1 << ", ";
		}
		
		ip1++;
		
		if(_kbhit())
		{
			cout << endl << "Breaking calculations at" << ip1 << endl;
            break;
        }
	}
	return 0;
}

void add_nums_to_be_verified (long long unsigned int num)
{
    if (num > num_where_all_verified)
	{
		for (long long unsigned int k = num_where_all_verified + 2; k <= num; k = k + 2)
		{
			set<long long unsigned int>::iterator it;
			if (! (it != set_already_verified.end()) )
			{
				set_already_verified.insert(k);
			}
		}
	}
}

void remove_nums_to_be_verified (long long unsigned int num, long long unsigned int max_num)
{
	/*
	set_already_verified.insert(num);

    if num in to_be_verified:
        to_be_verified.remove(num)
    if (len(to_be_verified) > 0):
        min_num = min(to_be_verified)
        if min_num > num_where_all_verified + 2:
            num_where_all_verified = min_num
    else:
        num_where_all_verified = max_num

    copy_already_verified = already_verified.copy()
    for n in copy_already_verified:
        if n < num_where_all_verified:
            already_verified.remove(n)
	*/
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