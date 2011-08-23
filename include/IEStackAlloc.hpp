/********************************************************
*														*
*	File: IEStackAlloc.hpp								*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __IESTACKALLOC_HPP__
#define __IESTACKALLOC_HPP__

#include "IEStd\stack.h"

namespace IESystem
{
	class StackAllocator:public IEStd::stack<void*>
	{
	public:
		// iterator
		typedef U32 Marker;

		// constructor with total size to alloc
		StackAllocator(U32 _size)
		{
			
			
		}
		void* alloc(U32 size_bytes);

		Marker getMarker();
		void freeToMarker(Marker marker);
		void clear();
	protected:
		void
	};
};


#endif // __IESTACKALLOC_HPP__