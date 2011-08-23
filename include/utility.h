/********************************************************
*														*
*	File: utility.h										*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __UTILITY_H__
#define __UTILITY_H__
#include "IEAtom.h"
#include <cstdio>

#define NULL 0


 /////////////////////// Microsoft compiler
#if defined(_MSC_VER)

#ifdef _WINDLL
#define ILLUSIONENGINE_API __declspec(dllexport)
#else
#define ILLUSIONENGINE_API 
#endif


#ifdef _DEBUG 


// algoritmo de control para punto de control del software

#define ASSERT (test)\
	if(!test){\
	printf("Assertion: fun[%s] file[%s] line[%i]\n",#test,__FILE__,__LINE__);\
	}

#else // Release
#define ASSERT (test) ((void) 0)
#endif

#endif //(_MSC_VER) 

// end Microsoft compiler///////////////////////

//////////////////// GNUC compiler ////////////////////
#if defined(__GNUC__)

#ifdef DEBUG 


// algoritmo de control para punto de control del software

#define ASSERT (test)\
	if(!test){\
	printf("Assertion: fun[%s] file[%s] line[%i]\n",#test,__FILE__,__LINE__);\
	}

#else // Release
#define ASSERT (test) ((void) 0)
#endif

#endif //__GNUC__ 
// end GNUC compiler////////////////////



#endif //__UTILITY_H__