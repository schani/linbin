#ifdef UNROLL8
	while (i + 7 < n) {
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		if (arr [i + 2] >= key) return i + 2;
		if (arr [i + 3] >= key) return i + 3;
		if (arr [i + 4] >= key) return i + 4;
		if (arr [i + 5] >= key) return i + 5;
		if (arr [i + 6] >= key) return i + 6;
		if (arr [i + 7] >= key) return i + 7;
		i += 8;
	}
#endif
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

#undef UNROLL8
#undef UNROLL4
#undef UNROLL2
