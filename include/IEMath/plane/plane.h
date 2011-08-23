#ifndef __PLANE_H__
#define __PLANE_H__

#include <IEMath\vector\vector.h>

template<typename TReal> 
class Plane
{
	typedef Vector3D<TReal> Point,Vector;
	typedef Vector4D<TReal> dPlane;


	Plane(TReal d,Vector v)
	{		
		_v.x=v.x;
		_v.y=v.y;
		_v.z=v.z;
		_v.v=d;
	}
	Plane(dPlane v)
	{		
		_v.x=v.x;
		_v.y=v.y;
		_v.z=v.z;
		_v.v=v.v;
	}

	Plane(){}

	Vector& GetNormal(VOID)
	{
		Vector tmp;
		tmp.x=_v.x;
		tmp.y=_v.y;
		tmp.z=_v.z;

		return tmp.normalize();
	}
	VOID SetNormal(Vector& normal)
	{
		Vector tmp = normal.normalize();
		_v.x = tmp.x;
		_v.y=tmp.y;
		_v.z=tmp.z;

	}
	
	Point GetPoint(VOID)
	{
		return P0;
	}
	VOID SetPoint(Point &p)
	{
		P0 = p;
	}

	TReal Distance(VOID)
	{
	}

	dPlane _v;
	
};


#endif