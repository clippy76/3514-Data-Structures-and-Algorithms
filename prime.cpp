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
    if (n == 2)
    {
        return true;
    }
    // Checks for divisibility up to n/2
    for (int i = 3; i <= n/2; i++)
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
    if (n == 2)
    {
        return true;
    }
    for (int i = 3; i <= sqrt(n); i++)
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

long long countModOps(PrimeFn isPrime, int lo, int hi) 
{
    long long counter = 0;
    for (int i = lo; i <= hi; i++)
    {
        isPrime(i, &counter);
    }
    return counter;
}