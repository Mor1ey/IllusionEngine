/********************************************************
*														*
*	File: IEMemory.hpp									*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __IEMEMORY_HPP__
#define __IEMEMORY_HPP__

#ifdef _DEBUG
#include <cstdio>
#endif

#include <cstdlib>
#include "utility.h"

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
void* operator new(size_t size)
{
#ifdef _DEBUG
	printf("Allocating %i bytes\n",size);
#endif
    return malloc(size* sizeof(char));
}

void operator delete (void* mem)
{
#ifdef _DEBUG
	printf("free block of memory %x\n",mem);
#endif
    free(mem);
}

// Don’t forget the array version of new/delete
void* operator new[](size_t size)
{
#ifdef _DEBUG
	printf("Allocating %i bytes\n",size);
#endif
    return malloc(size* sizeof(char));
}

void operator delete[](void* mem)
{
#ifdef _DEBUG
	printf("free block of memory %x\n",mem);
#endif
    free(mem);
}

/*// Aligned versions of new/delete
void* operator new[] (size_t size, Align alignment)
{
	 return new (pAlignedMem) MyClass();

}
void* operator new (size_t size, Align alignment);
void operator delete (void* mem, Align alignment);
void operator delete[] (void* mem, Align alignment);
*/
#endif // __IEMEMORY_HPP__