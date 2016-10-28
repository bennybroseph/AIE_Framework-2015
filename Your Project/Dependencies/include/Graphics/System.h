//////////////////////////////////////////////////////////////
// File: System.h
// Author: Ben Odom
// Brief: Holds the necessary structs for 2D graphics. Uses
//		  2D points, sizes/dimensions, velocity/angular
//		  velocity, and colors. Also hold some overloaded
//		  operators for adding points or sizes together.
//////////////////////////////////////////////////////////////

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#define PI 3.1415926535897932384626433832795 // PI in such a way that anything that includes "System.h" can use it

namespace System
{
	// Holds a quick reference to appropriate angles for d-pad based movement
	enum AngularDir
	{
		UP = 270,
		DOWN = 90,
		LEFT = 180,
		RIGHT = 0,

		UP_RIGHT = 315,
		UP_LEFT = 225,
		DOWN_RIGHT = 45,
		DOWN_LEFT = 135
	};

	// Defines a templated struct for an x and y point in 2D space as well as some overloaded operators to go along with it
	template <typename T>
	struct Point2D
	{
		T X, Y;

		// Addition of two 'Point2D's
		template <typename T, typename U>
		friend const Point2D<T> operator+(const Point2D<T>& ac_PointA, const Point2D<U>& ac_PointB);
		// Subtraction of two 'Point2D's
		template <typename T, typename U>
		friend const Point2D<T> operator-(const Point2D<T>& ac_PointA, const Point2D<U>& ac_PointB);
		// Applying a negative sign to a single Point2D; ex: "NegativeA = -PointA;"
		template <typename T>
		friend const Point2D<T> operator-(const Point2D<T>& ac_PointA);

		// Division of two 'Point2D's
		template <typename T, typename U>
		friend const Point2D<T> operator/(const Point2D<T>& ac_PointA, const Point2D<U>& ac_PointB);

		// Division of a 'Point2D' and an integer; ex: "HalfofA = PointA / 2;"
		template <typename T>
		friend const Point2D<T> operator/(const Point2D<T>& ac_PointA, const int ac_iNum);
	};

	// Defines a templated struct for dimensions/size in 2D space as well as some overloaded operators to go along with it
	template <typename T>
	struct Size2D
	{
		T W, H;

		template <typename T>
		friend const Size2D<T> operator/(const Size2D<T>& ac_SizeA, const int ac_iNum);

	};
	// Defines a templated struct for angular velocity in 2D space
	template <typename T>
	struct AngularVel
	{
		T Speed;
		T Angle;
	};
	// Defines a templated struct for color in the format rgba, which is the most useful for OpenGL
	// Accepted value range is 0 - 255
	template <typename T>
	struct Color
	{
		T Red, Green, Blue, Alpha;
	};

	// Defines what it means to add a 'Point2D' and a 'Size2D'
	template <typename T, typename U>
	const Point2D<T> operator+(const Point2D<T>& ac_PointA, const Size2D<U>& ac_SizeA);

	// Defines what it means to set a 'Point2D' equal to itself + an 'AngularVel'
	template <typename T, typename U>
	void operator+=(Point2D<T>& ac_PointA, const AngularVel<U>& ac_VelocityA);
}

namespace System
{
	template <typename T, typename U>
	const Point2D<T> operator+(const Point2D<T>& ac_PointA, const Point2D<U>& ac_PointB)
	{
		const Point2D<T> PointC = { ac_PointA.X + ac_PointB.X, ac_PointA.Y + ac_PointB.Y };

		return PointC;
	}
	template <typename T>
	const Point2D<T> operator-(const Point2D<T>& ac_PointA)
	{
		const Point2D<T> PointC = { -ac_PointA.X, -ac_PointA.Y };

		return PointC;
	}
	template <typename T, typename U>
	const Point2D<T> operator-(const Point2D<T>& ac_PointA, const Point2D<U>& ac_PointB)
	{
		return ac_PointA + (-ac_PointB);
	}
	template <typename T, typename U>
	const Point2D<T> operator/(const Point2D<T>& ac_PointA, const Point2D<U>& ac_PointB)
	{
		const Point2D<T> PointC = { ac_PointA.X / ac_PointB.X, ac_PointA.Y / ac_PointB.Y };

		return PointC;
	}
	template <typename T>
	const Point2D<T> operator/(const Point2D<T>& ac_PointA, const int ac_iNum)
	{
		const Point2D<T> PointC = { ac_PointA.X / ac_iNum, ac_PointA.Y / ac_iNum };

		return PointC;
	}

	template <typename T>
	const Size2D<T> operator/(const Size2D<T>& ac_SizeA, const int ac_iNum)
	{
		const Size2D<T> SizeC = { ac_Dimension.W / ac_iNum, ac_Dimension.H / ac_iNum };

		return SizeC;
	}

	template <typename T, typename U>
	const Point2D<T> operator+(const Point2D<T>& ac_PointA, const Size2D<U>& ac_SizeA)
	{
		const Point2D<T> PointC = { ac_PointA.X + ac_SizeA.W, ac_PointA.Y + ac_SizeA.H };

		return PointC;
	}

	template <typename T, typename U>
	void operator+=(Point2D<T>& ac_PointA, const AngularVel<U>& ac_VelocityA)
	{
		ac_PointA = {
			ac_PointA.X + ac_VelocityA.Speed * (T)cos(ac_VelocityA.Angle * (PI / 180)),
			ac_PointA.Y + ac_VelocityA.Speed * (T)sin(ac_VelocityA.Angle * (PI / 180)) };
	}
}

#endif // _SYSTEM_H_
