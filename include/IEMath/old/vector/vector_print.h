/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 */

#ifndef vector_print_h
#define vector_print_h

#include <iostream>

namespace IEMath {

/** Output a vector to a std::ostream. */
template<typename E, class AT > inline std::ostream&
operator<<(std::ostream& os, const vector<E,AT>& v)
{
    for (size_t i = 0; i < v.size(); ++i) {
        os << " " << v[i];
    }
    return os;
}

/** Output a vector expression to a std::ostream. */
template< class XprT > inline std::ostream&
operator<<(std::ostream& os, const et::VectorXpr<XprT>& v)
{
    for (size_t i = 0; i < v.size(); ++i) {
        os << " " << v[i];
    }
    return os;
}

} // namespace IEMath

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
