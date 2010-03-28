static int
NAME (const int *arr, int n, int key)
{
	int min = 0, max = n;
#ifdef LINEAR_FALLBACK
	while (min + LINEAR_FALLBACK < max) {
#else
	while (min < max) {
#endif
#include "binary-step.h"
	}
#ifdef LINEAR_FALLBACK
#if LINEAR_FALLBACK < 4
	return linear (arr + min, max - min, key) + min;
#else
	return linear_4 (arr + min, max - min, key) + min;
#endif
#else
	return min;
#endif
}

#undef NAME
#undef CMOV
#undef LINEAR_FALLBACK
