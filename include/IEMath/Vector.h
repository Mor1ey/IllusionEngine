#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>

#ifndef NULL
#define NULL 0;
#endif

#define	abs(x)		((x) >= 0 ? x : -(x));
#define	min(x,y)	((x) < (y) ? (x) : (y));
#define	max(x,y)	((x) > (y) ? (x) : (y));

namespace IEMath
{

//==================================================================
//  Vector Class Definition
//==================================================================

class Vector : public Point {
public:
	// Constructors same as Point class
	Vector() : Point() {};
	Vector( int a) : Point(a) {};
	Vector( double a) : Point(a) {};
	Vector( int a, int b) : Point(a,b) {};
	Vector( double a, double b) : Point(a,b) {};
	Vector( int a, int b, int c) : Point(a,b,c) {};
	Vector( double a, double b, double c) : Point(a,b,c) {};
	Vector( int n, int a[]) : Point(n,a) {};
	Vector( int n, double a[]) : Point(n,a) {};
	~Vector() {};

	//----------------------------------------------------------
	// IO streams and Comparisons: inherit from Point class

	//----------------------------------------------------------
	// Vector Unary Operations
	Vector operator-();                // unary minus
	Vector operator~();                // unary 2D perp operator

	//----------------------------------------------------------
	// Scalar Multiplication
	friend Vector operator*( int, Vector);
	friend Vector operator*( double, Vector);
	friend Vector operator*( Vector, int);
	friend Vector operator*( Vector, double);
	// Scalar Division
	friend Vector operator/( Vector, int);
	friend Vector operator/( Vector, double);

	//----------------------------------------------------------
	// Vector Arithmetic Operations
	Vector operator+( Vector);        // vector add
	Vector operator-( Vector);        // vector subtract
	double operator*( Vector);        // inner dot product
	double operator|( Vector);        // 2D exterior perp product
	Vector operator^( Vector);        // 3D exterior cross product

	Vector& operator*=( double);      // vector scalar mult
	Vector& operator/=( double);      // vector scalar div
	Vector& operator+=( Vector);      // vector increment
	Vector& operator-=( Vector);      // vector decrement
	Vector& operator^=( Vector);      // 3D exterior cross product

	//----------------------------------------------------------
	// Vector Properties
	double len() {                    // vector length
		return sqrt(x*x + y*y + z*z);
	}
	double len2() {                   // vector length squared (faster)
		return (x*x + y*y + z*z);
	}

	//----------------------------------------------------------
	// Special Operations
	void normalize();                 // convert vector to unit length
	friend Vector sum( int, int[], Vector[]);     // vector sum
	friend Vector sum( int, double[], Vector[]);  // vector sum
};
};

#endif /* __VECTOR_H__ */