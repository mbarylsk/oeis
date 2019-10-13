# From Marcin Barylski
# Python source code that generates A328179.

import sys

list_of_sets_required_factors = [{2}]
temp_list_of_sets_required_factors = []
n = 2

def is_prime (n):
    if n == 1:
        return False
    elif n == 2 or n == 3:
        return True
    elif n % 2 == 0 or n % 3 == 0:
        return False
    result = True
    i = 5
    while i*i <= n:
        if n %  i == 0 or n % (i + 2) == 0:
            result = False
            break
        i += 6
    return result

def find_sum_of_prime_numbers (n):
    min_i = 2
    max_i = int(n / 2) + 1
    factors = []
    for i in range (min_i, max_i):
        p1 = i
        p2 = n - p1
        if is_prime(p1) and is_prime (p2):
            pair = (p1, p2)
            factors.append (pair)
    return factors

def find_next_term (num):
    global list_of_sets_required_factors, temp_list_of_sets_required_factors
    
    # step 0:
    # find all Goldbach partitions
    factors = find_sum_of_prime_numbers (num)

    # step 1:
    # check #1: maybe set_required_factors already contains required factors?
    fullfiled = False
    for pair in factors:
        (p1, p2) = pair
        for set_required_factors in list_of_sets_required_factors:
            if not fullfiled and p1 in set_required_factors and p2 in set_required_factors:
                fullfiled = True

    # check #2: p1 or p2 is not on a set_required_factors
    if not fullfiled:
  
        for pair in factors:
            (p1, p2) = pair
            for my_set_required_factors in list_of_sets_required_factors:
                my_temp_set = my_set_required_factors.copy()
                if p1 in my_temp_set and p2 not in my_temp_set:
                    my_temp_set.add (p2)
                    temp_list_of_sets_required_factors.append (my_temp_set)
                    my_temp_set = {}

        for pair in factors:
            for my_set_required_factors in list_of_sets_required_factors:
                my_temp_set = my_set_required_factors.copy()
                if p1 not in my_temp_set and p2 in my_temp_set:
                    my_temp_set.add (p1)
                    temp_list_of_sets_required_factors.append (my_temp_set)
                    my_temp_set = {}

        for pair in factors:
            for my_set_required_factors in list_of_sets_required_factors:
                my_temp_set = my_set_required_factors.copy()
                if p1 not in my_temp_set and p2 not in my_temp_set:
                    my_temp_set.add (p1)
                    my_temp_set.add (p2)
                    temp_list_of_sets_required_factors.append (my_temp_set)
                    my_temp_set = {}
    else:
        for set_required_factors in list_of_sets_required_factors:
            condition_met = False
            for pair in factors:
                (p1, p2) = pair
                if p1 in set_required_factors and p2 in set_required_factors:
                    condition_met = True

            if not condition_met:
                list_of_sets_required_factors.remove (set_required_factors)

    # step 2: cleanup of set_temp_list_required_factors
    if len(temp_list_of_sets_required_factors) > 0:
        min_lenght = sys.maxsize
        for temp_set_required_factors in temp_list_of_sets_required_factors:
            if len(temp_set_required_factors) < min_lenght:
                min_lenght = len(temp_set_required_factors)

        list_of_sets_required_factors = []
        for temp_set_required_factors in temp_list_of_sets_required_factors:
            if len(temp_set_required_factors) == min_lenght:
                list_of_sets_required_factors.append (temp_set_required_factors)

        temp_list_of_sets_required_factors = []

# main
sys.stdout.write('0,')
try:
    while True:
        n += 2
        find_next_term (n)

        # print next term
        min_lenght = sys.maxsize
        for set_required_factors in list_of_sets_required_factors:
            if len(set_required_factors) < min_lenght:
                min_lenght = len(set_required_factors)
        sys.stdout.write(str(min_lenght)+',')
        
except KeyboardInterrupt:
    pass



