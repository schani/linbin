	{
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
