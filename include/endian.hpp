#ifndef __ENDIAN_HPP__
#define __ENDIAN_HPP__

#include "IEAtom.h"

enum {BIGENDIAN,LITTLEENDIAN};



union U32F32
{
	U32 m_asU32;
	F32 m_asF32;
};

union F64AU32
{
	F64 m_asF64;
	U32 m_asAU32[2];
};
union F80AU16
{
	F80 m_asF80;
	U16 m_asAU16[5];
};


inline U16 swapU16(U16 value)
{
	return ((value & 0x00FF) << 8)
		|  ((value & 0xFF00) >> 8);
}

inline U32 swapU32(U32 value)
{
	return  ((value & 0x000000FF) << 24)
		|	((value & 0x0000FF00) << 8)
		|	((value & 0x00FF0000) >> 8)
		|	((value & 0xFF000000) >> 24);
}

inline F32 swapF32(F32 value)
{
	U32F32 u;
	u.m_asF32 = value;

	// endian-swap as integer
	u.m_asU32 = swapU32(u.m_asU32);
	return u.m_asF32;
}
inline F64 swapF64(F64 value)
{
	F64AU32 u;
	u.m_asF64 = value;
	U32 TMP;
	u.m_asAU32[0] = swapU32(u.m_asAU32[0]);
	u.m_asAU32[1] = swapU32(u.m_asAU32[1]);
	TMP = u.m_asAU32[1];

	u.m_asAU32[1] = u.m_asAU32[0];
	u.m_asAU32[0] = TMP;
	
	return u.m_asF64;
}

inline F80 swapF80(F80 value)
{
	U16 m[5];
	F80AU16 u;
	u.m_asF80 = value;

	
	m[0]=u.m_asAU16[4];
	m[1]=u.m_asAU16[3];
	m[2]=u.m_asAU16[2];
	m[3]=u.m_asAU16[1];
	m[4]=u.m_asAU16[0];

	m[0] = swapU16(m[0]);
	m[1] = swapU16(m[1]);
	m[2] = swapU16(m[2]);
	m[3] = swapU16(m[3]);
	m[4] = swapU16(m[4]);

	u.m_asAU16[0] = m[0];
	u.m_asAU16[1] = m[1];
	u.m_asAU16[2] = m[2];
	u.m_asAU16[3] = m[3];
	u.m_asAU16[4] = m[4];
	return u.m_asF80;

}
#endif // __ENDIAN_HPP__