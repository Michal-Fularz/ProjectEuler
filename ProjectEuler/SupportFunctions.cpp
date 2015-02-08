#include "SupportFunctions.h"

int64_t FindNextPrimeNumber(int64_t currentPrimeNumber)
{
	int64_t newPrimeNumber = currentPrimeNumber;

	bool flagNewPrimeNumberFound = false;

	while (!flagNewPrimeNumberFound)
	{
		newPrimeNumber++;
		flagNewPrimeNumberFound = true;

		int64_t upperLimit = newPrimeNumber / 2;
		if (newPrimeNumber <= 4)
		{
			upperLimit = newPrimeNumber;
		}
		for (int i = 2; i < upperLimit; ++i)
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