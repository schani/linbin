#include <emmintrin.h>

static int
linear_search_ref (const int32_t *A, int32_t key, int n)
{
    int result = -1;
    int i;

    for (i = 0; i < n; ++i)
    {
        if (A[i] >= key)
        {
            result = i;
            break;
        }
    }
    return result;
}

static int
linear_sse2_paulr (const int32_t *A, int n, int32_t key)
{
#define VEC_INT_ELEMS 4
#define BLOCK_SIZE (VEC_INT_ELEMS * 32)
    const __m128i vkey = _mm_set1_epi32(key);
    int vresult = -1;
    int result = -1;
    int i, j;

    for (i = 0; i <= n - BLOCK_SIZE; i += BLOCK_SIZE)
    {
        __m128i vmask0 = _mm_set1_epi32(-1);
        __m128i vmask1 = _mm_set1_epi32(-1);
        int mask0, mask1;

        for (j = 0; j < BLOCK_SIZE; j += VEC_INT_ELEMS * 2)
        {
            __m128i vA0 = _mm_load_si128(&A[i + j]);
            __m128i vA1 = _mm_load_si128(&A[i + j + VEC_INT_ELEMS]);
            __m128i vcmp0 = _mm_cmpgt_epi32(vkey, vA0);
            __m128i vcmp1 = _mm_cmpgt_epi32(vkey, vA1);
            vmask0 = _mm_and_si128(vmask0, vcmp0);
            vmask1 = _mm_and_si128(vmask1, vcmp1);
        }
        mask0 = _mm_movemask_epi8(vmask0);
        mask1 = _mm_movemask_epi8(vmask1);
        if ((mask0 & mask1) != 0xffff)
        {
            vresult = i;
            break;
        }
    }
    if (vresult > -1)
    {
        result = vresult + linear_search_ref(&A[vresult], key, BLOCK_SIZE);
    }
    else if (i < n)
    {
        result = i + linear_search_ref(&A[i], key, n - i);
    }
    return result;
#undef BLOCK_SIZE
#undef VEC_INT_ELEMS
}
