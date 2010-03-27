static int
NAME (const int *arr, int n, int key)
{
	int min = 0, max = n;
#ifdef LINEAR_FALLBACK
	while (min + LINEAR_FALLBACK < max) {
#else
	while (min < max) {
#endif
		int middle = (min + max) >> 1;
#ifdef CMOV
		asm ("cmpl %3, %2\n\tcmovg %4, %0\n\tcmovle %5, %1"
		     : "+r" (min),
		       "+r" (max)
		     : "r" (key), "g" (arr [middle]), "g" (middle + 1), "g" (middle));
#else
		if (key > arr [middle])
			min = middle + 1;
		else
			max = middle;
#endif
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
