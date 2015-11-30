#ifndef _VECTOR2_H
#define _Vector2_H_

#include <iostream>

template<typename T>
class Vector2
{
public:


	T num1;
	T num2;
	Vector2();
	Vector2(T, T);
	T Magnitude();
	Vector2<T> operator+(Vector2<T> &Tick)
	{
		Vector2<T> Derp;
		Derp.num1 = num1 + Tick.num1;
		Derp.num2 = num2 + Tick.num2;
		return Derp;
	}

	Vector2<T> operator-(Vector2<T> &Tick)
	{
		Vector2<T> Derp;
		Derp.num1 = num1 - Tick.num1;
		Derp.num2 = num2 - Tick.num2;
		return Derp;
	}

		// V2 Dot Product 
	T operator&(Vector2<T> &Trick)
	{
		T total = 0;
		total += num1 * Trick.num1;
		total += num2 * Trick.num2;
		return total;
	}
	// V2 Cross Product 
	Vector2<T> operator^(Vector2<T> &Trick)
	{
		Vector2<T> Derp;
		Derp.num1 = num2*Trick.num1 - num1*Trick.num2;
		Derp.num2 = num1*Trick.num2 - num2*Trick.num1;
		return Derp;
	}

	
	// V2 Normalizer
	Vector2<T> Vector2<T>::Normalizer()
	{
		Vector2<T> Derp;
		Derp.num1 = num1 / Magnitude();
		Derp.num2 = num2 / Magnitude();
		return Derp;
	}

};

template <typename T>
Vector2<T>::Vector2()
{

	num1 = 0;
	num2 = 0;

}

template <typename T>
Vector2<T>::Vector2(T x, T y)
{

	num1 = x;
	num2 = y;

}

template<typename T>
T Vector2<T>::Magnitude()
{
	T Total;
	num1 *= num1;
	num2 *= num2;
	Total = num1 + num2;
	Total /= Total;

	return Total;
}
#endif // !_Vector2#_H_

