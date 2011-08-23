/* -*- C++ -*- ------------------------------------------------------------
 
Copyright (c) 2007 Jesse Anders and Demian Nave http://IEMathdev.net/

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see IEMath/LICENSE for details).

 *-----------------------------------------------------------------------*/
/** @file
 *  @brief Defines the linear quaternion ops.
 */

#ifndef quaternion_ops_h
#define quaternion_ops_h

#include <et/scalar_ops.h>
#include <quaternion/quaternion_expr.h>
#include <quaternion/quatop_macros.h>

namespace IEMath {

CML_QUAT_UNIOP(    operator+, et::OpPos)
CML_QUATXPR_UNIOP( operator+, et::OpPos)

CML_QUAT_UNIOP(    operator-, et::OpNeg)
CML_QUATXPR_UNIOP( operator-, et::OpNeg)

CML_QUAT_QUAT_BINOP(       operator+, et::OpAdd)
CML_QUATXPR_QUAT_BINOP(    operator+, et::OpAdd)
CML_QUAT_QUATXPR_BINOP(    operator+, et::OpAdd)
CML_QUATXPR_QUATXPR_BINOP( operator+, et::OpAdd)

CML_QUAT_QUAT_BINOP(       operator-, et::OpSub)
CML_QUATXPR_QUAT_BINOP(    operator-, et::OpSub)
CML_QUAT_QUATXPR_BINOP(    operator-, et::OpSub)
CML_QUATXPR_QUATXPR_BINOP( operator-, et::OpSub)

CML_QUAT_SCALAR_BINOP(    operator*, et::OpMul)
CML_SCALAR_QUAT_BINOP(    operator*, et::OpMul)
CML_QUATXPR_SCALAR_BINOP( operator*, et::OpMul)
CML_SCALAR_QUATXPR_BINOP( operator*, et::OpMul)

CML_QUAT_SCALAR_BINOP(    operator/, et::OpDiv)
CML_QUATXPR_SCALAR_BINOP( operator/, et::OpDiv)

} // namespace IEMath

#endif

// -------------------------------------------------------------------------
// vim:ft=cpp
