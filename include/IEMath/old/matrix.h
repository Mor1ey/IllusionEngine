/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 *
 *  The configurable matrix<> class.
 */

#ifndef IEMath_matrix_h
#define IEMath_matrix_h

#include <core/common.h>

namespace IEMath {

/** A configurable matrix.
 *
 * This class encapsulates the notion of a matrix.  The ArrayType template
 * argument can be used to select the type of array to be used as internal
 * storage for a 2D array of type Element.
 *
 * @internal Unlike the previous version, this uses specializations to better
 * enable varied array and matrix types. For example, with the rebind method,
 * it's difficult to support external<> matrix types that should not be
 * assigned to.
 *
 * @internal All assignments to the matrix should go through UnrollAssignment,
 * which ensures that the source expression and the destination matrix have
 * the same size.  This is particularly important for dynamically-sized
 * matrices.
 */
template<typename Element, class ArrayType,
    typename BasisOrient = CML_DEFAULT_BASIS_ORIENTATION,
    typename Layout = CML_DEFAULT_ARRAY_LAYOUT> class matrix;

} // namespace IEMath

#include <matrix/matrix_ops.h>
#include <matrix/matrix_transpose.h>
#include <matrix/matrix_rowcol.h>
#include <matrix/matrix_mul.h>
#include <matvec/matvec_mul.h>
#include <matrix/matrix_functions.h>
#include <matrix/lu.h>
#include <matrix/inverse.h>
#include <matrix/determinant.h>
#include <matrix/matrix_print.h>

#include <matrix/fixed.h>
#include <matrix/dynamic.h>
#include <matrix/external.h>

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
