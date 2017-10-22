#ifndef __MATRIX_H__

#define __MATRIX_H__
#include "../DirectX/Include/D3DX10core.h"
#include "definitions.h"

NS_JK_BEGIN

class Matrix
{
public:
	Matrix();
	~Matrix();

#pragma region GET-SET
	float get11() const;
	void set11(const float x);

	float get12() const;
	void set12(const float x);

	float get13() const;
	void set13(const float x);

	float get14() const;
	void set14(const float x);

	//-------------------------

	float get21() const;
	void set21(const float x);

	float get22() const;
	void set22(const float x);

	float get23() const;
	void set23(const float x);

	float get24() const;
	void set24(const float x);

//------------------------------	

	float get31() const;
	void set31(const float x);

	float get32() const;
	void set32(const float x);

	float get33() const;
	void set33(const float x);

	float get34() const;
	void set34(const float x);

//-----------------------------

	float get41() const;
	void set41(const float x);

	float get42() const;
	void set42(const float x);

	float get43() const;
	void set43(const float x);

	float get44() const;
	void set44(const float x);
#pragma endregion 

	void operator += (const Matrix &pM);
	void operator -= (const Matrix &pM);
	void operator *= (const float v);
	void operator /= (const float v);


	Matrix operator - () const;
	Matrix operator + (const Matrix &pM) const;
	Matrix operator - (const Matrix  &pM) const;
	Matrix operator * (const float v) const;
	Matrix operator / (const float v) const;


	Matrix matrixRotationX(const float angle);
	Matrix matrixRotationY(const float angle);
	static Matrix matrixRotationZ(const float angle);



private:
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;
};
NS_JK_END

#endif // !__MATRIX_H__
