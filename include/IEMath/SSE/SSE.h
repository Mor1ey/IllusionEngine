#ifndef __SIMD_SSE_H__
#define __SIMD_SSE_H__
#define _ASSEMBLY_

#ifdef _ASSEMBLY_
#include <IEMath\SSE\i386\i386.h>
#else
#include <IEMath\SSE\generic\generic.h>
#endif

__m128 load(float *v)
{
	return _mm_load_ps(v);
}

void restore(float* f,__m128 v)
{
	_mm_store_ps(f,v);
}

typedef	__m128 F128;
__m128 mulVecMatrix(__m128 &v,__m128 &r0,__m128 &r1,__m128 &r2,__m128 &r3)
{

	F128 result;
	
	result = (_mm_replicate_x_ps(v) * r0);
	result = ((_mm_replicate_x_ps(v) * r1) + result);
	result = ((_mm_replicate_x_ps(v) * r2) + result);
	result = ((_mm_replicate_x_ps(v) * r3) + result);
	return result;
}
#endif