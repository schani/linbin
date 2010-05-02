#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

#include "linear-simd-paulr.h"

#endif

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
	DECLARE_FUNC (linear_sse2_paulr),
#endif
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
			for (i = 0; i < n; ++i)
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
			searches [i] = random () % (max_n);

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
