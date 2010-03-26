#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static int
linear (const int *arr, int n, int key)
{
	int i = 0;
	while (i + 3 < n) {
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		if (arr [i + 2] >= key) return i + 2;
		if (arr [i + 3] >= key) return i + 3;
		i += 4;
	}
	while (i + 2 < n) {
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		i += 2;
	}
	while (i < n) {
		if (arr [i] >= key)
			break;
		++i;
	}
	return i;
}

static int
binary (const int *arr, int n, int key)
{
	int min = 0, max = n;
	while (min < max) {
		int middle = (min + max) >> 1;
		asm ("cmpl %3, %2\n\tcmovg %4, %0\n\tcmovle %5, %1"
		     : "+r" (min),
		       "+r" (max)
		     : "r" (key), "g" (arr [middle]), "g" (middle + 1), "g" (middle));
		/*
		if (key > arr [middle])
			min = middle + 1;
		else
			max = middle;
		*/
	}
	return min;
}

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
