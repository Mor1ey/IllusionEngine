/********************************************************
*														*
*	File: exception.hpp									*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <exception>

#include "utility.h"

class IEStdException:public std::exception
{
public:
	IEStdException(PCHAR error)
	{
		mErrNo=NULL;
		mErr = error;
	}
	IEStdException(U32 nerror)
	{
		mErrNo=nerror;
		loadErr();
	}

	const char* what() const
	{
		return (mErr);
	}
	 void loadErr(void){}
protected:

	U32 mErrNo;
	PCHAR mErr;
};
#endif // __EXCEPTION_HPP__