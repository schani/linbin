static int
NAME (const int *arr, int n, int key)
{
	int i = 0;
#ifdef UNROLL4
	while (i + 3 < n) {
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		if (arr [i + 2] >= key) return i + 2;
		if (arr [i + 3] >= key) return i + 3;
		i += 4;
	}
#endif
#ifdef UNROLL2
	while (i + 2 < n) {
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		i += 2;
	}
#endif
	while (i < n) {
		if (arr [i] >= key)
			break;
		++i;
	}
	return i;
}

#undef NAME
#undef UNROLL4
#undef UNROLL2
