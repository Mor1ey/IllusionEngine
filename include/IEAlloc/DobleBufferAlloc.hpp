/********************************************************
*														*
*	File: doblebufferallocator.hpp							*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __DOBLEBUFFERALLOCATOR_HPP__
#define __DOBLEBUFFERALLOCATOR_HPP__

#include "StackAllocator.hpp"

class DoubleBufferedAllocator
{
	U32 m_curStack;
	StackAllocator m_stack[2];
public:
	DoubleBufferedAllocator()
	{}
	void swapBuffers()
	{
		m_curStack = (U32)!m_curStack;
	}

	void clearCurrentBuffer()
	{
		m_stack[m_curStack].clear();
	}

	void* alloc(U32 nBytes)
	{
		return m_stack[m_curStack].alloc(nBytes);
	}

};



#endif