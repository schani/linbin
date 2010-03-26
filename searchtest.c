#include <stdio.h>
#include <assert.h>

static int
linear (const int *arr, int n, int key)
{
	int i;
	for (i = 0; i < n; ++i)
		if (arr [i] >= key)
			break;
	return i;
}

static int
binary (const int *arr, int n, int key)
{
	int min = 0, max = n;
	while (min < max) {
		int middle = (min + max) >> 1;
		if (key > arr [middle])
			min = middle + 1;
		else
			max = middle;
	}
	return min;
}

#define MAX_N	128

int
main (void)
{
	static int arr [MAX_N];

	int i, n;

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

	return 0;
}
