#include "Vec2.h"

US_NS_JK


Vec2::Vec2(): x(0.0f), y(0.0f)
{
}

Vec2::Vec2(const float xx,const float yy): x(xx), y(yy)
{
}


 Vec2::Vec2(const Vec2& p1, const Vec2& p2)
{
	set(p1, p2);
}

 Vec2::Vec2(const Vec2& copy)
{
	set(copy);
}

 Vec2::~Vec2()
{
}

float Vec2::getX() const
{
	return x;
}

void Vec2::setX(const float& x)
{
	this->x = x;
}

float Vec2::getY() const
{
	return y;
}

void Vec2::setY(const float& y)
{
	this->y = y;
}

bool Vec2::isZero() const
{
	return x == 0.0f && y == 0.0f;
}

bool Vec2::isOne() const
{
	return x == 1.0f && y == 1.0f;
}

 void Vec2::add(const Vec2& v)
{
	x += v.x;
	y += v.y;
}

float Vec2::dot(const Vec2& v) const
{
	return (x * v.x + y * v.y);
}

float clampf(float value, float min_inclusive, float max_inclusive)
{
	if (min_inclusive > max_inclusive) {
		std::swap(min_inclusive, max_inclusive);
	}
	return value < min_inclusive ? min_inclusive : value < max_inclusive ? value : max_inclusive;
}

 float Vec2::distanceSquared(const Vec2& v) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	return (dx * dx + dy * dy);
}

 void Vec2::negate()
{
	x = -x;
	y = -y;
}

 void Vec2::scale(float scalar)
{
	x *= scalar;
	y *= scalar;
}

 void Vec2::scale(const Vec2& scale)
{
	x *= scale.x;
	y *= scale.y;
}

 void Vec2::set(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
}

 void Vec2::set(const Vec2& v)
{
	this->x = v.x;
	this->y = v.y;
}

 void Vec2::set(const Vec2& p1, const Vec2& p2)
{
	x = p2.x - p1.x;
	y = p2.y - p1.y;
}

void Vec2::setZero()
{
	x = y = 0.0f;
}

 void Vec2::subtract(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
}

 void Vec2::smooth(const Vec2& target, float elapsedTime, float responseTime)
{
	if (elapsedTime > 0)
	{
		*this += (target - *this) * (elapsedTime / (elapsedTime + responseTime));
	}
}

 Vec2 Vec2::operator+(const Vec2& v) const
{
	Vec2 result(*this);
	result.add(v);
	return result;
}

 Vec2& Vec2::operator+=(const Vec2& v)
{
	add(v);
	return *this;
}

 Vec2 Vec2::operator-(const Vec2& v) const
{
	Vec2 result(*this);
	result.subtract(v);
	return result;
}

 Vec2& Vec2::operator-=(const Vec2& v)
{
	subtract(v);
	return *this;
}

 Vec2 Vec2::operator-() const
{
	Vec2 result(*this);
	result.negate();
	return result;
}

 Vec2 Vec2::operator*(float s) const
{
	Vec2 result(*this);
	result.scale(s);
	return result;
	 /*Vec2 result;
	 result.setX((result.getX()*s));
	 result.setY((result.getY()*s));
	 return result;*/
}


Vec2& Vec2::operator*=(float s)
{
	scale(s);
	return *this;
}

 Vec2 Vec2::operator/(const float s) const
{
	return Vec2(this->x / s, this->y / s);
}

 bool Vec2::operator<(const Vec2& v) const
{
	if (x == v.x)
	{
		return y < v.y;
	}
	return x < v.x;
}

bool Vec2::operator>(const Vec2& v) const
{
	if (x == v.x)
	{
		return y > v.y;
	}
	return x > v.x;
}

 bool Vec2::operator==(const Vec2& v) const
{
	return x == v.x && y == v.y;
}

 bool Vec2::operator!=(const Vec2& v) const
{
	return x != v.x || y != v.y;
}

 Vec2 operator*(float x, const Vec2& v)
{
	Vec2 result(v);
	result.scale(x);
	return result;
}

void Vec2::setPoint(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
}

bool isOneDimensionSegmentOverlap(float A, float B, float C, float D, float *S, float * E)
{
	float ABmin = min(A, B);
	float ABmax = max(A, B);
	float CDmin = min(C, D);
	float CDmax = max(C, D);

	if (ABmax < CDmin || CDmax < ABmin)
	{
		// ABmin->ABmax->CDmin->CDmax or CDmin->CDmax->ABmin->ABmax
		return false;
	}
	else
	{
		if (ABmin >= CDmin && ABmin <= CDmax)
		{
			// CDmin->ABmin->CDmax->ABmax or CDmin->ABmin->ABmax->CDmax
			if (S != nullptr) *S = ABmin;
			if (E != nullptr) *E = CDmax < ABmax ? CDmax : ABmax;
		}
		else if (ABmax >= CDmin && ABmax <= CDmax)
		{
			// ABmin->CDmin->ABmax->CDmax
			if (S != nullptr) *S = CDmin;
			if (E != nullptr) *E = ABmax;
		}
		else
		{
			// ABmin->CDmin->CDmax->ABmax
			if (S != nullptr) *S = CDmin;
			if (E != nullptr) *E = CDmax;
		}
		return true;
	}
}

// cross product of 2 vector. A->B X C->D
float crossProduct2Vector(const Vec2& A, const Vec2& B, const Vec2& C, const Vec2& D)
{
	return (D.y - C.y) * (B.x - A.x) - (D.x - C.x) * (B.y - A.y);
}

float Vec2::angle(const Vec2& v1, const Vec2& v2)
{
	float dz = v1.x * v2.y - v1.y * v2.x;
	return atan2f(fabsf(dz) + MATH_FLOAT_SMALL, dot(v1, v2));
}


float Vec2::distance(const Vec2& v) const
{
	float dx = v.x - x;
	float dy = v.y - y;

	return std::sqrt(dx * dx + dy * dy);
}


float Vec2::length() const
{
	return std::sqrt(x * x + y * y);
}

float Vec2::dot(const Vec2& v1, const Vec2& v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

void Vec2::normalize()
{
	float n = x * x + y * y;
	// Already normalized.
	if (n == 1.0f)
		return;

	n = std::sqrt(n);
	// Too close to zero.
	if (n < MATH_TOLERANCE)
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
}

Vec2 Vec2::getNormalized() const
{
	Vec2 v(*this);
	v.normalize();
	return v;
}

void Vec2::rotate(const Vec2& point, float angle)
{
	float sinAngle = std::sin(angle);
	float cosAngle = std::cos(angle);

	if (point.isZero())
	{
		float tempX = x * cosAngle - y * sinAngle;
		y = y * cosAngle + x * sinAngle;
		x = tempX;
	}
	else
	{
		float tempX = x - point.x;
		float tempY = y - point.y;

		x = tempX * cosAngle - tempY * sinAngle + point.x;
		y = tempY * cosAngle + tempX * sinAngle + point.y;
	}
}


bool Vec2::equals(const Vec2& target) const
{
	return (std::abs(this->x - target.x) < FLT_EPSILON)
		&& (std::abs(this->y - target.y) < FLT_EPSILON);
}

bool Vec2::fuzzyEquals(const Vec2& b, float var) const
{
	if (x - var <= b.x && b.x <= x + var)
		if (y - var <= b.y && b.y <= y + var)
			return true;
	return false;
}

float Vec2::getAngle(const Vec2& other) const
{
	Vec2 a2 = getNormalized();
	Vec2 b2 = other.getNormalized();
	float angle = atan2f(a2.cross(b2), a2.dot(b2));
	if (std::abs(angle) < FLT_EPSILON) return 0.f;
	return angle;
}

Vec2 Vec2::rotateByAngle(const Vec2& pivot, float angle) const
{
	return pivot + (*this - pivot).rotate(Vec2::forAngle(angle));
}

bool Vec2::isLineIntersect(const Vec2& A, const Vec2& B,
	const Vec2& C, const Vec2& D,
	float *S, float *T)
{
	// FAIL: Line undefined
	if ((A.x == B.x && A.y == B.y) || (C.x == D.x && C.y == D.y))
	{
		return false;
	}

	const float denom = crossProduct2Vector(A, B, C, D);

	if (denom == 0)
	{
		// Lines parallel or overlap
		return false;
	}

	if (S != nullptr) *S = crossProduct2Vector(C, D, C, A) / denom;
	if (T != nullptr) *T = crossProduct2Vector(A, B, C, A) / denom;

	return true;
}

bool Vec2::isLineParallel(const Vec2& A, const Vec2& B,
	const Vec2& C, const Vec2& D)
{
	// FAIL: Line undefined
	if ((A.x == B.x && A.y == B.y) || (C.x == D.x && C.y == D.y))
	{
		return false;
	}

	if (crossProduct2Vector(A, B, C, D) == 0)
	{
		// line overlap
		if (crossProduct2Vector(C, D, C, A) == 0 || crossProduct2Vector(A, B, C, A) == 0)
		{
			return false;
		}

		return true;
	}

	return false;
}

bool Vec2::isLineOverlap(const Vec2& A, const Vec2& B,
	const Vec2& C, const Vec2& D)
{
	// FAIL: Line undefined
	if ((A.x == B.x && A.y == B.y) || (C.x == D.x && C.y == D.y))
	{
		return false;
	}

	if (crossProduct2Vector(A, B, C, D) == 0 &&
		(crossProduct2Vector(C, D, C, A) == 0 || crossProduct2Vector(A, B, C, A) == 0))
	{
		return true;
	}

	return false;
}

bool Vec2::isSegmentOverlap(const Vec2& A, const Vec2& B, const Vec2& C, const Vec2& D, Vec2* S, Vec2* E)
{

	if (isLineOverlap(A, B, C, D))
	{
		return isOneDimensionSegmentOverlap(A.x, B.x, C.x, D.x, &S->x, &E->x) &&
			isOneDimensionSegmentOverlap(A.y, B.y, C.y, D.y, &S->y, &E->y);
	}

	return false;
}

bool Vec2::isSegmentIntersect(const Vec2& A, const Vec2& B, const Vec2& C, const Vec2& D)
{
	float S, T;

	if (isLineIntersect(A, B, C, D, &S, &T) &&
		(S >= 0.0f && S <= 1.0f && T >= 0.0f && T <= 1.0f))
	{
		return true;
	}

	return false;
}

Vec2 Vec2::getIntersectPoint(const Vec2& A, const Vec2& B, const Vec2& C, const Vec2& D)
{
	float S, T;
	Vec2 a;
	if (isLineIntersect(A, B, C, D, &S, &T))
	{
		// Vec2 of intersection
		Vec2 P;
		P.x = A.x + S * (B.x - A.x);
		P.y = A.y + S * (B.y - A.y);
		return P;
	}

	return a;
	//return Vec2::ZERO;
}
