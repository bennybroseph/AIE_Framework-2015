#ifndef _VECTOR2_H
#define _VECTOR2_H_

#include <iostream>

template<typename T>
class Vector2
{
public:


	T XX;
	T YY;
	Vector2();
	Vector2(T, T);
	T Magnitude();
	Vector2<T> Radions();
	Vector2<T> Degrees();
	// V2 Addition 
	Vector2<T> operator+(Vector2<T> &UserInput)
	{
		Vector2<T> TempVariable;
		TempVariable.XX = XX + UserInput.XX;
		TempVariable.YY = YY + UserInput.YY;
		return TempVariable;
	}
	// V2 Subtraction 
	Vector2<T> operator-(Vector2<T> &UserInput)
	{
		Vector2<T> TempVariable;
		TempVariable.XX = XX - UserInput.XX;
		TempVariable.YY = YY - UserInput.YY;
		return TempVariable;
	}

		// V2 Dot Product 
	T operator&(Vector2<T> &UserInput)
	{
		T total = 0;
		total += XX * UserInput.XX;
		total += YY * UserInput.YY;
		return total;
	}
	// V2 Cross Product 
	Vector2<T> operator^(Vector2<T> &UserInput)
	{
		Vector2<T> TempVariable;
		TempVariable.XX = YY*UserInput.XX - XX*UserInput.YY;
		TempVariable.YY = XX*UserInput.YY - YY*UserInput.XX;
		return TempVariable;
	}
	// V2 Interpolation 
	Vector2<T> operator%(Vector2<T> &UserInput)
	{
		Vector2<T> TempVariable;
		TempVariable.XX = XX + .5 * (UserInput.XX - XX);
		TempVariable.YY = YY + .5 * (UserInput.YY - YY);
		return TempVariable;
	}

	// V2 Normalizer
	Vector2<T> Vector2<T>::Normalizer()
	{
		Vector2<T> TempVariable;
		TempVariable.XX = XX / Magnitude();
		TempVariable.YY = YY / Magnitude();
		return TempVariable;
	}



};
// V2 Defualt Constructer
template <typename T>
Vector2<T>::Vector2()
{

	XX = 0;
	YY = 0;

}

// V2 Manual Constructer
template <typename T>
Vector2<T>::Vector2(T x, T y)
{

	XX = x;
	YY = y;

}

// V2 Magnitude 
template<typename T>
T Vector2<T>::Magnitude()
{
	T Total;
	T V2XX, V2YY;
	V2XX = XX * XX;
	V2YY = YY * YY;
	Total = V2XX + V2YY;
	Total = sqrt(Total);

	return Total;
}

// Converting for Raidions to Degrees
template <typename T>
Vector2<T> Vector2<T>::Radions() 
{
	Vector2<T> TempVariable;
	TempVariable.XX = 3.14 / 180 * XX;
	TempVariable.YY = 3.14 / 180 * YY;
	return TempVariable;

}

// Converting from Degress to Radions
template <typename T>
Vector2<T> Vector2<T>::Degrees() {
	Vector2<T> TempVariable;
	TempVariable.XX = 180 / 3.14 * XX;
	TempVariable.YY = 180 / 3.14 * YY;
	return TempVariable;
}

#endif 
