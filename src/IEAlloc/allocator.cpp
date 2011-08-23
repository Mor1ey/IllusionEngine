#include "allocator.hpp"



PVOID allocateUnaligned(U32 expandedSize_bytes)
{
	return (PVOID) malloc(expandedSize_bytes);
}

PVOID allocateAligned(U32 size_bytes,U32 alignment)
{
	

	// Determine total amount of memory to allocate
	U32 expandedSize_bytes =  size_bytes + alignment;

	// Allocate an unaligned block & convert address to a U32
	U32 rawAddress = (U32) allocateUnaligned(expandedSize_bytes);

	// calculate the adjustment by masking off the lower bits of the addres, to determine how "misaligned" it is
	U32 mask = (alignment - 1);
	U32 misalignment =  (rawAddress & mask);
	U32 adjustment =  alignment - misalignment;

	// calculate the adjusted address, and return as a pointer

	U32 alignedAddress =  rawAddress + adjustment;

	// Store the adjustment in the four bytes immediately
	// preceding the asjusted address that we're
	// returning

	U32* pAdjustment = (U32*)(alignedAddress - 4);
	*pAdjustment = adjustment;
	
	return (PVOID) alignedAddress;
}

VOID freeUnaligned(PVOID p)
{
	free((void*) p);
}

VOID freeAligned(PVOID p)
{
	U32 alignedAddress =(U32) p;
	U8* pAdjustment = (U8*)(alignedAddress -4);
	U32 adjustment = (U32)*pAdjustment;

	U32 rawAddress = alignedAddress - adjustment;
	freeUnaligned((PVOID)rawAddress);
}



// Overridden 'normal' new/delete
void* operator new (size_t size)
{
	return allocateUnaligned(size);
}
void* operator new[] (size_t size)
{
	return allocateUnaligned(size);
}

void operator delete( void* mem )
{
	freeUnaligned(mem);
}
void operator delete[]( void* mem )
{
	freeUnaligned(mem);
}

// Aligned versions of new/delete
void* operator new[] (size_t size, Align alignment)
{
	return allocateAligned(size,alignment.GetValue());
}
void* operator new (size_t size, Align alignment)
{
	return allocateAligned(size,alignment.GetValue());
}

void operator delete (void* mem, Align alignment)
{
	freeAligned(mem);
}
void operator delete[] (void* mem, Align alignment)
{
	freeAligned(mem);
}
