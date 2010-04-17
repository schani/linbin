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
	int i = min;
	n = max;
#if LINEAR_FALLBACK >= 4
#define UNROLL4
#endif
#include "linear-loop.h"
	return i;
#else
	return min;
#endif
}

#undef NAME
#undef CMOV
#undef LINEAR_FALLBACK
