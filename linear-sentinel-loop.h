	for (;;) {
#ifdef UNROLL2
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		i += 2;
#endif
#ifdef UNROLL4
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		if (arr [i + 2] >= key) return i + 2;
		if (arr [i + 3] >= key) return i + 3;
		i += 4;
#endif
#ifdef UNROLL8
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		if (arr [i + 2] >= key) return i + 2;
		if (arr [i + 3] >= key) return i + 3;
		if (arr [i + 4] >= key) return i + 4;
		if (arr [i + 5] >= key) return i + 5;
		if (arr [i + 6] >= key) return i + 6;
		if (arr [i + 7] >= key) return i + 7;
		i += 8;
#endif
#ifdef UNROLL16
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		if (arr [i + 2] >= key) return i + 2;
		if (arr [i + 3] >= key) return i + 3;
		if (arr [i + 4] >= key) return i + 4;
		if (arr [i + 5] >= key) return i + 5;
		if (arr [i + 6] >= key) return i + 6;
		if (arr [i + 7] >= key) return i + 7;
		if (arr [i + 8] >= key) return i + 8;
		if (arr [i + 9] >= key) return i + 9;
		if (arr [i + 10] >= key) return i + 10;
		if (arr [i + 11] >= key) return i + 11;
		if (arr [i + 12] >= key) return i + 12;
		if (arr [i + 13] >= key) return i + 13;
		if (arr [i + 14] >= key) return i + 14;
		if (arr [i + 15] >= key) return i + 15;
		i += 16;
#endif
#ifdef UNROLL32
		if (arr [i + 0] >= key) return i + 0;
		if (arr [i + 1] >= key) return i + 1;
		if (arr [i + 2] >= key) return i + 2;
		if (arr [i + 3] >= key) return i + 3;
		if (arr [i + 4] >= key) return i + 4;
		if (arr [i + 5] >= key) return i + 5;
		if (arr [i + 6] >= key) return i + 6;
		if (arr [i + 7] >= key) return i + 7;
		if (arr [i + 8] >= key) return i + 8;
		if (arr [i + 9] >= key) return i + 9;
		if (arr [i + 10] >= key) return i + 10;
		if (arr [i + 11] >= key) return i + 11;
		if (arr [i + 12] >= key) return i + 12;
		if (arr [i + 13] >= key) return i + 13;
		if (arr [i + 14] >= key) return i + 14;
		if (arr [i + 15] >= key) return i + 15;
		if (arr [i + 16] >= key) return i + 16;
		if (arr [i + 17] >= key) return i + 17;
		if (arr [i + 18] >= key) return i + 18;
		if (arr [i + 19] >= key) return i + 19;
		if (arr [i + 20] >= key) return i + 20;
		if (arr [i + 21] >= key) return i + 21;
		if (arr [i + 22] >= key) return i + 22;
		if (arr [i + 23] >= key) return i + 23;
		if (arr [i + 24] >= key) return i + 24;
		if (arr [i + 25] >= key) return i + 25;
		if (arr [i + 26] >= key) return i + 26;
		if (arr [i + 27] >= key) return i + 27;
		if (arr [i + 28] >= key) return i + 28;
		if (arr [i + 29] >= key) return i + 29;
		if (arr [i + 30] >= key) return i + 30;
		if (arr [i + 31] >= key) return i + 31;
		i += 32;
#endif
		if (arr [i] >= key)
			break;
		++i;
	}

#undef UNROLL2
#undef UNROLL4
#undef UNROLL8
#undef UNROLL16
#undef UNROLL32
