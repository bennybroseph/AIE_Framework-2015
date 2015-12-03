#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Vector4
{
public:
	T RR;
	T GG;
	T BB;
	T AA;
	Vector4();
	Vector4(T, T ,T ,T);
	T Magnitude();
	Vector4<T> Hexadecimal(string);
	/* V4 Interpolation
	Vector4 Interpolation();*/

	//V4 Normalizer 
	Vector4<T> Normalizer()
	{
		Vector4<T> TempVariable;
		TempVariable.RR = RR / Magnitude();
		TempVariable.GG = GG / Magnitude();
		TempVariable.BB = BB / Magnitude();
		TempVariable.AA = AA / Magnitude();
		return TempVariable;
	}

};

// V4 Defualt Constructer 
template <typename T>
Vector4<T>::Vector4()
{
	RR = 0;
	GG = 0;
	BB = 0;
	AA = 0;
}

// V4 MAnual Constructer
template <typename T>
Vector4<T>::Vector4(T r, T b, T y, T a)
{
	RR = r;
	GG = b;
	BB = y;
	AA = a;
}

// V4 Magnitude 
template <typename T>
T Vector4<T>::Magnitude()
{
	T Total;
	T V4RR, V4GG,V4BB, V4AA;
	V4RR = RR * RR;
	V4GG = GG * GG;
	V4BB = BB * BB;
	V4AA = AA * AA;
	Total = V4RR + V4GG + V4BB + V4AA;
	Total = sqrt(Total);
	return Total;
}

// V4 Hexadecimal
template <typename T>
Vector4<T> Vector4<T>::Hexadecimal(string UserInput)
{
	Vector4<T> TempVariable;
	if (UserInput[0] == '#')
	{
		int TempArray[6];
		Vector4<T> TempVariable;
		for (int i = 1; i <= 6; ++i)
			TempArray[i - 1] = (int(UserInput[i]));

		for (int j = 0; j < 6; ++j)
		{
			if (TempArray[j] / 10 == 4 || TempArray[j] / 10 == 5)
				TempArray[j] = TempArray[j] - 48;
			else if (TempArray[j] / 10 == 6 || TempArray[j] / 10 == 7)
				TempArray[j] = TempArray[j] - 55;
			else
				TempArray[j] = TempArray[j];
		}

		TempVariable.RR = (TempArray[0] * 16) + TempArray[1];
		TempVariable.GG = (TempArray[2] * 16) + TempArray[3];
		TempVariable.BB = (TempArray[4] * 16) + TempArray[5];
		TempVariable.AA = 255;
		return TempVariable;
	}
	else
	{
		TempVariable.RR = 00;
		TempVariable.GG = 00;
		TempVariable.BB = 00;
		TempVariable.AA = 00;
	}
		
}

/* Not needed 
template <typename T>
Vector4<T> Vector4<T>::Interpolation()
{
	Vector4<T> TempVariable;
	TempVariable.RR = RR + .5 * (RR - GG);
	TempVariable.RR = GG + .5 * (GG - BB);
	TempVariable.RR = BB + .5 * (BB - AA);
	TempVariable.RR = AA + .5 * (AA - RR);
	return TempVariable;
	}*/


#endif
