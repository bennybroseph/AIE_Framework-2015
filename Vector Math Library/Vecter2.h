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

	T Magnitude();

	Vector2<T> Vector2<T>::Normalizer()
	{
		Vector2<T> Derp;
		Derp.num1 = num1 / Magnitude();
		Derp.num2 = num2 / Magnitude();
		return Derp;
	}
	/*T Normalizer();*/
	
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

//template <typename T>
//Vector2<T> Vector2<T>::Normalizer()
//{
//	Vector2<T> Derp;
//	Derp.num1 = num1 /  Magnitude();
//	Derp.num2 = num2 /  Magnitude();
//	return Derp;
//}


#endif // !_Vector2#_H_

