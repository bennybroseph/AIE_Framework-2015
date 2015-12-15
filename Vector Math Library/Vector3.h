#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <iostream>

template<typename T>
class Vector3 
{
public:
	

	T XX;
	T YY;
	T ZZ;
	Vector3 ();
	Vector3 (T, T, T);
	T Magnitude();
	// V3 Addition
	Vector3 <T> operator+(Vector3 <T> &UserInput)
	{
		Vector3<T> TempVariable;
		TempVariable.XX = XX + UserInput.XX;
		TempVariable.YY = YY + UserInput.YY;
		TempVariable.ZZ = ZZ + UserInput.ZZ;
		return TempVariable;
	}
	// V3 Subtraction 
	Vector3 <T> operator-(Vector3 <T> &UserInput)
	{
		Vector3 <T> TempVariable;
		TempVariable.XX = XX - UserInput.XX;
		TempVariable.YY = YY - UserInput.YY;
		TempVariable.ZZ = ZZ - UserInput.ZZ;
		return TempVariable;
	}

	// V3 Dot Product 
	T operator&(Vector3 <T> &UserInput)
	{
		T total = 0;
		total += XX * UserInput.XX;
		total += YY * UserInput.YY;
		total += ZZ * UserInput.ZZ;
		return total;
	}
	// V3 Cross Product 
	Vector3 <T> operator^(Vector3 <T> &UserInput)
	{
		Vector3 <T> TempVariable;
		TempVariable.XX = YY*UserInput.ZZ - ZZ*UserInput.YY;
		TempVariable.YY = ZZ*UserInput.XX - XX*UserInput.ZZ;
		TempVariable.ZZ = XX*UserInput.YY - YY*UserInput.XX;
		return TempVariable;
	}

	// V3 Interpolation
	Vector3<T> operator%(Vector3<T> &UserInput)
	{
		Vector3<T> TempVariable;
		TempVariable.XX = XX + .5 * (UserInput.XX - XX);
		TempVariable.YY = YY + .5 * (UserInput.YY - YY);
		TempVariable.ZZ = ZZ + .5 * (UserInput.ZZ - ZZ);

		return TempVariable;
	}
	// V3 Normalizer
	Vector3<T> Vector3<T>::Normalizer()
	{
		Vector3<T> TempVariable;
		TempVariable.XX = XX / Magnitude();
		TempVariable.YY = YY / Magnitude();
		TempVariable.ZZ = ZZ / Magnitude();
		return TempVariable;
	}
};

// V3 Defualt Constructer
template <typename T>
Vector3<T>::Vector3 ()
{

	XX = 0;
	YY = 0;
	ZZ = 0;
}

// V3 Manual Constructer
template <typename T>
Vector3<T>::Vector3 (T x, T y, T z)
{

	XX = x;
	YY = y;
	ZZ = z;
}

// V3 MAgnitude 
template<typename T>
T Vector3<T>::Magnitude()
{
	T Total;
	T V3XX, V3YY, V3ZZ;
	V3XX = XX * XX;
	V3YY = YY * YY;
	V3ZZ = ZZ * ZZ;
	Total = V4XX + V4YY + V4ZZ;
	Total = sqrt(Total);

	return Total;
}




#endif 

