#define CATCH_CONFIG_MAIN
#include "C:\Users\camde\projects\Project1A\catch.hpp"
#include "prime.cpp"

// Testing few prime identification
TEST_CASE("Testing prime numbers half", "[isPrimeHalf]")
{
    REQUIRE(isPrimeHalf(4) == false);
    REQUIRE(isPrimeHalf(67) == true);
    REQUIRE(isPrimeHalf(97) == true);
    REQUIRE(isPrimeHalf(38) == false);
}
TEST_CASE("Testing prime numbers sqrt", "[isPrimeSqrt]")
{
    REQUIRE(isPrimeSqrt(4) == false);
    REQUIRE(isPrimeSqrt(49) == false);
    REQUIRE(isPrimeSqrt(67) == true);
    REQUIRE(isPrimeSqrt(97) == true);
}
// Testing composite numbers
TEST_CASE("Testing composite numbers", "[compositeNumbers]")
{
    REQUIRE(isPrimeSqrt(4) == false);
    REQUIRE(isPrimeSqrt(10) == false);
    REQUIRE(isPrimeSqrt(55) == false);
    REQUIRE(isPrimeSqrt(93) == false);
}
// Test for few range of prime numbers if both methods are consistent
TEST_CASE("Testing range (no edge cases) to 1000", "[comparison]")
{
    for (int i = 2; i <= 1000; i++)
    {
        REQUIRE(isPrimeHalf(i) == isPrimeSqrt(i));
    }
}
// Testing mod operation counts
TEST_CASE("Testing mod operation counts for the two")
{
    long long halfOps = 0;
    long long sqrtOps = 0;
    isPrimeHalf(64, &halfOps);
    isPrimeSqrt(64, &sqrtOps);
    REQUIRE(halfOps == 1);
    REQUIRE(sqrtOps == 1);
    REQUIRE(countModOps(isPrimeHalf, 0, 10) == 10);
}
// Test edge cases
TEST_CASE("Testing edge cases")
{
    REQUIRE(isPrimeHalf(0) == false);
    REQUIRE(isPrimeHalf(1) == false);
    REQUIRE(isPrimeHalf(2) == true);

    REQUIRE(isPrimeSqrt(0) == false);
    REQUIRE(isPrimeSqrt(1) == false);
    REQUIRE(isPrimeSqrt(2) == true);
}