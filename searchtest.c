#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "returns.h"

#if defined (__x86_64) || defined (__i386)
#define HAVE_CMOV
#endif

#define NAME linear
#include "linear.h"

#define NAME linear_2
#define UNROLL2
#include "linear.h"

#define NAME linear_4
#define UNROLL4
#include "linear.h"

#define NAME linear_42
#define UNROLL4
#define UNROLL2
#include "linear.h"

#define NAME linear_84
#define UNROLL8
#define UNROLL4
#include "linear.h"

#define NAME linear_sentinel
#include "linear-sentinel.h"

#define NAME linear_sentinel_2
#define UNROLL2
#include "linear-sentinel.h"

#define NAME linear_sentinel_4
#define UNROLL4
#include "linear-sentinel.h"

#define NAME linear_sentinel_8
#define UNROLL8
#include "linear-sentinel.h"

#define NAME linear_sentinel_16
#define UNROLL16
#include "linear-sentinel.h"

#define NAME linear_sentinel_32
#define UNROLL32
#include "linear-sentinel.h"

#define NAME linear_sentinel_32_preload_4
#define PRELOAD
#include "linear-sentinel.h"

#ifdef __SSE2__

#define NAME linear_sentinel_sse2
#include "linear-sentinel-simd.h"

#define NAME linear_sentinel_sse2_2
#define UNROLL2
#include "linear-sentinel-simd.h"

#define NAME linear_sentinel_sse2_4
#define UNROLL4
#include "linear-sentinel-simd.h"

#define NAME linear_sentinel_sse2_8
#define UNROLL8
#include "linear-sentinel-simd.h"

#define NAME linear_sentinel_sse2_nobranch
#define NO_BRANCH
#include "linear-sentinel-simd.h"

#endif

static int
linear_static_unrolled (const int *arr, int n, int key)
{
#define RETURN(i)	return i
#include "linear-static-unrolled.h"
#undef RETURN
	assert (0);
	return -1;
}

static int
linear_static_unrolled_indirect (const int *arr, int n, int key)
{
#define RETURN(i)	return return_ ## i ()
#include "linear-static-unrolled.h"
#undef RETURN
	assert (0);
	return -1;
}

#define NAME binary
#include "binary.h"

#ifdef HAVE_CMOV

#define NAME binary_cmov
#define CMOV
#include "binary.h"

#define NAME binary_cmov_lin1
#define CMOV
#define LINEAR_FALLBACK	1
#include "binary.h"

#define NAME binary_cmov_lin2
#define CMOV
#define LINEAR_FALLBACK	2
#include "binary.h"

#define NAME binary_cmov_lin4
#define CMOV
#define LINEAR_FALLBACK	4
#include "binary.h"

#define NAME binary_cmov_lin8
#define CMOV
#define LINEAR_FALLBACK	8
#include "binary.h"

#define NAME binary_cmov_lin16
#define CMOV
#define LINEAR_FALLBACK	16
#include "binary.h"

#define NAME binary_cmov_lin32
#define CMOV
#define LINEAR_FALLBACK	32
#include "binary.h"

#define NAME binary_cmov_unrolled0
#define CMOV
#define LOOPS 0
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled1
#define CMOV
#define LOOPS 1
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled2
#define CMOV
#define LOOPS 2
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled3
#define CMOV
#define LOOPS 3
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled4
#define CMOV
#define LOOPS 4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled5
#define CMOV
#define LOOPS 5
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled6
#define CMOV
#define LOOPS 6
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled7
#define CMOV
#define LOOPS 7
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled8
#define CMOV
#define LOOPS 8
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled9
#define CMOV
#define LOOPS 9
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled10
#define CMOV
#define LOOPS 10
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled11
#define CMOV
#define LOOPS 11
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled12
#define CMOV
#define LOOPS 12
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled13
#define CMOV
#define LOOPS 13
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled14
#define CMOV
#define LOOPS 14
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled15
#define CMOV
#define LOOPS 15
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled16
#define CMOV
#define LOOPS 16
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled17
#define CMOV
#define LOOPS 17
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled18
#define CMOV
#define LOOPS 18
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled19
#define CMOV
#define LOOPS 19
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled20
#define CMOV
#define LOOPS 20
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled21
#define CMOV
#define LOOPS 21
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled22
#define CMOV
#define LOOPS 22
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled23
#define CMOV
#define LOOPS 23
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled24
#define CMOV
#define LOOPS 24
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled25
#define CMOV
#define LOOPS 25
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled26
#define CMOV
#define LOOPS 26
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled27
#define CMOV
#define LOOPS 27
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled28
#define CMOV
#define LOOPS 28
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled29
#define CMOV
#define LOOPS 29
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled30
#define CMOV
#define LOOPS 30
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled1_linear4
#define CMOV
#define LOOPS 1
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled2_linear4
#define CMOV
#define LOOPS 2
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled3_linear4
#define CMOV
#define LOOPS 3
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled4_linear4
#define CMOV
#define LOOPS 4
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled5_linear4
#define CMOV
#define LOOPS 5
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled6_linear4
#define CMOV
#define LOOPS 6
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled7_linear4
#define CMOV
#define LOOPS 7
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled8_linear4
#define CMOV
#define LOOPS 8
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled9_linear4
#define CMOV
#define LOOPS 9
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled10_linear4
#define CMOV
#define LOOPS 10
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled11_linear4
#define CMOV
#define LOOPS 11
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled12_linear4
#define CMOV
#define LOOPS 12
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled13_linear4
#define CMOV
#define LOOPS 13
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled14_linear4
#define CMOV
#define LOOPS 14
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled15_linear4
#define CMOV
#define LOOPS 15
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled16_linear4
#define CMOV
#define LOOPS 16
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled17_linear4
#define CMOV
#define LOOPS 17
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled18_linear4
#define CMOV
#define LOOPS 18
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled19_linear4
#define CMOV
#define LOOPS 19
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled20_linear4
#define CMOV
#define LOOPS 20
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled21_linear4
#define CMOV
#define LOOPS 21
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled22_linear4
#define CMOV
#define LOOPS 22
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled23_linear4
#define CMOV
#define LOOPS 23
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled24_linear4
#define CMOV
#define LOOPS 24
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled25_linear4
#define CMOV
#define LOOPS 25
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled26_linear4
#define CMOV
#define LOOPS 26
#define LINEAR_FINISH
#define UNROLL4
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled1_linear_sentinel32
#define CMOV
#define LOOPS 1
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled2_linear_sentinel32
#define CMOV
#define LOOPS 2
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled3_linear_sentinel32
#define CMOV
#define LOOPS 3
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled4_linear_sentinel32
#define CMOV
#define LOOPS 4
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled5_linear_sentinel32
#define CMOV
#define LOOPS 5
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled6_linear_sentinel32
#define CMOV
#define LOOPS 6
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled7_linear_sentinel32
#define CMOV
#define LOOPS 7
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled8_linear_sentinel32
#define CMOV
#define LOOPS 8
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled9_linear_sentinel32
#define CMOV
#define LOOPS 9
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled10_linear_sentinel32
#define CMOV
#define LOOPS 10
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled11_linear_sentinel32
#define CMOV
#define LOOPS 11
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled12_linear_sentinel32
#define CMOV
#define LOOPS 12
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled13_linear_sentinel32
#define CMOV
#define LOOPS 13
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled14_linear_sentinel32
#define CMOV
#define LOOPS 14
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled15_linear_sentinel32
#define CMOV
#define LOOPS 15
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled16_linear_sentinel32
#define CMOV
#define LOOPS 16
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled17_linear_sentinel32
#define CMOV
#define LOOPS 17
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled18_linear_sentinel32
#define CMOV
#define LOOPS 18
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled19_linear_sentinel32
#define CMOV
#define LOOPS 19
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled20_linear_sentinel32
#define CMOV
#define LOOPS 20
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled21_linear_sentinel32
#define CMOV
#define LOOPS 21
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled22_linear_sentinel32
#define CMOV
#define LOOPS 22
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled23_linear_sentinel32
#define CMOV
#define LOOPS 23
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled24_linear_sentinel32
#define CMOV
#define LOOPS 24
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled25_linear_sentinel32
#define CMOV
#define LOOPS 25
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define NAME binary_cmov_unrolled26_linear_sentinel32
#define CMOV
#define LOOPS 26
#define LINEAR_SENTINEL_FINISH
#define UNROLL32
#include "binary-unrolled.h"

#define GEN_NAME(s,i)	binary_static_unrolled_ ## i
#define RETURN(i)	return i
#include "binary-static-unrolled.h"

#endif

typedef int (*search_func_t) (const int *arr, int n, int key);
typedef search_func_t (*get_search_func_t) (int n);

#ifdef HAVE_CMOV

static search_func_t
get_binary_cmov_unrolled (int n)
{
	if (n < (1 << 1)) return binary_cmov_unrolled0;
	if (n < (1 << 2)) return binary_cmov_unrolled1;
	if (n < (1 << 3)) return binary_cmov_unrolled2;
	if (n < (1 << 4)) return binary_cmov_unrolled3;
	if (n < (1 << 5)) return binary_cmov_unrolled4;
	if (n < (1 << 6)) return binary_cmov_unrolled5;
	if (n < (1 << 7)) return binary_cmov_unrolled6;
	if (n < (1 << 8)) return binary_cmov_unrolled7;
	if (n < (1 << 9)) return binary_cmov_unrolled8;
	if (n < (1 << 10)) return binary_cmov_unrolled9;
	if (n < (1 << 11)) return binary_cmov_unrolled10;
	if (n < (1 << 12)) return binary_cmov_unrolled11;
	if (n < (1 << 13)) return binary_cmov_unrolled12;
	if (n < (1 << 14)) return binary_cmov_unrolled13;
	if (n < (1 << 15)) return binary_cmov_unrolled14;
	if (n < (1 << 16)) return binary_cmov_unrolled15;
	if (n < (1 << 17)) return binary_cmov_unrolled16;
	if (n < (1 << 18)) return binary_cmov_unrolled17;
	if (n < (1 << 19)) return binary_cmov_unrolled18;
	if (n < (1 << 20)) return binary_cmov_unrolled19;
	if (n < (1 << 21)) return binary_cmov_unrolled20;
	if (n < (1 << 22)) return binary_cmov_unrolled21;
	if (n < (1 << 23)) return binary_cmov_unrolled22;
	if (n < (1 << 24)) return binary_cmov_unrolled23;
	if (n < (1 << 25)) return binary_cmov_unrolled24;
	if (n < (1 << 26)) return binary_cmov_unrolled25;
	if (n < (1 << 27)) return binary_cmov_unrolled26;
	if (n < (1 << 28)) return binary_cmov_unrolled27;
	if (n < (1 << 29)) return binary_cmov_unrolled28;
	if (n < (1 << 30)) return binary_cmov_unrolled29;
	if (n < (1 << 31)) return binary_cmov_unrolled30;
	assert (0);
}

static search_func_t
get_binary_cmov_unrolled_linear (int n)
{
	if (n < (1 << 1)) return linear_sentinel_32;
	if (n < (1 << 2)) return linear_sentinel_32;
	if (n < (1 << 3)) return linear_sentinel_32;
	if (n < (1 << 4)) return linear_sentinel_32;
	if (n < (1 << 5)) return linear_sentinel_32;
	if (n < (1 << 6)) return binary_cmov_unrolled1_linear4;
	if (n < (1 << 7)) return binary_cmov_unrolled2_linear4;
	if (n < (1 << 8)) return binary_cmov_unrolled3_linear4;
	if (n < (1 << 9)) return binary_cmov_unrolled4_linear4;
	if (n < (1 << 10)) return binary_cmov_unrolled5_linear4;
	if (n < (1 << 11)) return binary_cmov_unrolled6_linear4;
	if (n < (1 << 12)) return binary_cmov_unrolled7_linear4;
	if (n < (1 << 13)) return binary_cmov_unrolled8_linear4;
	if (n < (1 << 14)) return binary_cmov_unrolled9_linear4;
	if (n < (1 << 15)) return binary_cmov_unrolled10_linear4;
	if (n < (1 << 16)) return binary_cmov_unrolled11_linear4;
	if (n < (1 << 17)) return binary_cmov_unrolled12_linear4;
	if (n < (1 << 18)) return binary_cmov_unrolled13_linear4;
	if (n < (1 << 19)) return binary_cmov_unrolled14_linear4;
	if (n < (1 << 20)) return binary_cmov_unrolled15_linear4;
	if (n < (1 << 21)) return binary_cmov_unrolled16_linear4;
	if (n < (1 << 22)) return binary_cmov_unrolled17_linear4;
	if (n < (1 << 23)) return binary_cmov_unrolled18_linear4;
	if (n < (1 << 24)) return binary_cmov_unrolled19_linear4;
	if (n < (1 << 25)) return binary_cmov_unrolled20_linear4;
	if (n < (1 << 26)) return binary_cmov_unrolled21_linear4;
	if (n < (1 << 27)) return binary_cmov_unrolled22_linear4;
	if (n < (1 << 28)) return binary_cmov_unrolled23_linear4;
	if (n < (1 << 29)) return binary_cmov_unrolled24_linear4;
	if (n < (1 << 30)) return binary_cmov_unrolled25_linear4;
	if (n < (1 << 31)) return binary_cmov_unrolled26_linear4;
	assert (0);
}

static search_func_t
get_binary_cmov_unrolled_linear_sentinel (int n)
{
	if (n < (1 << 1)) return linear_sentinel_32;
	if (n < (1 << 2)) return linear_sentinel_32;
	if (n < (1 << 3)) return linear_sentinel_32;
	if (n < (1 << 4)) return linear_sentinel_32;
	if (n < (1 << 5)) return linear_sentinel_32;
	if (n < (1 << 6)) return binary_cmov_unrolled1_linear_sentinel32;
	if (n < (1 << 7)) return binary_cmov_unrolled2_linear_sentinel32;
	if (n < (1 << 8)) return binary_cmov_unrolled3_linear_sentinel32;
	if (n < (1 << 9)) return binary_cmov_unrolled4_linear_sentinel32;
	if (n < (1 << 10)) return binary_cmov_unrolled5_linear_sentinel32;
	if (n < (1 << 11)) return binary_cmov_unrolled6_linear_sentinel32;
	if (n < (1 << 12)) return binary_cmov_unrolled7_linear_sentinel32;
	if (n < (1 << 13)) return binary_cmov_unrolled8_linear_sentinel32;
	if (n < (1 << 14)) return binary_cmov_unrolled9_linear_sentinel32;
	if (n < (1 << 15)) return binary_cmov_unrolled10_linear_sentinel32;
	if (n < (1 << 16)) return binary_cmov_unrolled11_linear_sentinel32;
	if (n < (1 << 17)) return binary_cmov_unrolled12_linear_sentinel32;
	if (n < (1 << 18)) return binary_cmov_unrolled13_linear_sentinel32;
	if (n < (1 << 19)) return binary_cmov_unrolled14_linear_sentinel32;
	if (n < (1 << 20)) return binary_cmov_unrolled15_linear_sentinel32;
	if (n < (1 << 21)) return binary_cmov_unrolled16_linear_sentinel32;
	if (n < (1 << 22)) return binary_cmov_unrolled17_linear_sentinel32;
	if (n < (1 << 23)) return binary_cmov_unrolled18_linear_sentinel32;
	if (n < (1 << 24)) return binary_cmov_unrolled19_linear_sentinel32;
	if (n < (1 << 25)) return binary_cmov_unrolled20_linear_sentinel32;
	if (n < (1 << 26)) return binary_cmov_unrolled21_linear_sentinel32;
	if (n < (1 << 27)) return binary_cmov_unrolled22_linear_sentinel32;
	if (n < (1 << 28)) return binary_cmov_unrolled23_linear_sentinel32;
	if (n < (1 << 29)) return binary_cmov_unrolled24_linear_sentinel32;
	if (n < (1 << 30)) return binary_cmov_unrolled25_linear_sentinel32;
	if (n < (1 << 31)) return binary_cmov_unrolled26_linear_sentinel32;
	assert (0);
}

#endif

static search_func_t
get_binary_static_unrolled (int n)
{
	if (n <= 0) return binary_static_unrolled_0;
	if (n <= 1) return binary_static_unrolled_1;
	if (n <= 2) return binary_static_unrolled_2;
	if (n <= 3) return binary_static_unrolled_3;
	if (n <= 4) return binary_static_unrolled_4;
	if (n <= 5) return binary_static_unrolled_5;
	if (n <= 6) return binary_static_unrolled_6;
	if (n <= 7) return binary_static_unrolled_7;
	if (n <= 8) return binary_static_unrolled_8;
	if (n <= 9) return binary_static_unrolled_9;
	if (n <= 10) return binary_static_unrolled_10;
	if (n <= 11) return binary_static_unrolled_11;
	if (n <= 12) return binary_static_unrolled_12;
	if (n <= 13) return binary_static_unrolled_13;
	if (n <= 14) return binary_static_unrolled_14;
	if (n <= 15) return binary_static_unrolled_15;
	if (n <= 16) return binary_static_unrolled_16;
	if (n <= 17) return binary_static_unrolled_17;
	if (n <= 18) return binary_static_unrolled_18;
	if (n <= 19) return binary_static_unrolled_19;
	if (n <= 20) return binary_static_unrolled_20;
	if (n <= 21) return binary_static_unrolled_21;
	if (n <= 22) return binary_static_unrolled_22;
	if (n <= 23) return binary_static_unrolled_23;
	if (n <= 24) return binary_static_unrolled_24;
	if (n <= 25) return binary_static_unrolled_25;
	if (n <= 26) return binary_static_unrolled_26;
	if (n <= 27) return binary_static_unrolled_27;
	if (n <= 28) return binary_static_unrolled_28;
	if (n <= 29) return binary_static_unrolled_29;
	if (n <= 30) return binary_static_unrolled_30;
	if (n <= 31) return binary_static_unrolled_31;
	if (n <= 32) return binary_static_unrolled_32;
	if (n <= 33) return binary_static_unrolled_33;
	if (n <= 34) return binary_static_unrolled_34;
	if (n <= 35) return binary_static_unrolled_35;
	if (n <= 36) return binary_static_unrolled_36;
	if (n <= 37) return binary_static_unrolled_37;
	if (n <= 38) return binary_static_unrolled_38;
	if (n <= 39) return binary_static_unrolled_39;
	if (n <= 40) return binary_static_unrolled_40;
	if (n <= 41) return binary_static_unrolled_41;
	if (n <= 42) return binary_static_unrolled_42;
	if (n <= 43) return binary_static_unrolled_43;
	if (n <= 44) return binary_static_unrolled_44;
	if (n <= 45) return binary_static_unrolled_45;
	if (n <= 46) return binary_static_unrolled_46;
	if (n <= 47) return binary_static_unrolled_47;
	if (n <= 48) return binary_static_unrolled_48;
	if (n <= 49) return binary_static_unrolled_49;
	if (n <= 50) return binary_static_unrolled_50;
	if (n <= 51) return binary_static_unrolled_51;
	if (n <= 52) return binary_static_unrolled_52;
	if (n <= 53) return binary_static_unrolled_53;
	if (n <= 54) return binary_static_unrolled_54;
	if (n <= 55) return binary_static_unrolled_55;
	if (n <= 56) return binary_static_unrolled_56;
	if (n <= 57) return binary_static_unrolled_57;
	if (n <= 58) return binary_static_unrolled_58;
	if (n <= 59) return binary_static_unrolled_59;
	if (n <= 60) return binary_static_unrolled_60;
	if (n <= 61) return binary_static_unrolled_61;
	if (n <= 62) return binary_static_unrolled_62;
	if (n <= 63) return binary_static_unrolled_63;
	if (n <= 64) return binary_static_unrolled_64;
	if (n <= 65) return binary_static_unrolled_65;
	if (n <= 66) return binary_static_unrolled_66;
	if (n <= 67) return binary_static_unrolled_67;
	if (n <= 68) return binary_static_unrolled_68;
	if (n <= 69) return binary_static_unrolled_69;
	if (n <= 70) return binary_static_unrolled_70;
	if (n <= 71) return binary_static_unrolled_71;
	if (n <= 72) return binary_static_unrolled_72;
	if (n <= 73) return binary_static_unrolled_73;
	if (n <= 74) return binary_static_unrolled_74;
	if (n <= 75) return binary_static_unrolled_75;
	if (n <= 76) return binary_static_unrolled_76;
	if (n <= 77) return binary_static_unrolled_77;
	if (n <= 78) return binary_static_unrolled_78;
	if (n <= 79) return binary_static_unrolled_79;
	if (n <= 80) return binary_static_unrolled_80;
	if (n <= 81) return binary_static_unrolled_81;
	if (n <= 82) return binary_static_unrolled_82;
	if (n <= 83) return binary_static_unrolled_83;
	if (n <= 84) return binary_static_unrolled_84;
	if (n <= 85) return binary_static_unrolled_85;
	if (n <= 86) return binary_static_unrolled_86;
	if (n <= 87) return binary_static_unrolled_87;
	if (n <= 88) return binary_static_unrolled_88;
	if (n <= 89) return binary_static_unrolled_89;
	if (n <= 90) return binary_static_unrolled_90;
	if (n <= 91) return binary_static_unrolled_91;
	if (n <= 92) return binary_static_unrolled_92;
	if (n <= 93) return binary_static_unrolled_93;
	if (n <= 94) return binary_static_unrolled_94;
	if (n <= 95) return binary_static_unrolled_95;
	if (n <= 96) return binary_static_unrolled_96;
	if (n <= 97) return binary_static_unrolled_97;
	if (n <= 98) return binary_static_unrolled_98;
	if (n <= 99) return binary_static_unrolled_99;
	if (n <= 100) return binary_static_unrolled_100;
	if (n <= 101) return binary_static_unrolled_101;
	if (n <= 102) return binary_static_unrolled_102;
	if (n <= 103) return binary_static_unrolled_103;
	if (n <= 104) return binary_static_unrolled_104;
	if (n <= 105) return binary_static_unrolled_105;
	if (n <= 106) return binary_static_unrolled_106;
	if (n <= 107) return binary_static_unrolled_107;
	if (n <= 108) return binary_static_unrolled_108;
	if (n <= 109) return binary_static_unrolled_109;
	if (n <= 110) return binary_static_unrolled_110;
	if (n <= 111) return binary_static_unrolled_111;
	if (n <= 112) return binary_static_unrolled_112;
	if (n <= 113) return binary_static_unrolled_113;
	if (n <= 114) return binary_static_unrolled_114;
	if (n <= 115) return binary_static_unrolled_115;
	if (n <= 116) return binary_static_unrolled_116;
	if (n <= 117) return binary_static_unrolled_117;
	if (n <= 118) return binary_static_unrolled_118;
	if (n <= 119) return binary_static_unrolled_119;
	if (n <= 120) return binary_static_unrolled_120;
	if (n <= 121) return binary_static_unrolled_121;
	if (n <= 122) return binary_static_unrolled_122;
	if (n <= 123) return binary_static_unrolled_123;
	if (n <= 124) return binary_static_unrolled_124;
	if (n <= 125) return binary_static_unrolled_125;
	if (n <= 126) return binary_static_unrolled_126;
	if (n <= 127) return binary_static_unrolled_127;
	if (n <= 128) return binary_static_unrolled_128;
	assert (0);
	return NULL;
}

#define DECLARE_FUNC(name)	{ #name, name, NULL }
#define DECLARE_INIT(name)	{ #name, NULL, get_ ## name }

static struct { const char *name; search_func_t func; get_search_func_t init;} funcs [] = {
	DECLARE_FUNC (linear),
	DECLARE_FUNC (linear_2),
	DECLARE_FUNC (linear_4),
	DECLARE_FUNC (linear_42),
	DECLARE_FUNC (linear_84),
	DECLARE_FUNC (linear_sentinel),
	DECLARE_FUNC (linear_sentinel_2),
	DECLARE_FUNC (linear_sentinel_4),
	DECLARE_FUNC (linear_sentinel_8),
	DECLARE_FUNC (linear_sentinel_16),
	DECLARE_FUNC (linear_sentinel_32),
	DECLARE_FUNC (linear_sentinel_32_preload_4),
#ifdef __SSE2__
	DECLARE_FUNC (linear_sentinel_sse2),
	DECLARE_FUNC (linear_sentinel_sse2_2),
	DECLARE_FUNC (linear_sentinel_sse2_4),
	DECLARE_FUNC (linear_sentinel_sse2_8),
	DECLARE_FUNC (linear_sentinel_sse2_nobranch),
#endif
	DECLARE_FUNC (linear_static_unrolled),
	DECLARE_FUNC (linear_static_unrolled_indirect),
	DECLARE_FUNC (binary),
#ifdef HAVE_CMOV
	DECLARE_FUNC (binary_cmov),
	DECLARE_FUNC (binary_cmov_lin1),
	DECLARE_FUNC (binary_cmov_lin2),
	DECLARE_FUNC (binary_cmov_lin4),
	DECLARE_FUNC (binary_cmov_lin8),
	DECLARE_FUNC (binary_cmov_lin16),
	DECLARE_FUNC (binary_cmov_lin32),
	DECLARE_INIT (binary_cmov_unrolled),
	DECLARE_INIT (binary_cmov_unrolled_linear),
	DECLARE_INIT (binary_cmov_unrolled_linear_sentinel),
#endif
	DECLARE_INIT (binary_static_unrolled),
	{ NULL, NULL, NULL }
};

int
main (int argc, const char *argv [])
{
	int num_bench_runs;
	const char *name;
	search_func_t func = NULL;
	get_search_func_t init = NULL;
	int max_n;
	int *arr;
	int i, n;

	assert (argc == 2 || argc == 4);

	if (argc == 2) {
		assert (strcmp (argv [1], "--list") == 0);

		for (i = 0; funcs [i].name != NULL; ++i)
			printf ("%s\n", funcs [i].name);

		return 0;
	}

	/* test or benchmark? */
	if (strcmp (argv [1], "test") == 0)
		num_bench_runs = -1;
	else
		num_bench_runs = atoi (argv [1]);

	/* search func */
	name = argv [2];
	for (i = 0; funcs [i].name != NULL; ++i) {
		if (strcmp (name, funcs [i].name) == 0) {
			func = funcs [i].func;
			init = funcs [i].init;
		}
	}
	assert (func != NULL || init != NULL);

	/* max_n */
	max_n = atoi (argv [3]);

	/* alloc array */
	/* plus 1 for the sentinel, plus 16 for preload/simd, plus 15 for alignment */
	arr = (int*) malloc (sizeof (int) * (max_n + 1 + 16 + 15));

	/* align */
	arr = (int*) (((unsigned long)arr + 15) & ~0xfL);

	if (num_bench_runs < 0) {
		/* init invalidated array */
		for (i = 0; i < max_n; ++i)
			arr [i] = -1;

		for (n = 0; n <= max_n; ++n) {
			arr [n] = INT_MAX; /* sentinel */

			if (init)
				func = init (n);
			for (i = 0; i <= n; ++i)
				assert (func (arr, n, i) == i);

			/* init array step */
			arr [n] = n;
		}
	} else {
		int n_searches;
		int *searches;
		int s;

		/* init array */
		for (i = 0; i < max_n; ++i)
			arr [i] = i;
		arr [max_n] = INT_MAX;

		/* init searches */
		if (max_n < 100000)
		    n_searches = max_n;
		else
		    n_searches = 100000;
		searches = (int*) malloc (sizeof (int) * n_searches);
		for (i = 0; i < n_searches; ++i)
			searches [i] = random () % (max_n + 1);

		if (init)
			func = init (max_n);

		n = 0;
		s = 0;
		for (i = 0; i < num_bench_runs; ++i) {
			n += func (arr, max_n, searches [s]);
			if (++s == n_searches)
				s = 0;
		}

		printf ("%d\n", n);
	}

	return 0;
}
