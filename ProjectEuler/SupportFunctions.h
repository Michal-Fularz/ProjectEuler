#ifndef SUPPORT_FUNCTIONS_H_
#define SUPPORT_FUNCTIONS_H_

#include <cstdint>

int64_t FindNextPrimeNumber(int64_t currentPrimeNumber);

inline int CharToInt(const char& value)
{
	return (value - '0');
}

#endif // SUPPORT_FUNCTIONS_H_