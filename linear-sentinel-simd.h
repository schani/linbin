typedef int v4si __attribute__ ((vector_size (16)));
typedef unsigned char v16qi __attribute__ ((vector_size (16)));

static int
linear_sentinel_sse2 (const int *arr, int n, int key)
{
	v4si *in_data = (v4si*)arr;
	int i = 0;
	int res;
	v4si key4 = { key, key, key, key };

	for (;;) {
		v4si tmp = __builtin_ia32_pcmpgtd128 (key4, in_data [i]);
		res = __builtin_ia32_pmovmskb128 ((v16qi)tmp);
		if (res != 0xffff)
			break;
		++i;
	}

	return i * 4 + __builtin_ctz (~res) / 4;
}
