//prime.cpp
#include "prime.hpp"
#include "cmath"

bool isPrimeHalf(int n, long long* modOps) 
{
    long long counter = 0;
    // Gets edge case for 0 and 1
    if (n < 2)
    {
        return false;
    }
    // Gets edge case for 2 when null
    if (n == 2)
    {
        return true;
    }

    // Gets rid of redundant checking for even numbers
    if (n % 2 == 0)
    {
        if (modOps)
        {
            counter++;
            *modOps += counter;
        }
        return false;
    }

    // Checks for divisibility up to n/2
    for (int i = 3; i <= n/2; i+=2)
    {
        counter++;
        // Checks if number is prime
        if (n % i == 0)
        {
            // Checks for if modOps is not nullptr
            if (modOps)
            {
                *modOps += counter;
            }
            return false;
        }
    }
    // Checks for if modOps is not nullptr
    if (modOps)
    {
        *modOps += counter;
    }
    return true;
}

bool isPrimeSqrt(int n, long long* modOps) 
{
    long long counter = 0;
    // Gets edge case for 0 and 1
    if (n < 2)
    {
        return false;
    }
    // Gets edge case for 2 when null
    if (n == 2)
    {
        return true;
    }

    // Gets rid of redundant checking for even numbers
    if (n % 2 == 0)
    {
        if (modOps)
        {
            counter++;
            *modOps += counter;
        }
        return false;
    }

    for (int i = 3; i <= sqrt(n); i+=2)
    {
        counter++;
        // Checks if number is prime
        if (n % i == 0)
        {
            // Checks for if modOps is not nullptr
            if (modOps)
            {
                *modOps += counter;
            }
            return false;
        }
    }
    // Checks for if modOps is not nullptr ss
    if (modOps)
    {
        *modOps += counter;
    }
    return true;
}

long long countModOps(PrimeFn isPrime, int lo, int hi) 
{
    long long counter = 0;
    
    for (int i = lo; i <= hi; i++)
    {
        isPrime(i, &counter);
    }
    return counter;
}