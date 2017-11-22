#ifndef __VEC2_H__
#define __VEC2_H__

#include <algorithm>
#include <functional>
#include <cmath>
//#include "CCMathBase.h"
#include "definitions.h"


#define MATH_FLOAT_SMALL            1.0e-37f
#define MATH_TOLERANCE              2e-37f
#define MATH_PIOVER2                1.57079632679489661923f
#define MATH_EPSILON                0.000001f

NS_JK_BEGIN
class Vec2
{
public:

	float x;
	float y;

	Vec2();

	Vec2(float xx, float yy);
	Vec2(const Vec2& p1, const Vec2& p2);
	Vec2(const Vec2& copy);
	~Vec2();

	float getX() const;
	void setX(const float& x);
	float getY() const;
	void setY(const float& y);

	//Indicates whether this vector contains all zeros.
	bool isZero() const;

	//Indicates whether this vector contains all ones.
	bool isOne() const;


	//Returns the angle (in radians) between the specified vectors.
	//@return The angle between the two vectors (in radians).	
	static float angle(const Vec2& v1, const Vec2& v2);

	float clampf(float value, float min_inclusive, float max_inclusive);

	//Returns the dot product of this vector and the specified vector.
	float dot(const Vec2& v) const;

	//Returns the dot product between the specified vectors.
	static float dot(const Vec2& v1, const Vec2& v2);

	//Adds the elements of the specified vector to this one.
	void add(const Vec2& v);

	//Returns the distance between this vector and v.
	float distance(const Vec2& v) const;

	//Returns the squared distance between this vector and v.
	 float distanceSquared(const Vec2& v) const;

	//Negates this vector.
	void negate();

	//Normalizes this vector.
	void normalize();

	// Get the normalized vector.
	Vec2 getNormalized() const;

	//Computes the length of this vector.
	float length() const;

	//Scales all elements of this vector by the specified value.
	void scale(float scalar);

	// Scales each element of this vector by the matching component of scale.
	void scale(const Vec2& scale);

	// Rotates this vector by angle (specified in radians) around the given point.
	void rotate(const Vec2& point, float angle);

	// Sets the elements of this vector to the specified values.
	void set(float xx, float yy);

	// Sets the elements of this vector to those in the specified vector.
	void set(const Vec2& v);

	// Sets this vector to the directional vector between the specified points.
	void set(const Vec2& p1, const Vec2& p2);

	// Sets the elements of this vector to zero.
	void setZero();

	// Subtracts this vector and the specified vector as (this - v) and stores the result in this vector.
	void subtract(const Vec2& v);

	/**
	* Updates this vector towards the given target using a smoothing function.
	* The given response time determines the amount of smoothing (lag). A longer
	* response time yields a smoother result and more lag. To force this vector to
	* follow the target closely, provide a response time that is very small relative
	* to the given elapsed time.
	*/
	void smooth(const Vec2& target, float elapsedTime, float responseTime);

	/*  Calculates the sum of this vector with the given vector.
		Note: this does not modify this vector.  */	
	Vec2 operator+(const Vec2& v) const;

	// Adds the given vector to this vector.
	Vec2& operator+=(const Vec2& v);

	/*  Calculates the sum of this vector with the given vector.
		Note: this does not modify this vector. */
	Vec2 operator-(const Vec2& v) const;

	// Subtracts the given vector from this vector.
	Vec2& operator-=(const Vec2& v);

	//Calculates the negation of this vector.
	Vec2 operator-() const;

	// Calculates the scalar product of this vector with the given value.
	Vec2 operator*(float s) const;

	// Scales this vector by the given value.
	Vec2& operator*=(float s);

	// Returns the components of this vector divided by the given constant
	Vec2 operator/(float s) const;

	//Determines if this vector is less than the given vector.
	bool operator<(const Vec2& v) const;

	// Determines if this vector is greater than the given vector.
	bool operator>(const Vec2& v) const;

	// Determines if this vector is equal to the given vector.
	bool operator==(const Vec2& v) const;
	
	// Determines if this vector is not equal to the given vector.
	bool operator!=(const Vec2& v) const;




	void setPoint(float xx, float yy);

	bool equals(const Vec2& target) const;

	// @returns if points have fuzzy equality which means equal with some degree of variance.
	bool fuzzyEquals(const Vec2& target, float variance) const;


	// Calculates distance between point an origin
	float getLength() const {
		return sqrtf(x*x + y*y);
	}

	// Calculates the square length of a Vec2 (not calling sqrt())
	float getLengthSq() const {
		return dot(*this); //x*x + y*y;
	}

	// Calculates the square distance between two points (not calling sqrt() )
	float getDistanceSq(const Vec2& other) const {
		return (*this - other).getLengthSq();
	}

	// Calculates the distance between two points
	float getDistance(const Vec2& other) const {
		return (*this - other).getLength();
	}

	// @returns the angle in radians between this vector and the x axis
	float getAngle() const {
		return atan2f(y, x);
	}

	// @returns the angle in radians between two vector 
	float getAngle(const Vec2& other) const;

	// Calculates cross product of two points.
	float cross(const Vec2& other) const {
		return x*other.y - y*other.x;
	}

	/** Calculates perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0
	@return Vec2
	@since v2.1.4
	* @js NA
	* @lua NA
	*/
	 Vec2 getPerp() const {
		return Vec2(-y, x);
	}

	/** Calculates midpoint between two points.
	@return Vec2
	@since v3.0
	* @js NA
	* @lua NA
	*/
	 Vec2 getMidpoint(const Vec2& other) const
	{
		return Vec2((x + other.x) / 2.0f, (y + other.y) / 2.0f);
	}

	/** Clamp a point between from and to.
	@since v3.0
	* @js NA
	* @lua NA
	*/
	Vec2 getClampPoint(const Vec2& min_inclusive, const Vec2& max_inclusive) 
	{
		return Vec2(clampf(x, min_inclusive.x, max_inclusive.x), clampf(y, min_inclusive.y, max_inclusive.y));
	}

	/** Run a math operation function on each point component
	* absf, floorf, ceilf, roundf
	* any function that has the signature: float func(float);
	* For example: let's try to take the floor of x,y
	* p.compOp(floorf);
	@since v3.0
	* @js NA
	* @lua NA
	*/
	 Vec2 compOp(std::function<float(float)> function) const
	{
		return Vec2(function(x), function(y));
	}

	/** Calculates perpendicular of v, rotated 90 degrees clockwise -- cross(v, rperp(v)) <= 0
	@return Vec2
	@since v2.1.4
	* @js NA
	* @lua NA
	*/
	 Vec2 getRPerp() const {
		return Vec2(y, -x);
	}

	/** Calculates the projection of this over other.
	@return Vec2
	@since v2.1.4
	* @js NA
	* @lua NA
	*/
	 Vec2 project(const Vec2& other) const {
		return other * (dot(other) / other.dot(other));
	}

	/** Complex multiplication of two points ("rotates" two points).
	@return Vec2 vector with an angle of this.getAngle() + other.getAngle(),
	and a length of this.getLength() * other.getLength().
	@since v2.1.4
	* @js NA
	* @lua NA
	*/
	 Vec2 rotate(const Vec2& other) const {
		return Vec2(x*other.x - y*other.y, x*other.y + y*other.x);
	}

	/** Unrotates two points.
	@return Vec2 vector with an angle of this.getAngle() - other.getAngle(),
	and a length of this.getLength() * other.getLength().
	@since v2.1.4
	* @js NA
	* @lua NA
	*/
	 Vec2 unrotate(const Vec2& other) const {
		return Vec2(x*other.x + y*other.y, y*other.x - x*other.y);
	}

	/** Linear Interpolation between two points a and b
	@returns
	alpha == 0 ? a
	alpha == 1 ? b
	otherwise a value between a..b
	@since v2.1.4
	* @js NA
	* @lua NA
	*/
	 Vec2 lerp(const Vec2& other, float alpha) const {
		return *this * (1.f - alpha) + other * alpha;
	}

	/** Rotates a point counter clockwise by the angle around a pivot
	@param pivot is the pivot, naturally
	@param angle is the angle of rotation ccw in radians
	@returns the rotated point
	@since v2.1.4
	* @js NA
	* @lua NA
	*/
	Vec2 rotateByAngle(const Vec2& pivot, float angle) const;

	/**
	* @js NA
	* @lua NA
	*/
	static  Vec2 forAngle(const float a)
	{
		return Vec2(cosf(a), sinf(a));
	}

	/** A general line-line intersection test
	@param A   the startpoint for the first line L1 = (A - B)
	@param B   the endpoint for the first line L1 = (A - B)
	@param C   the startpoint for the second line L2 = (C - D)
	@param D   the endpoint for the second line L2 = (C - D)
	@param S   the range for a hitpoint in L1 (p = A + S*(B - A))
	@param T   the range for a hitpoint in L2 (p = C + T*(D - C))
	@return    whether these two lines intersects.
	Note that to truly test intersection for segments we have to make
	sure that S & T lie within [0..1] and for rays, make sure S & T > 0
	the hit point is        C + T * (D - C);
	the hit point also is   A + S * (B - A);
	@since 3.0
	* @js NA
	* @lua NA
	*/
	static bool isLineIntersect(const Vec2& A, const Vec2& B,
		const Vec2& C, const Vec2& D,
		float *S = nullptr, float *T = nullptr);

	/**
	returns true if Line A-B overlap with segment C-D
	@since v3.0
	* @js NA
	* @lua NA
	*/
	static bool isLineOverlap(const Vec2& A, const Vec2& B,
		const Vec2& C, const Vec2& D);

	/**
	returns true if Line A-B parallel with segment C-D
	@since v3.0
	* @js NA
	* @lua NA
	*/
	static bool isLineParallel(const Vec2& A, const Vec2& B,
		const Vec2& C, const Vec2& D);

	/**
	returns true if Segment A-B overlap with segment C-D
	@since v3.0
	* @js NA
	* @lua NA
	*/
	static bool isSegmentOverlap(const Vec2& A, const Vec2& B,
		const Vec2& C, const Vec2& D,
		Vec2* S = nullptr, Vec2* E = nullptr);

	/**
	returns true if Segment A-B intersects with segment C-D
	@since v3.0
	* @js NA
	* @lua NA
	*/
	static bool isSegmentIntersect(const Vec2& A, const Vec2& B, const Vec2& C, const Vec2& D);

	/**
	returns the intersection point of line A-B, C-D
	@since v3.0
	* @js NA
	* @lua NA
	*/
	static Vec2 getIntersectPoint(const Vec2& A, const Vec2& B, const Vec2& C, const Vec2& D);

	//static Vec2 ZERO;

};

/**
* Calculates the scalar product of the given vector with the given value.
*
* @param x The value to scale by.
* @param v The vector to scale.
* @return The scaled vector.
*/



NS_JK_END
#endif // __VEC2_H__