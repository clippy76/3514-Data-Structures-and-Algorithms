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
    // Checks for divisibility up to n/2
    for (int i = 2; i <= n/2; i++)
    {
        // Checks if number is prime
        if (n % i == 0)
        {
            counter++;
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
    for (int i = 2; i <= sqrt(n); i++)
    {
        // Checks if number is prime
        if (n % i == 0)
        {
            counter++;
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

long long countModOps(PrimeFn isPrime, int lo, int hi) 
{
    long long counter = 0;
    for (int i = lo; i <= hi; i++)
    {
        isPrime(i, &counter);
    }
    return counter;
}