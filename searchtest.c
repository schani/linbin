#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

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

#define NAME binary
#include "binary.h"

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

typedef int (*search_func_t) (const int *arr, int n, int key);

#define DECLARE_FUNC(name)	{ #name, name }

static struct { const char *name; search_func_t func; } funcs [] = {
	DECLARE_FUNC (linear),
	DECLARE_FUNC (linear_2),
	DECLARE_FUNC (linear_4),
	DECLARE_FUNC (linear_42),
	DECLARE_FUNC (linear_84),
	DECLARE_FUNC (binary),
	DECLARE_FUNC (binary_cmov),
	DECLARE_FUNC (binary_cmov_lin1),
	DECLARE_FUNC (binary_cmov_lin2),
	DECLARE_FUNC (binary_cmov_lin4),
	DECLARE_FUNC (binary_cmov_lin8),
	DECLARE_FUNC (binary_cmov_lin16),
	DECLARE_FUNC (binary_cmov_lin32),
	{ NULL, NULL }
};

int
main (int argc, const char *argv [])
{
	int num_bench_runs;
	const char *name;
	search_func_t func = NULL;
	int max_n;
	int *arr;
	int i, n;

	assert (argc == 4);

	/* test or benchmark? */
	if (strcmp (argv [1], "test") == 0)
		num_bench_runs = -1;
	else
		num_bench_runs = atoi (argv [1]);

	/* search func */
	name = argv [2];
	for (i = 0; funcs [i].name != NULL; ++i) {
		if (strcmp (name, funcs [i].name) == 0)
			func = funcs [i].func;
	}
	assert (func != NULL);

	/* max_n */
	max_n = atoi (argv [3]);

	/* init array */
	arr = (int*) malloc (sizeof (int) * max_n);
	for (i = 0; i < max_n; ++i)
		arr [i] = i;

	if (num_bench_runs < 0) {
		for (n = 0; n <= max_n; ++n) {
			for (i = 0; i <= n; ++i)
				assert (func (arr, n, i) == i);
		}
	} else {
		int n_searches;
		int *searches;
		int s;

		/* init searches */
		if (max_n < 100000)
		    n_searches = max_n;
		else
		    n_searches = 100000;
		searches = (int*) malloc (sizeof (int) * n_searches);
		for (i = 0; i < n_searches; ++i)
			searches [i] = random () % (max_n + 1);

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
