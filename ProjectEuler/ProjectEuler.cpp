#include <iostream>

#include "ProjectEuler.h"

int main(void)
{
	std::cout << "Project Euler go go go!" << std::endl;

	//Problem_001_bruteforce();
	//Problem_001();

	Problem_002();


	std::cin.sync();		// Flush The Input Buffer Just In Case
	std::cin.ignore();		// There's No Need To Actually Store The Users Input

	return 0;
}