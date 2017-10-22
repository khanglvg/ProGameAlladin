#include "Matrix.h"

US_NS_JK
Matrix::Matrix()
{								
	_11 = 1; _12 = 0; _13 = 0; _14 = 0;			//	|1	0	0	0|
	_21 = 0; _22 = 1; _23 = 0; _24 = 0;			//	|0	1	0	0|
	_31 = 0; _32 = 0; _33 = 1; _34 = 0;			//	|0	0	1	0|
	_41 = 0; _42 = 0; _43 = 0; _44 = 1;			//	|0	0	0	1|
								
}

Matrix::~Matrix()
{
}


#pragma region GET-SET
float Matrix::get11() const
{
	return _11;
}

void Matrix::set11(const float x)
{
	_11 = x;
}

float Matrix::get12() const
{
	return _12;
}

void Matrix::set12(const float x)
{
	_12 = x;
}

float Matrix::get13() const
{
	return _13;
}

void Matrix::set13(const float x)
{
	_13 = x;
}

float Matrix::get14() const
{
	return _14;
}

void Matrix::set14(const float x)
{
	_14 = x;
}

float Matrix::get21() const
{
	return _21;
}

void Matrix::set21(const float x)
{
	_21 = x;
}

float Matrix::get22() const
{
	return _22;
}

void Matrix::set22(const float x)
{
	_22 = x;
}

float Matrix::get23() const
{
	return _23;
}

void Matrix::set23(const float x)
{
	_23 = x;
}

float Matrix::get24() const
{
	return _24;
}

void Matrix::set24(const float x)
{
	_24 = x;
}

float Matrix::get31() const
{
	return _31;
}

void Matrix::set31(const float x)
{
	_31 = x;
}

float Matrix::get32() const
{
	return _32;
}

void Matrix::set32(const float x)
{
	_32 = x;
}

float Matrix::get33() const
{
	return _33;
}

void Matrix::set33(const float x)
{
	_33 = x;
}

float Matrix::get34() const
{
	return _34;
}

void Matrix::set34(const float x)
{
	_34 = x;
}

float Matrix::get41() const
{
	return _41;
}

void Matrix::set41(const float x)
{
	_41 = x;
}

float Matrix::get42() const
{
	return _42;
}

void Matrix::set42(const float x)
{
	_42 = x;
}

float Matrix::get43() const
{
	return _43;
}

void Matrix::set43(const float x)
{
	_43 = x;
}

float Matrix::get44() const
{
	return _44;
}

void Matrix::set44(const float x)
{
	_44 = x;
}
#pragma endregion


void Matrix::operator += (const Matrix &pM)
{
	_11 += pM._11;
	_12 += pM._12;
	_13 += pM._13;
	_14 += pM._14;

	_21 += pM._21;
	_22 += pM._22;
	_23 += pM._23;
	_24 += pM._24;

	_31 += pM._31;
	_32 += pM._32;
	_33 += pM._33;
	_34 += pM._34;

	_41 += pM._41;
	_42 += pM._42;
	_43 += pM._43;
	_44 += pM._44;
}

void Matrix::operator -= (const Matrix &pM)
{
	_11 -= pM._11;
	_12 -= pM._12;
	_13 -= pM._13;
	_14 -= pM._14;

	_21 -= pM._21;
	_22 -= pM._22;
	_23 -= pM._23;
	_24 -= pM._24;

	_31 -= pM._31;
	_32 -= pM._32;
	_33 -= pM._33;
	_34 -= pM._34;

	_41 -= pM._41;
	_42 -= pM._42;
	_43 -= pM._43;
	_44 -= pM._44;
}

void Matrix::operator *= (const float v)
{
	_11 *= v;
	_12 *= v;
	_13 *= v;
	_14 *= v;

	_21 *= v;
	_22 *= v;
	_23 *= v;
	_24 *= v;

	_31 *= v;
	_32 *= v;
	_33 *= v;
	_34 *= v;

	_41 *= v;
	_42 *= v;
	_43 *= v;
	_44 *= v;
}

void Matrix::operator /= (const float v)
{
	_11 /= v;
	_12 /= v;
	_13 /= v;
	_14 /= v;

	_21 /= v;
	_22 /= v;
	_23 /= v;
	_24 /= v;

	_31 /= v;
	_32 /= v;
	_33 /= v;
	_34 /= v;

	_41 /= v;
	_42 /= v;
	_43 /= v;
	_44 /= v;
}



Matrix Matrix::operator - () const
{
	Matrix pOut;

	pOut._11 = -_11;
	pOut._12 = -_12;
	pOut._13 = -_13;
	pOut._14 = -_14;

	pOut._21 = -_21;
	pOut._22 = -_22;
	pOut._23 = -_23;
	pOut._24 = -_24;

	pOut._31 = -_31;
	pOut._32 = -_32;
	pOut._33 = -_33;
	pOut._34 = -_34;

	pOut._41 = -_41;
	pOut._42 = -_42;
	pOut._43 = -_43;
	pOut._44 = -_44;

	return pOut;
}

Matrix Matrix::operator + (const Matrix &pM) const
{
	Matrix pOut;

	pOut._11 = _11 + pM._11;
	pOut._12 = _12 + pM._12;
	pOut._13 = _13 + pM._13;
	pOut._14 = _14 + pM._14;

	pOut._21 = _21 + pM._21;
	pOut._22 = _22 + pM._22;
	pOut._23 = _23 + pM._23;
	pOut._24 = _24 + pM._24;

	pOut._31 = _31 + pM._31;
	pOut._32 = _32 + pM._32;
	pOut._33 = _33 + pM._33;
	pOut._34 = _34 + pM._34;

	pOut._41 = _41 + pM._41;
	pOut._42 = _42 + pM._42;
	pOut._43 = _43 + pM._43;
	pOut._44 = _44 + pM._44;

	return pOut;
}

Matrix Matrix::operator - (const Matrix  &pM) const
{
	Matrix pOut;

	pOut._11 = _11 - pM._11;
	pOut._12 = _12 - pM._12;
	pOut._13 = _13 - pM._13;
	pOut._14 = _14 - pM._14;

	pOut._21 = _21 - pM._21;
	pOut._22 = _22 - pM._22;
	pOut._23 = _23 - pM._23;
	pOut._24 = _24 - pM._24;

	pOut._31 = _31 - pM._31;
	pOut._32 = _32 - pM._32;
	pOut._33 = _33 - pM._33;
	pOut._34 = _34 - pM._34;

	pOut._41 = _41 - pM._41;
	pOut._42 = _42 - pM._42;
	pOut._43 = _43 - pM._43;
	pOut._44 = _44 - pM._44;

	return pOut;
}

Matrix Matrix::operator * (const float v) const
{
	Matrix pOut;

	pOut._11 = _11 * v;
	pOut._12 = _12 * v;
	pOut._13 = _13 * v;
	pOut._14 = _14 * v;

	pOut._21 = _21 * v;
	pOut._22 = _22 * v;
	pOut._23 = _23 * v;
	pOut._24 = _24 * v;

	pOut._31 = _31 * v;
	pOut._32 = _32 * v;
	pOut._33 = _33 * v;
	pOut._34 = _34 * v;

	pOut._41 = _41 * v;
	pOut._42 = _42 * v;
	pOut._43 = _43 * v;
	pOut._44 = _44 * v;

	return pOut;
}

Matrix Matrix::operator / (const float v) const
{
	Matrix pOut;

	pOut._11 = _11 / v;
	pOut._12 = _12 / v;
	pOut._13 = _13 / v;
	pOut._14 = _14 / v;

	pOut._21 = _21 / v;
	pOut._22 = _22 / v;
	pOut._23 = _23 / v;
	pOut._24 = _24 / v;

	pOut._31 = _31 / v;
	pOut._32 = _32 / v;
	pOut._33 = _33 / v;
	pOut._34 = _34 / v;

	pOut._41 = _41 / v;
	pOut._42 = _42 / v;
	pOut._43 = _43 / v;
	pOut._44 = _44 / v;

	return pOut;

}


//chua set-up
Matrix Matrix::matrixRotationX(const float angle)
{
	Matrix matrix;
	auto const cosAng = cosf(angle);
	auto const sinAng = sinf(angle);


	_22 = cosAng;
	_23 = -sinAng;

	_33 = cosAng;
	_32 = sinAng;

	return matrix;
}

//chua set-up
Matrix Matrix::matrixRotationY(const float angle)
{
	Matrix matrix;
	auto const cosAng = cosf(angle);
	auto const sinAng = sinf(angle);

	_11 = cosAng;
	_13 = sinAng;

	_31 = -sinAng;
	_33 = cosAng;

	return matrix;
}

Matrix Matrix::matrixRotationZ(const float angle)
{
	Matrix matrix;
	auto const cosAng = cosf(angle);
	auto const sinAng = sinf(angle);

	matrix._11 = cosAng;
	matrix._12 = -sinAng;

	matrix._21 = sinAng;
	matrix._22 = cosAng;

	return matrix;
}
