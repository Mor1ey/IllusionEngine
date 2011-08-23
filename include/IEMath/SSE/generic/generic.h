#ifndef __GENERIC_H__
#define __GENERIC_H__

#include <xmmintrin.h>


#define  SHUFFLE_PARAM(x,y,z,w) ((x) | ((y << 2) | ((z) << 4) | ((w) << 6)))

#define _mm_replicate_x_ps(v) _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(0, 0, 0, 0))

#define _mm_replicate_y_ps(v)	_mm_shuffle_ps((v), (v), SHUFFLE_PARAM(1, 1, 1, 1))

#define _mm_replicate_z_ps(v)	_mm_shuffle_ps((v), (v), SHUFFLE_PARAM(2, 2, 2, 2))

#define _mm_replicate_w_ps(v)	_mm_shuffle_ps((v), (v), SHUFFLE_PARAM(3, 3, 3, 3))

#define _mm_madd_ps(a,b,c)	_mm_add_ps(_mm_mul_ps((a), (b)), (c))





__m128 operator+(__m128 a,__m128 b)
{
	return _mm_add_ps(a,b);
}
__m128 operator-(__m128 a,__m128 b)
{
	return _mm_sub_ps(a,b);
}
__m128 operator*(__m128 a,__m128 b)
{
	return _mm_mul_ps(a,b);
}
__m128 operator/(__m128 a,__m128 b)
{
	return _mm_div_ps(a,b);
}


#endif