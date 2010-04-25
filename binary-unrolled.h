static int
NAME (const int *arr, int n, int key)
{
    int min = 0, max = n;

#if LOOPS >= 1
#include "binary-step.h"
#endif
#if LOOPS >= 2
#include "binary-step.h"
#endif
#if LOOPS >= 3
#include "binary-step.h"
#endif
#if LOOPS >= 4
#include "binary-step.h"
#endif
#if LOOPS >= 5
#include "binary-step.h"
#endif
#if LOOPS >= 6
#include "binary-step.h"
#endif
#if LOOPS >= 7
#include "binary-step.h"
#endif
#if LOOPS >= 8
#include "binary-step.h"
#endif
#if LOOPS >= 9
#include "binary-step.h"
#endif
#if LOOPS >= 10
#include "binary-step.h"
#endif
#if LOOPS >= 11
#include "binary-step.h"
#endif
#if LOOPS >= 12
#include "binary-step.h"
#endif
#if LOOPS >= 13
#include "binary-step.h"
#endif
#if LOOPS >= 14
#include "binary-step.h"
#endif
#if LOOPS >= 15
#include "binary-step.h"
#endif
#if LOOPS >= 16
#include "binary-step.h"
#endif
#if LOOPS >= 17
#include "binary-step.h"
#endif
#if LOOPS >= 18
#include "binary-step.h"
#endif
#if LOOPS >= 19
#include "binary-step.h"
#endif
#if LOOPS >= 20
#include "binary-step.h"
#endif
#if LOOPS >= 21
#include "binary-step.h"
#endif
#if LOOPS >= 22
#include "binary-step.h"
#endif
#if LOOPS >= 23
#include "binary-step.h"
#endif
#if LOOPS >= 24
#include "binary-step.h"
#endif
#if LOOPS >= 25
#include "binary-step.h"
#endif
#if LOOPS >= 26
#include "binary-step.h"
#endif
#if LOOPS >= 27
#include "binary-step.h"
#endif
#if LOOPS >= 28
#include "binary-step.h"
#endif
#if LOOPS >= 29
#include "binary-step.h"
#endif
#if LOOPS >= 30
#include "binary-step.h"
#endif
#if LOOPS >= 31
#error Cannot unroll more than 30 binary loops
#endif

#if defined(LINEAR_FINISH)
    int i = min;
    n = max;
#include "linear-loop.h"
    return i;
#elif defined(LINEAR_SENTINEL_FINISH)
    int i = min;
#include "linear-sentinel-loop.h"
    return i;
#else
    if (min == max)
	return min;
    if (arr [min] >= key)
	return min;
    return min + 1;
#endif
}

#undef NAME
#undef LOOPS
#undef LINEAR_FINISH
