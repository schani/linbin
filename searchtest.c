#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define NAME linear
#define UNROLL4
#define UNROLL2
#include "linear.h"

#define NAME binary
#define CMOV
#include "binary.h"

#define N_SEARCHES	128
#define MAX_N	128
#define TEST_N	7
#define TEST_SEARCH	binary

#define NUM_TEST_RUNS	40000000

int
main (void)
{
	static int arr [MAX_N];
	static int searches [N_SEARCHES];

	int i, n, s;

	/* init array */
	for (i = 0; i < MAX_N; ++i)
		arr [i] = i;

	/* test */
	for (n = 0; n <= MAX_N; ++n) {
		for (i = 0; i <= n; ++i) {
			assert (linear (arr, n, i) == i);
			assert (binary (arr, n, i) == i);
		}
	}

	/* init searches */
	for (i = 0; i < N_SEARCHES; ++i)
		searches [i] = random () % (TEST_N + 1);

	n = 0;
	s = 0;
	for (i = 0; i < NUM_TEST_RUNS; ++i) {
		n += TEST_SEARCH (arr, TEST_N, searches [s]);
		if (++s == N_SEARCHES)
			s = 0;
	}

	printf ("%d\n", n);

	return 0;
}
