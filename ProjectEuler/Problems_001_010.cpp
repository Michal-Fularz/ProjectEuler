#include "ProjectEuler.h"

#include <iostream>

using namespace std;

/*
Multiples of 3 and 5
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

void Problem_001_bruteforce(void)
{
	// simples, brute force solution
	const int upperBound = 1000;
	int sumOf3Or5Multiplies = 0;
	for (int i = 0; i < upperBound; ++i)
	{
		if (0 == i%3)
		{
			sumOf3Or5Multiplies += i;
		}
		else if (0 == i%5)
		{
			sumOf3Or5Multiplies += i;
		}
	}

	cout << sumOf3Or5Multiplies << endl;
}

void Problem_001(void)
{
	const int upperBound = 1000;
	int sumOf3Or5Multiplies = 0;

	for (int i = 3; i < upperBound; i = i + 3)
	{
		sumOf3Or5Multiplies += i;
	}
	for (int i = 5; i < upperBound; i = i + 5)
	{
		sumOf3Or5Multiplies += i;
	}
	for (int i = 15; i < upperBound; i = i + 15)
	{
		sumOf3Or5Multiplies -= i;
	}

	cout << sumOf3Or5Multiplies << endl;
}

/*
Even Fibonacci numbers
Problem 2
Each new term in the Fibonacci sequence is generated by adding the previous two terms.By starting with 1 and 2, the first 10 terms will be :

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even - valued terms.
*/

void Problem_002(void)
{
	int previousElement = 1;
	int currentElement = 2;

	int sumOfFibonacciEvenValuedTerms = previousElement;

	while (currentElement < 4000000)
	{
		int temp = currentElement;
		currentElement = currentElement + previousElement;
		previousElement = temp;

		if (1 == currentElement % 2)
		{
			sumOfFibonacciEvenValuedTerms += currentElement;
		}
	}

	cout << sumOfFibonacciEvenValuedTerms << endl;
}

/*
Largest prime factor
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

static long findNextPrimeNumber(long currentPrimeNumber)
{
	long newPrimeNumber = currentPrimeNumber;

	bool flagNewPrimeNumberFound = false;

	while (!flagNewPrimeNumberFound)
	{
		newPrimeNumber++;
		flagNewPrimeNumberFound = true;

		long upperLimit = newPrimeNumber / 2;
		if (newPrimeNumber < 4)
		{
			upperLimit = newPrimeNumber;
		}
		for (int i = 2; i < newPrimeNumber/2; ++i)
		{
			if (newPrimeNumber % i == 0)
			{
				flagNewPrimeNumberFound = false;
				break;
			}
		}
	}

	return newPrimeNumber;
}

#include <list>

void Problem_003(void)
{
	long long valueToCheck = 600851475143; // 13195;

	long long currentPrimeNumber = 2;

	list<long long> listOfPrimeFactors;

	// testing findNextPrimeNumber function 
	/*
	int primeNumber = 1;
	for (int i = 0; i < 50; ++i)
	{
		primeNumber = findNextPrimeNumber(primeNumber);
		cout << primeNumber << endl;
	}
	*/

	while (currentPrimeNumber <= valueToCheck)
	{
		if (0 == (valueToCheck % currentPrimeNumber))
		{
			listOfPrimeFactors.push_front(currentPrimeNumber);
			valueToCheck = valueToCheck / currentPrimeNumber;
			cout << listOfPrimeFactors.front() << endl;
		}
		currentPrimeNumber = findNextPrimeNumber(currentPrimeNumber);	
	}
}

/*
Largest palindrome product
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 � 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

void Problem_004(void)
{
	char valueAsString[7];
	// bruteforce powa!
	for (int i = 999; i > 99; --i)
	{
		bool flagIsPalindrom = false;

		for (int j = 999; j > 99; --j)
		{
			int product = i*j;
			itoa(product, valueAsString, 10);
			int length = strlen(valueAsString);
			flagIsPalindrom = true;
			for (int k = 0; k < length / 2; ++k)
			{
				if (valueAsString[k] != valueAsString[length - (k+1)])
				{
					flagIsPalindrom = false;
					break;
				}
			}

			if (flagIsPalindrom)
			{
				cout << i << ", " << j << endl;
				break;
			}
		}
		if (flagIsPalindrom)
		{
			break;
		}
	}
}
