#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>

#ifndef NULL
#define NULL 0;
#endif

#define	abs(x)		((x) >= 0 ? x : -(x));
#define	min(x,y)	((x) < (y) ? (x) : (y));
#define	max(x,y)	((x) > (y) ? (x) : (y));

using namespace std;
namespace IEMath
{

class Point {
friend class Vector;
protected:
	int dimn;            // # coords (1, 2, or 3 max here)
	
public:
	double x, y, z;      // z=0 for 2D, y=z=0 for 1D

	//----------------------------------------------------------
	// Lots of Constructors (add more as needed)
	Point() { dimn=3; x=y=z=0; }
	// 1D Point
	Point( int a) {
		dimn=1; x=a; y=z=0;  }
	Point( double a) {
		dimn=1; x=a; y=z=0;  }
	// 2D Point
	Point( int a, int b) {
		dimn=2; x=a; y=b; z=0; }
	Point( double a, double b) {
		dimn=2; x=a; y=b; z=0; }
	// 3D Point
	Point( int a, int b, int c) {
		dimn=3; x=a; y=b; z=c;  }
	Point( double a, double b, double c) {
		dimn=3; x=a; y=b; z=c;  }
	// n-dim Point
	Point( int n, int a[]);
	Point( int n, double a[]);
	// Destructor
	~Point() {};

	//----------------------------------------------------------
	// Input/Output streams
	friend istream& operator>>( istream&, Point&);
	friend ostream& operator<<( ostream&, Point);

	//----------------------------------------------------------
	// Assignment "=": use the default to copy all members
	int dim() { return dimn; }      // get dimension
	int setdim( int);               // set new dimension

	//----------------------------------------------------------
	// Comparison (dimension must match, or not)
	int operator==( Point);
	int operator!=( Point);

	//----------------------------------------------------------
	// Point and Vector Operations (always valid) 
	Vector operator-( Point);       // Vector difference
	Point  operator+( Vector);      // +translate
	Point  operator-( Vector);      // -translate
	Point& operator+=( Vector);     // inc translate
	Point& operator-=( Vector);     // dec translate

	//----------------------------------------------------------
	// Point Scalar Operations (convenient but often illegal)
	// using any type of scalar (int, float, or double)
	//    are not valid for points in general,
	//    unless they are 'affine' as coeffs of 
	//    a sum in which all the coeffs add to 1,
	//    such as: the sum (a*P + b*Q) with (a+b == 1).
	//    The programmer must enforce this (if they want to).

	// Scalar Multiplication
	friend Point operator*( int, Point);
	friend Point operator*( double, Point);
	friend Point operator*( Point, int);
	friend Point operator*( Point, double);
	// Scalar Division
	friend Point operator/( Point, int);
	friend Point operator/( Point, double);

	//----------------------------------------------------------
	// Point Addition (also convenient but often illegal)
	//    is not valid unless part of an affine sum.
	//    The programmer must enforce this (if they want to).
	friend Point operator+( Point, Point);     // add points

	// Affine Sum
	// Returns weighted sum, even when not affine, but...
	// Tests if coeffs add to 1.  If not, sets: err = Esum.
	friend Point asum( int, int[], Point[]);
	friend Point asum( int, double[], Point[]);

	//----------------------------------------------------------
	// Point Relations
	friend double d( Point, Point);         // Distance
	friend double d2( Point, Point);        // Distance^2
	double isLeft( Point, Point);           // 2D only
	double Area( Point, Point); 		// any dim for triangle PPP

	// Collinearity Conditions (any dim n)
	bool isOnLine( Point, Point, char);  // is On line (char= flag)
	bool isOnLine( Point, Point);        // is On line (flag= all)
	bool isBefore( Point, Point);        // is On line (flag= before)
	bool isBetween( Point, Point);       // is On line (flag= between)
	bool isAfter( Point, Point);         // is On line (flag= after)
	bool isOnRay( Point, Point);         // is On line (flag= between|after)

	//----------------------------------------------------------
	// Error Handling

};

};

#endif /* __POINT_H__ */