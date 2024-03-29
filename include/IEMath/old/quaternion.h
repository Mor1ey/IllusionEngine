/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 */

#ifndef IEMath_quaternion_h
#define IEMath_quaternion_h

#include <core/common.h>

namespace IEMath {

// NOTE: 'scale' constant no longer used.

/** Helper to specify v1^v2 multiplication order. */
struct positive_cross {
    /*enum { scale = 1 };*/
};

/** Helper to specify v2^v1 multiplication order. */
struct negative_cross {
    /*enum { scale = -1 };*/
};

/** Helper to specify scalar-first quaternion ordering. */
struct scalar_first {
    enum { W, X, Y, Z };
};

/** Helper to specify vector-first quaternion ordering. */
struct vector_first {
    enum { X, Y, Z, W };
};

/** A configurable quaternion.
 *
 * This class encapsulates the notion of a quaternion.  The ArrayType
 * template argument can be used to select the type of array to be used as
 * internal storage for the quaternion's coefficients.
 *
 * @note Quaternions with two different orders cannot be used in the same
 * expression.
 */
template<typename Element, class ArrayType = fixed<>,
    class Order = scalar_first, class Cross = positive_cross> class quaternion;

} // namespace IEMath

#include <quaternion/quaternion_ops.h>
#include <quaternion/conjugate.h>
#include <quaternion/quaternion_mul.h>
#include <quaternion/quaternion_functions.h>
#include <quaternion/quaternion_comparison.h>
#include <quaternion/inverse.h>
#include <quaternion/quaternion.h>
#include <quaternion/quaternion_print.h>
#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
