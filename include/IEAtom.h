/********************************************************************
*																	*
*		FILE: IEAtom.h												*
*		Autor: Keinier Caboverde R.									*
*																	*
********************************************************************/

#ifndef __IEATOM_H__
#define __IEATOM_H__


 /////////////////////// Microsoft compiler
#if defined(_MSC_VER)
// Integer types

typedef	 signed		__int8	    I8;
typedef unsigned    __int8      U8;
typedef signed      __int16     I16;
typedef unsigned    __int16     U16;
typedef signed      __int32     I32;
typedef unsigned    __int32     U32;
typedef signed      __int64     I64;
typedef unsigned    __int64     U64;


// Real types
typedef             float       F32;
typedef             double      F64;
typedef			long double		F80;

// Logical types

typedef             bool        BOOL;

// Void type

typedef             void        VOID;
typedef				void*		PVOID;

// Char type
typedef             char        CHAR;
typedef    unsigned char        UCHAR;
typedef             char*       PCHAR;
typedef				wchar_t		CHAR16;
typedef				wchar_t*	PCHAR16;



// data unit

typedef				 char		BYTE;
typedef		unsigned char		UBYTE;
typedef				char*		PBYTE;

#endif //(_MSC_VER) 

// end Microsoft compiler///////////////////////

//////////////////// GNUC compiler ////////////////////
#if defined(__GNUC__)


// Integer types

typedef signed      char        I8;
typedef unsigned    char        U8;
typedef signed      short       I6;
typedef unsigned    short       U6;
typedef signed      int         I32;
typedef unsigned    int         U32;
typedef signed      long long   I64;
typedef unsigned    long long   U64;

// Real types

typedef             float       F32;
typedef             double      F64;
typedef			long double		F80;


// Logical types

typedef             bool        BOOL;

// Void type

typedef             void        VOID;
typedef				void*		PVOID;

// Char type

typedef             char        CHAR;
typedef    unsigned char        UCHAR;
typedef             char*       PCHAR;
typedef				wchar_t		CHAR16;
typedef				wchar_t*	PCHAR16;



// data unit

typedef				 char		BYTE;
typedef		unsigned char		UBYTE;
typedef				char*		PBYTE;


#endif //__GNUC__ 
// end GNUC compiler////////////////////



#endif // __IEATOM_H__