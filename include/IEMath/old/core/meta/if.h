/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 */

#ifndef meta_if_h
#define meta_if_h

#include <core/meta/common.h>

namespace IEMath {

/** Select argument type based upon truth value. */
template<bool yn, typename TrueT, typename FalseT> struct select_if;

/** Result is TrueT if true. */
template<typename TrueT, typename FalseT>
struct select_if<true,TrueT,FalseT> {
    typedef TrueT result;
    enum { is_true = true };
};

/** Result is FalseT if false. */
template<typename TrueT, typename FalseT>
struct select_if<false,TrueT,FalseT> {
    typedef FalseT result;
    enum { is_true = false };
};

} // namespace IEMath

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
