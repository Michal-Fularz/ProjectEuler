#include "ProjectEuler.h"

#include <iostream>

#include <list>
#include <vector>
#include <set>

#include <algorithm>
#include <numeric>
#include <functional>

#include <string>

#include <Windows.h>

#include "SupportFunctions.h"

using std::cout;
using std::cin;
using std::endl;

/*
Largest product in a grid
Problem 11
In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

void Problem_011(void)
{
	std::string inputData = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

	const int gridSize = 20;
	std::vector<std::vector<int>> grid;
	const int sizeOfBest = 4;


	for (int i = 0; i < gridSize; i++)
	{
		std::vector<int> newVector;
		for (int j = 0; j < gridSize; j++)
		{
			int index = 3 * (i * 20 + j);
			int value = CharToInt(inputData[index]) * 10 + CharToInt(inputData[index + 1]);
			newVector.push_back(value);
		}
		grid.push_back(newVector);
	}

	// horizontal round
	int horizontalBestPositionI = 0;
	int horizontalBestPositionJ = 0;
	int horizontalBest = grid[horizontalBestPositionI][horizontalBestPositionJ] * grid[horizontalBestPositionI][horizontalBestPositionJ + 1] * grid[horizontalBestPositionI][horizontalBestPositionJ + 2] * grid[horizontalBestPositionI][horizontalBestPositionJ + 3];
	int horizontalCurrent = 1;
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < (gridSize - sizeOfBest); j++)
		{
			horizontalCurrent = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];

			if (horizontalCurrent > horizontalBest)
			{
				horizontalBest = horizontalCurrent;
				horizontalBestPositionI = i;
				horizontalBestPositionJ = j;
			}
		}
	}

	cout << "Horizontal best position: " << horizontalBest << ", at: " << horizontalBestPositionI << ", " << horizontalBestPositionJ << endl;

	// vertical round
	int verticalBestPositionI = 0;
	int verticalBestPositionJ = 0;
	int verticalBest = grid[verticalBestPositionI][verticalBestPositionJ] * grid[verticalBestPositionI + 1][verticalBestPositionJ] * grid[verticalBestPositionI + 2][verticalBestPositionJ] * grid[verticalBestPositionI + 3][verticalBestPositionJ];
	int verticalCurrent = 1;
	for (int i = 0; i < (gridSize - sizeOfBest); i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			verticalCurrent = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];

			if (verticalCurrent > verticalBest)
			{
				verticalBest = verticalCurrent;
				verticalBestPositionI = i;
				verticalBestPositionJ = j;
			}
		}
	}

	cout << "Vertical best position: " << verticalBest << ", at: " << verticalBestPositionI << ", " << verticalBestPositionJ << endl;

	// diagonally up-left to down-right, round
	int diagonally1BestPositionI = 0;
	int diagonally1BestPositionJ = 0;
	int diagonally1Best = grid[diagonally1BestPositionI][diagonally1BestPositionJ] * grid[diagonally1BestPositionI + 1][diagonally1BestPositionJ] * grid[diagonally1BestPositionI + 2][diagonally1BestPositionJ] * grid[diagonally1BestPositionI + 3][diagonally1BestPositionJ];
	int diagonally1Current = 1;
	for (int i = 0; i < (gridSize - sizeOfBest); i++)
	{
		for (int j = 0; j < (gridSize - sizeOfBest); j++)
		{
			diagonally1Current = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];

			if (diagonally1Current > diagonally1Best)
			{
				diagonally1Best = diagonally1Current;
				diagonally1BestPositionI = i;
				diagonally1BestPositionJ = j;
			}
		}
	}

	cout << "Diagonally up-left to down-right best position: " << diagonally1Best << ", at: " << diagonally1BestPositionI << ", " << diagonally1BestPositionJ << endl;

	// diagonally up-right to down-left, round
	int diagonally2BestPositionI = 0;
	int diagonally2BestPositionJ = 0;
	int diagonally2Best = grid[diagonally2BestPositionI][diagonally2BestPositionJ] * grid[diagonally2BestPositionI + 1][diagonally2BestPositionJ] * grid[diagonally2BestPositionI + 2][diagonally2BestPositionJ] * grid[diagonally2BestPositionI + 3][diagonally2BestPositionJ];
	int diagonally2Current = 1;
	for (int i = sizeOfBest; i < gridSize; i++)
	{
		for (int j = 0; j < (gridSize - sizeOfBest); j++)
		{
			diagonally2Current = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3];

			if (diagonally2Current > diagonally2Best)
			{
				diagonally2Best = diagonally2Current;
				diagonally2BestPositionI = i;
				diagonally2BestPositionJ = j;
			}
		}
	}

	cout << "Diagonally up-right to down-left best position: " << diagonally2Best << ", at: " << diagonally2BestPositionI << ", " << diagonally2BestPositionJ << endl;

	std::list<int> bestScore;
	bestScore.push_back(horizontalBest);
	bestScore.push_back(verticalBest);
	bestScore.push_back(diagonally1Best);
	bestScore.push_back(diagonally2Best);
	bestScore.sort();

	cout << "Best overall: " << bestScore.back() << endl;
}

/*
Highly divisible triangular number
Problem 12
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

1: 1
3: 1,3
6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
*/

void GetSmallerPart(int value, int maxValue, std::vector<int>& set)
{
	set.push_back(value);

	if (value < maxValue)
	{
		GetSmallerPart(value + 1, maxValue, set);
	}
}

std::vector<std::vector<int>> GeneratePermutations(int lowValue, int highValue)
{
	cout << "Permutations" << endl;
	std::vector<std::vector<int>> permutations;
	for (int startValue = lowValue; startValue < highValue; startValue++)
	{
		for (int endValue = startValue; endValue < highValue; endValue++)
		{
			std::vector<int> newPermutations;
			GetSmallerPart(startValue, endValue, newPermutations);

			for (auto item : newPermutations)
			{
				cout << item << ", ";
			}
			cout << endl;
		}
	}
	cout << endl;

	return permutations;
}

typedef uint64_t Problem_012_t;

Problem_012_t Multiplication(const std::vector<Problem_012_t>& data, int index, int maxIndex)
{
	Problem_012_t result = 1;

	if (index <= maxIndex)
	{
		result = data[index] * Multiplication(data, index + 1, maxIndex);
	}

	return result;
}

std::vector<Problem_012_t> AllPossibleMultiplicationsInSet(const std::vector<Problem_012_t>& data, Problem_012_t maxValueAllowed)
{
	std::vector<Problem_012_t> multiplications;

	int lowValue = 0;
	int highValue = data.size();

	for (int startValue = lowValue; startValue < highValue; startValue++)
	{
		for (int endValue = startValue + 1; endValue < highValue; endValue++)
		{
			// stupid recursive version
			//Problem_012_t newMultiplication = Multiplication(data, startValue, endValue);
			bool flagAddValue = true;
			Problem_012_t newMultiplication = 1;
			for (int i = startValue; i <= endValue; i++)
			{
				if (newMultiplication < maxValueAllowed)
				{
					newMultiplication *= data[i];
				}
				else
				{
					flagAddValue = false;
					break;
				}
			}

			if (flagAddValue)
			{
				multiplications.push_back(newMultiplication);
			}
		}
	}

	return multiplications;
}

void Problem_012(void)
{
	LARGE_INTEGER freq, start, end;
	double total = 0;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);

	Problem_012_t triangularNumber = 0;
	bool flagFound = false;
	// iterate through the triangular numbers
	Problem_012_t i = 1;
	while (!flagFound)
	{
		triangularNumber += i;
		i++;

		// 1 is special case factor! - take it into account
		std::vector<Problem_012_t> basicFactors;
		basicFactors.reserve(100);

		Problem_012_t value = triangularNumber;
		bool flagEnd = false;

		// first find all divisions by 2
		flagEnd = false;
		while (!flagEnd)
		{
			if ((value & 1) == 0)
			{
				// 2
				basicFactors.push_back(2);
				value = value / 2;
			}
			else
			{
				flagEnd = true;
			}
		}

		Problem_012_t currentFactor = 3;

		// then check all odd numbers starting from 3
		Problem_012_t conditionValue = (triangularNumber >> 1);
		// it is not necessary to test (currentFactor > value), eg. value = 41, currentFactor = 41 means that will be 1 so first condition will be sufficient
		while (!((value == 1) || (currentFactor > conditionValue)))
		{
			if ((value % currentFactor) == 0)
			{
				basicFactors.push_back(currentFactor);
				value = value / currentFactor;
			}
			else
			{
				currentFactor += 2;
			}
		}

		std::vector<Problem_012_t> extendedFactors = AllPossibleMultiplicationsInSet(basicFactors, triangularNumber / 2);

		basicFactors.push_back(1);
		basicFactors.push_back(triangularNumber);

		// first idea to generate two elements permutations - longer were problematic with this approach
		// then add all available permutations
		//for (int j = 0; j < factors.size(); j++)
		//{
		//	int newFactor = 1;
		//	for (int k = j+1; k < factors.size(); k++)
		//	{
		//		newFactor = factors[j] * factors[k];
		//		if (newFactor < (triangularNumber / 2))
		//		{
		//			extendedFactors.insert(newFactor);
		//		}
		//	}
		//}

		std::set<Problem_012_t> uniqueFactors;
		// copy all factors (without dupilcates) to set
		for (auto item : basicFactors)
		{
			uniqueFactors.insert(item);
		}
		// copy all multiplications of factors (without dupilcates) to set
		for (auto item : extendedFactors)
		{
			uniqueFactors.insert(item);
		}

		if (uniqueFactors.size() >= 100)
		{
			cout << "Triangular number: " << triangularNumber << endl;

			//cout << "Basic factors: " << endl;
			//for (auto item : basicFactors)
			//{
			//	cout << item << ", ";
			//}
			//cout << endl;

			//cout << "Factors multiplications: " << endl;
			//for (auto item : extendedFactors)
			//{
			//	cout << item << ", ";
			//}
			//cout << endl;

			//cout << "All factors: " << endl;
			//for (auto item : uniqueFactors)
			//{
			//	cout << item << ", ";
			//}
			//cout << endl;

			flagFound = true;
		}
	}

	QueryPerformanceCounter(&end);

	total += (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
	cout << "Total time: " << total << endl;
}