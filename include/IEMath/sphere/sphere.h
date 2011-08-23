#ifndef __SPHERE_H__
#define __SPHERE_H__

#include <IEMath\vector\vector.h>

template<typename TReal> class Sphere
{
public:
	Sphere(Vector3D<TReal> pos,TReal radi)
	{
		comp.set(pos.x,pos.y,pos.z,radi);
		r=radi
	}
	Sphere(Vector4D<TReal> q)
	{
		comp = q;
	}


	VOID SetR(TReal r)
	{
		comp.v = r;
	}
	TReal GetR(VOID)
	{
		return comp.v;
	}

	VOID SetPos(Vector3D<TReal> pos)
	{
		comp.x = pos.x;
		comp.y = pos.y;
		comp.z = pos.z;
	}
	Vector3D<TReal> GetPos(VOID)
	{
		return Vector3D(comp.x,comp.y,comp.z);
	}


	Vector4D<TReal> comp;
};
#endif