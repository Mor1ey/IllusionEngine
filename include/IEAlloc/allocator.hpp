/********************************************************
*														*
*	File: allocator.hpp									*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __ALLOCATOR_HPP__
#define __ALLOCATOR_HPP__
#include "utility.h"
#ifndef _INC_STDLIB
#include <cstdlib>
#endif




VOID freeAligned(PVOID p);
VOID freeUnaligned(PVOID p);
PVOID allocateAligned(U32 size_bytes,U32 alignment);
PVOID allocateUnaligned(U32 expandedSize_bytes);

class Align
{
public:
    explicit Align(I32 value) : m_value(value)
    {
    }
    I32 GetValue() const
    {
       return m_value;
    }
private:
    I32 m_value;
};

// Overridden 'normal' new/delete
void* operator new (size_t size);
void* operator new[] (size_t size);
void operator delete( void* mem );
void operator delete[]( void* mem );

// Aligned versions of new/delete
void* operator new[] (size_t size, Align alignment);
void* operator new (size_t size, Align alignment);
void operator delete (void* mem, Align alignment);
void operator delete[] (void* mem, Align alignment);

#endif