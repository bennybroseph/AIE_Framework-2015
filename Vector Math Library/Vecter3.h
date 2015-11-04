#ifndef _2DVECTER_H_
#define _2DVECTER_H_

#include <iostream>

template<typename T>
class Vecter3
{
public:
	

	T num1;
	T num2;
	T num3;
	Vecter3();
	Vecter3(T, T, T);
	Vecter3<T> operator+(Vecter3<T> &Tick)
	{
		Vecter3<T> Derp;
		Derp.num1 = num1 + Tick.num1;
		Derp.num2 = num2 + Tick.num2;
		Derp.num3 = num3 + Tick.num3;
		return Derp;
	}
	
	Vecter3<T> operator-(Vecter3<T> &Tick)
	{
		Vecter3<T> Derp;
		Derp.num1 = num1 - Tick.num1;
		Derp.num2 = num2 - Tick.num2;
		Derp.num3 = num3 - Tick.num3;
		return Derp;
	}

	T operator*(Vecter3<T> &Trick)
	{
		T total = 0;
		total += num1 * Trick.num1;
		total += num2 * Trick.num2;
		total += num3 * Trick.num3;
		return total;
	}
	Vecter3<T> operator/(Vecter3<T> &Trick)
	{
		Vecter3<T> Derp;
		Derp.num1 = num2*Trick.num3 - num3*Trick.num2;
		Derp.num2 = num3*Trick.num1 - num1*Trick.num3;
		Derp.num3 = num1*Trick.num2 - num2*Trick.num1;
		return Derp;

	}
};


template <typename T>
Vecter3<T>::Vecter3()
{

	num1 = 0;
	num2 = 0;
	num3 = 0;
}

template <typename T>
Vecter3<T>::Vecter3(T x, T y, T z)
{

	num1 = x;
	num2 = y;
	num3 = z;
}




#endif // !1

