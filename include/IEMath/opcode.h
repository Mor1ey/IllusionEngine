#ifndef __OPCODE_H__
#define __OPCODE_H__
#include "DataType.hpp"

#include <cmath>

namespace IEMath
{
	template<class T>
	class Vector
	{
	public:
		Vector()
		{
			i=j=k=0;
		}
		Vector(T x,T y,T z=0)
		{
			i=x;j=y;k=z;
		}

		Vector& operator*(Vector& a,Vector& b)
		{

		}

		/* product vector with scalar */
		Vector& operator*(Vector& a,float f)
		{
			Vector res;
			res.i=(a.i*f);
			res.j=(a.j*f);
			res.k=(a.k*f);
			return res;
		}
		Vector& operator*(Vector& a,double d)
		{
			Vector res;
			res.i=(a.i*d);
			res.j=(a.j*d);
			res.k=(a.k*d);
			return res;
		}
		Vector& operator*(Vector& a,int i)
		{
			Vector res;
			res.i=(a.i*i);
			res.j=(a.j*i);
			res.k=(a.k*i);
			return res;
		}

		/* Product dot */

		float operator*(Vector& a,Vector& b)
		{
			return (float)((a.i*b.i) + (a.j*b.j) + (a.k*b.k));
		}
		float dot(T ModA,T ModB,double angle)
		{
			return (float)((ModA*ModB)*cos(angle));
		}

		Vector& operator+(Vector& a,Vector& b)
		{
			Vector res;
			res.i=(a.i+b.i);
			res.j=(a.j+b.j);
			res.k=(a.k+b.k);
			return res;
		}

		Vector& operator-(Vector& a,Vector& b)
		{
			Vector res;
			res.i=(a.i - b.i);
			res.j=(a.j - b.j);
			res.k=(a.k - b.k);
			return res;
		}

		float Mod()
		{
			return (float)(sqrt(((i*i)+(j*j)+(k*k))));
		}

		float ModQuad()
		{
			return (float)((i*i)+(j*j)+(k*k));
		}

		Vector& Normalization()
		{
			Vector res;
			res= ((*this) * (1/Mod()));
			return res;
		}

		Vector& Project(Vector& v)
		{
			Vector res;
			res = (*this) * v.Normalization();
			return res;
		}

		T i,j,k;
	};
};
#endif /* __OPCODE_H__ */