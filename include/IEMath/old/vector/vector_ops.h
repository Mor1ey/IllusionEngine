/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief Defines vector operators.
 */

#ifndef vector_ops_h
#define vector_ops_h

#include <et/scalar_ops.h>
#include <vector/vector_expr.h>
#include <vector/vecop_macros.h>

namespace IEMath {

CML_VEC_UNIOP(    operator+, et::OpPos)
CML_VECXPR_UNIOP( operator+, et::OpPos)

CML_VEC_UNIOP(    operator-, et::OpNeg)
CML_VECXPR_UNIOP( operator-, et::OpNeg)

CML_VEC_VEC_BINOP(       operator+, et::OpAdd)
CML_VECXPR_VEC_BINOP(    operator+, et::OpAdd)
CML_VEC_VECXPR_BINOP(    operator+, et::OpAdd)
CML_VECXPR_VECXPR_BINOP( operator+, et::OpAdd)

CML_VEC_VEC_BINOP(       operator-, et::OpSub)
CML_VECXPR_VEC_BINOP(    operator-, et::OpSub)
CML_VEC_VECXPR_BINOP(    operator-, et::OpSub)
CML_VECXPR_VECXPR_BINOP( operator-, et::OpSub)

CML_VEC_SCALAR_BINOP(    operator*, et::OpMul)
CML_SCALAR_VEC_BINOP(    operator*, et::OpMul)
CML_VECXPR_SCALAR_BINOP( operator*, et::OpMul)
CML_SCALAR_VECXPR_BINOP( operator*, et::OpMul)

CML_VEC_SCALAR_BINOP(    operator/, et::OpDiv)
CML_VECXPR_SCALAR_BINOP( operator/, et::OpDiv)

} // namespace IEMath

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
