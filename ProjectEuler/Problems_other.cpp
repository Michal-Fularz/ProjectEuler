#include "ProjectEuler.h"

#include <iostream>

#include <list>
#include <vector>
#include <set>

#include <algorithm>
#include <numeric>
#include <functional>

#include <string>

#include "SupportFunctions.h"

using std::cout;
using std::cin;
using std::endl;

/*
St. Petersburg Lottery
Problem 499
A gambler decides to participate in a special lottery. In this lottery the gambler plays a series of one or more games.
Each game costs m pounds to play and starts with an initial pot of 1 pound. The gambler flips an unbiased coin. Every time a head appears, the pot is doubled and the gambler continues. When a tail appears, the game ends and the gambler collects the current value of the pot. The gambler is certain to win at least 1 pound, the starting value of the pot, at the cost of m pounds, the initial fee.

The gambler cannot continue to play if his fortune falls below m pounds.
Let pm(s) denote the probability that the gambler will never run out of money in this lottery given his initial fortune s and the cost per game m.
For example p2(2) ≈ 0.2522, p2(5) ≈ 0.6873 and p6(10 000) ≈ 0.9952 (note: pm(s) = 0 for s < m).

Find p15(109) and give your answer rounded to 7 decimal places behind the decimal point in the form 0.abcdefg.
*/

void Problem_499(void)
{

}

/*
Eight Divisors
Problem 501
The eight divisors of 24 are 1, 2, 3, 4, 6, 8, 12 and 24.
The ten numbers not exceeding 100 having exactly eight divisors are 24, 30, 40, 42, 54, 56, 66, 70, 78 and 88.
Let f(n) be the count of numbers not exceeding n with exactly eight divisors.
You are given f(100) = 10, f(1000) = 180 and f(10^6) = 224427.
Find f(10^12).
*/

void Problem_500(void)
{
	// bruteforce solution is probably not an option
	// 24: 1 * 2 * 3 * 4 *  6 *  8 * 12 *  24: 2*2*2*3
	// 30: 1 * 2 * 3 * 5 *  6 * 10 * 15 *  30: 2*3*5
	// 40: 1 * 2 * 4 * 5 *  8 * 10 * 20 *  40: 2*2*2*5
	// 42: 1 * 2 * 3 * 6 *  7 * 14 * 21 *  42: 2*3*7
	// 54: 1 * 2 * 3 * 6 *  9 * 18 * 27 *  54: 2*3*3*3
	// 56: 1 * 2 *  
	// 66: 1 * 2 * 
	// 70: 1 * 2 * 5 * 7 * 10 * 14 * 35 *  70: 2*5*7
	// 78: 1 * 2 * 
	// 88: 1 * 2 * 
	// ...
	// 104: 1 * 2 * 3 * 6 * 17 * 34 * 51 * 104: 2*3*17
	// ...
	// 128: 1 * 2 * 4 * 8 * 16 * 32 * 64 * 128: 2*2*2*2*2*2*2
	// ...
	// 2187: 1 * 3 * 9 * 27 * 81 * 243 * 729 * 2187: 3*3*3*3*3*3*3

	// solution:
	// prepare the list of prime numbers and then:
	// find all 7-elemnets: n*n*n*n*n*n*n
	// fina all 4-elements: n*n*n*m
	// find all 3-elements: n*m*o
	// that are less than 10^12
	// where n, m, o are prime numbers

	// add sieve of Erastothenes for prime numbers generation (with static vector of prime numbers and static flag that checks if it was already invoked)
	// or create appropriate class

	int64_t upperBound = 1000;

	int countOfNumbers = 0;

	int64_t maxPrimeNumberRequired = upperBound / (2 * 3);	// because 2*3*prime_number < upperBound

	// idea:
	// the for loop is not required - it is enough to find the largest prime_number for each triplet - then all lesser prime numbers can also be counted for that triplet
	// eg. we have to find prime number that is closest to upperBound/(2*3)
}