#ifndef _2DVECTER_H_
#define _2DVECTER_H_

#include <iostream>

template<typename T>
class Vector3 
{
public:
	

	T num1;
	T num2;
	T num3;
	Vector3 ();
	Vector3 (T, T, T);
	T Magnitude();
	// V3 Addition
	Vector3 <T> operator+(Vector3 <T> &Tick)
	{
		Vector3 <T> Derp;
		Derp.num1 = num1 + Tick.num1;
		Derp.num2 = num2 + Tick.num2;
		Derp.num3 = num3 + Tick.num3;
		return Derp;
	}
	// V3 Subtraction 
	Vector3 <T> operator-(Vector3 <T> &Tick)
	{
		Vector3 <T> Derp;
		Derp.num1 = num1 - Tick.num1;
		Derp.num2 = num2 - Tick.num2;
		Derp.num3 = num3 - Tick.num3;
		return Derp;
	}

	// V3 Dot Product 
	T operator&(Vector3 <T> &Trick)
	{
		T total = 0;
		total += num1 * Trick.num1;
		total += num2 * Trick.num2;
		total += num3 * Trick.num3;
		return total;
	}
	// V3 Cross Product 
	Vector3 <T> operator^(Vector3 <T> &Trick)
	{
		Vector3 <T> Derp;
		Derp.num1 = num2*Trick.num3 - num3*Trick.num2;
		Derp.num2 = num3*Trick.num1 - num1*Trick.num3;
		Derp.num3 = num1*Trick.num2 - num2*Trick.num1;
		return Derp;
	}
	// V3 Normalizer
	Vector3<T> Vector3<T>::Normalizer()
	{
		Vector3<T> Derp;
		Derp.num1 = num1 / Magnitude();
		Derp.num2 = num2 / Magnitude();
		Derp.num3 = num3 / Magnitude();
		return Derp;
	}
};


template <typename T>
Vector3<T>::Vector3 ()
{

	num1 = 0;
	num2 = 0;
	num3 = 0;
}

template <typename T>
Vector3<T>::Vector3 (T x, T y, T z)
{

	num1 = x;
	num2 = y;
	num3 = z;
}

template<typename T>
T Vector3<T>::Magnitude()
{
	T Total;
	num1 *= num1;
	num2 *= num2;
	num3 *= num3;
	Total = num1 + num2 + num3;
	Total /= Total;

	return Total;
}




#endif // !1

