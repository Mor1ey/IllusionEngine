#ifndef __LINE_H__
#define __LINE_H__

#include <IEMath\vector\vector.h>

template<typename TReal> class Line2D
{
public:
	//ctor
	Line2D()
	{
		u = u.normalize();
		P=u;
		t=0;
		calc();
	}
	Line2D(Vector2D<TReal> &vpos,Vector2D<TReal>& vdir,TReal len)
	{
		u =vdir.normalize();
		P=vpos;
		t=len;
		calc();
	}
	Line2D(Vector2D<TReal> &vpos1,Vector2D<TReal>& vpos2)
	{
		Vector2D<TReal> tmp = (vpos1 + vpos2);
		
		t = tmp.len();
		u =tmp.normalize();
		P = vpos1;
		calc();
		
	}

	// sets
	VOID SetDir(Vector2D<TReal> vdir)
	{
		v=vdir.normalize();
		calc();
	}
	VOID SetLen(TReal len)
	{
		t= len;
		calc();
	}
	VOID SetPos(Vector2D<TReal> vPos)
	{
		P=vPos;
		calc();
	}
	VOID calc(VOID)
	{
		
		Pt = P + (t*u);
	}

	  /// Logs
  friend std::ostream& operator<< (std::ostream& o, const Line2D<TReal>& v)
{
	o << "Line2D(P0:" << v.P << ", Pf:" << v.P2 << ", Dir: " << v.u <<",t("<< v.t <<"))";

  return o;
}

	Vector2D<TReal> P,P2;
	Vector2D<TReal> u;
	TReal t;
};

template<typename TReal> class Line3D
{
public:
	//ctor
	Line3D()
	{
		u = u.normalize();
		P=u;
		t=0;
		calc();
	}
	Line3D(Vector3D<TReal> &vpos,Vector3D<TReal>& vdir,TReal len)
	{
		u =vdir.normalize();
		P=vpos;
		t=len;
		calc();
	}
	Line3D(Vector3D<TReal> &vpos1,Vector3D<TReal>& vpos2)
	{
		Vector3D<TReal> tmp = (vpos1 + vpos2);
		
		t = tmp.len();
		u =tmp.normalize();
		P = vpos1;
		calc();
		
	}

	// sets
	VOID SetDir(Vector3D<TReal> vdir)
	{
		v=vdir.normalize();
		calc();
	}
	VOID SetLen(TReal len)
	{
		t= len;
		calc();
	}
	VOID SetPos(Vector3D<TReal> vPos)
	{
		P=vPos;
		calc();
	}
	VOID calc(VOID)
	{
		
		P2 = P + (u*t);
	}
		  /// Logs
  friend  std::ostream& operator<< (std::ostream& o, const Line3D<TReal>& v)
{
	o << "Line2D(P0:" << v.P << ", Pf:" << v.P2 << ", Dir: " << v.u <<",t("<< v.t <<"))";

  return o;
}

	Vector3D<TReal> P,P2;
	Vector3D<TReal> u;
	TReal t;
};

#endif