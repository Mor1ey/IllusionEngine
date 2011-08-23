/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 *
 * Forward declarations, useful to avoid including lots of headers.
 *
 * @sa IEMath/et/array_promotions.h
 */

#ifndef core_fwd_h
#define core_fwd_h

namespace IEMath {

/* IEMath/core/fixed_1D.h */
template<typename E, int S> class fixed_1D;

/* IEMath/core/fixed_2D.h */
template<typename E, int R, int C, class L> class fixed_2D;

/* IEMath/core/dynamic_1D.h */
template<typename E, class A> class dynamic_1D;

/* IEMath/core/dynamic_2D.h */
template<typename E, class L, class A> class dynamic_2D;

/* IEMath/core/external_1D.h */
template<typename E, int S> class external_1D;

/* IEMath/core/external_2D.h */
template<typename E, int R, int C, class L> class external_2D;

/* IEMath/fixed.h */
template<int Dim1, int Dim2> struct fixed;

/* IEMath/dynamic.h */
template<class Alloc> struct dynamic;

/* IEMath/external.h */
template<int Dim1, int Dim2> struct external;

/* IEMath/vector.h */
template<typename E, class AT> class vector;

/* IEMath/matrix.h */
template<typename E, class AT, class BO, class L> class matrix;

/* IEMath/quaternion.h */
template<typename E, class AT, class OT, class CT> class quaternion;

} // namespace IEMath

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
