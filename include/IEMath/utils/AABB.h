#ifndef __AABB_H__
#define __AABB_H__

#include <IEMath\vector\vector.h>

template<typename TReal>
class AABB
{
public:
	typedef Vector3D<TReal> Point;

	AABB()
	{}

	AABB(Point pmin,Point pmax)
	{
		m_Pmax = pmax;
		m_Pmin = pmin;
	}

	//sets

	VOID SetPmin(Point p)
	{
		m_Pmin = p;
	}
	VOID SetPmax(Point p)
	{
		m_Pmax = p;
	}

	BOOL IsInSide(Point &p)
	{
		return ((p.x >= m_Pmin.x) && (p.x <= m_Pmax.x) &&
				(p.y >= m_Pmin.y) && (p.y <= m_Pmax.y) &&
				(p.z >= m_Pmin.z) && (p.z >= m_Pmax.z));

	}

protected:
	Point m_Pmax;
	Point m_Pmin;

};
#endif 