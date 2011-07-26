// -*- C++ -*-
/* 
 * File:   DataType.hpp
 * Author: keinier
 *
 * Created on 24 de julio de 2011, 18:45
 *
 * @Description: Archivo que define un conjunto de tipos de datos basicos
 * para el manejo de datos atomicos.
 */

#ifndef DATATYPE_HPP
#define	DATATYPE_HPP

 /////////////////////// Microsoft compiler
#if defined(_MSC_VER)
// Integer types

typedef signed __int8 I8;
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

// Logical types

typedef             bool        BOOL;

// Void type

typedef             void        VOID;

// Char type

typedef             char        Char;
typedef             char*       PChar;

#endif //(_MSC_VER) // end Microsoft compiler///////////////////////

//////////////////// GNUC compiler
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


// Logical types

typedef             bool        BOOL;

// Void type

typedef             void        VOID;

// Char type

typedef             char        Char;
typedef             char*       PChar;

#endif //__GNUC__ // end GNUC compiler////////////////////



#endif	/* DATATYPE_HPP */

