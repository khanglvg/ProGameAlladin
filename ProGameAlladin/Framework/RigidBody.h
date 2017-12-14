#ifndef __RIGIDBODY_H__

#define __RIGIDBODY_H__

#include "Rect.h"
#include "Size.h"

NS_JK_BEGIN

enum
{
	DYNAMIC,
	RINEMATIC,
	STATIC
};

class RigidBody
{
	friend class PhysicsManager;
private:
	std::vector<std::string> _collidingBodies;

	std::string _tag;

	// Vị trí Objects
	Vec2 _position;

	// Vận tốc Objects
	Vec2 _velocity;

	// Loại vật thể: có 3 loại:
	//		DYNAMIC:	vật thể bình thường (nhân vật, quái vật,...)
	//		KINEMATIC:	vật thể di chuyển được nhưng không va chạm được
	//		STATIC:		vật thể không di chuyển được nhưng va chạm được (mặt đất)
	int _bodyType;

	// Độ đặc của vật
	float _density;

	// Rock			Density : 0.6  Restitution : 0.1
	// Wood			Density : 0.3  Restitution : 0.2
	// Metal		Density : 1.2  Restitution : 0.05
	// BouncyBall	Density : 0.3  Restitution : 0.8
	// SuperBall	Density : 0.3  Restitution : 0.95
	// Pillow		Density : 0.1  Restitution : 0.2
	// Static		Density : 0.0  Restitution : 0.4

	// Độ đàn hồi của vật
	float _restitution;

	// Trọng lực
	float _gravityScale;

	// Lực tác dụng vào:		
	// F = a*m		(a = acceleration, m = mass) 
	// => a = F/m	(m = density*squared(shape))
	Vec2 _forces;

	// Xung lực
	float _impulse;

	// Hình dáng vật
	Vec2 _offset;
	Size _size;

	bool _isActived;

public:
	RigidBody();
	RigidBody(const Vec2& position,
		const Vec2& velocity,
		const int& bodyType,
		const float& density,
		const float& restitution,
		const float& gravityScale,
		const Vec2& forces,
		const float& impulse,
		const Vec2& offset,
		const Size& size);

	~RigidBody();


#pragma region GET-SET
	const vector<string>& getCollidingBodies() const;
	
	string getTag() const;
	void setTag(const string& tag);

	Vec2 getPosition() const;
	void setPosition(const Vec2& position);

	Vec2 getVelocity() const;
	void setVelocity(const Vec2& velocity);

	int getBodyType() const;
	void setBodyType(const int& bodyType);

	float getDensity() const;
	void setDensity(const float& density);

	float getRestitution() const;
	void setRestitution(const float& restitution);

	float getGravityScale() const;
	void setGravityScale(const float& gravityScale);

	Vec2 getForces() const;
	void setForces(const Vec2& forces);

	float getImpulse() const;
	void setImpulse(const float& impulse);

	Vec2 getOffset() const;
	void setOffset(const Vec2& offset);

	Size getSize() const;
	void setSize(const Size& size);

	bool isActived() const;
	void setActive(const bool& isActive);
#pragma endregion 


	
};

NS_JK_END

#endif __RIGIDBODY_H__
