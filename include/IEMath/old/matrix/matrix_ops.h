/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief Defines matrix operators.
 */
#ifndef matrix_ops_h
#define matrix_ops_h

#include <et/scalar_ops.h>
#include <matrix/matrix_expr.h>
#include <matrix/matop_macros.h>

namespace IEMath {

CML_MAT_UNIOP(    operator+, et::OpPos)
CML_MATXPR_UNIOP( operator+, et::OpPos)

CML_MAT_UNIOP(    operator-, et::OpNeg)
CML_MATXPR_UNIOP( operator-, et::OpNeg)

CML_MAT_MAT_BINOP(       operator+, et::OpAdd)
CML_MATXPR_MAT_BINOP(    operator+, et::OpAdd)
CML_MAT_MATXPR_BINOP(    operator+, et::OpAdd)
CML_MATXPR_MATXPR_BINOP( operator+, et::OpAdd)

CML_MAT_MAT_BINOP(       operator-, et::OpSub)
CML_MATXPR_MAT_BINOP(    operator-, et::OpSub)
CML_MAT_MATXPR_BINOP(    operator-, et::OpSub)
CML_MATXPR_MATXPR_BINOP( operator-, et::OpSub)

CML_MAT_SCALAR_BINOP(    operator*, et::OpMul)
CML_SCALAR_MAT_BINOP(    operator*, et::OpMul)
CML_MATXPR_SCALAR_BINOP( operator*, et::OpMul)
CML_SCALAR_MATXPR_BINOP( operator*, et::OpMul)

CML_MAT_SCALAR_BINOP(    operator/, et::OpDiv)
CML_MATXPR_SCALAR_BINOP( operator/, et::OpDiv)

} // namespace IEMath

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
