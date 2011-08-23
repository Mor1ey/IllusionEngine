/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 *
 * Defines promotions for the vectors resulting from matrix/vector or
 * vector/matrix ops.
 *
 * @sa matvec_ops::mvmul
 */

#ifndef matvec_promotions_h
#define matvec_promotions_h

#include <et/scalar_promotions.h>
#include <vector/vector_promotions.h>

namespace IEMath {
namespace et {

/* Default mat/vec type promotion template. */
template<typename LeftT, typename RightT> struct MatVecPromote;

/** Type promotion for a matrix and a vector. */
template<
    typename E1, class AT1, typename BO, typename L,
    typename E2, class AT2>
struct MatVecPromote< IEMath::matrix<E1,AT1,BO,L>, IEMath::vector<E2,AT2> >
{
    typedef IEMath::matrix<E1,AT1,BO,L> matrix_type;
    typedef IEMath::vector<E2,AT2> vector_type;

    /* Promote the arrays: */
    typedef typename ArrayPromote<
        typename matrix_type::array_type,
        typename vector_type::array_type
    >::type promoted_array;

    /* The deduced vector result type: */
    typedef IEMath::vector<
        typename promoted_array::value_type,
        typename promoted_array::generator_type
    > type;

    /* The deduced temporary type: */
    typedef typename type::temporary_type temporary_type;
    /* Note: this is to avoid an "incomplete type" error from ICC9, which
     * can't handle e.g. <X>::<Y>::<Z> when <X> is a template type.
     */
};

/** Type promotion for a vector and a matrix. */
template<
    typename E1, class AT1,
    typename E2, class AT2, typename BO, typename L>
struct MatVecPromote< IEMath::vector<E1,AT1>, IEMath::matrix<E2,AT2,BO,L> >
{
    typedef IEMath::vector<E1,AT1> vector_type;
    typedef IEMath::matrix<E2,AT2,BO,L> matrix_type;

    /* Promote the arrays: */
    typedef typename ArrayPromote<
        typename vector_type::array_type,
        typename matrix_type::array_type
    >::type promoted_array;

    /* The deduced vector result type: */
    typedef IEMath::vector<
        typename promoted_array::value_type,
        typename promoted_array::generator_type
    > type;

    /* The deduced temporary type: */
    typedef typename type::temporary_type temporary_type;
    /* Note: this is to avoid an "incomplete type" error from ICC9, which
     * can't handle e.g. <X>::<Y>::<Z> when <X> is a template type.
     */
};

} // namespace et
} // namespace IEMath

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
