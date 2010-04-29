static int
NAME (const int *arr, int n, int key)
{
	int i = 0;

#ifdef PRELOAD
#include "linear-sentinel-preload-loop.h"
#else
#include "linear-sentinel-loop.h"
#endif

	return i;
}

#undef NAME
#undef PRELOAD
