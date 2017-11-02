#ifndef __NODE_H__ 
#define __NODE_H__

#include "Matrix.h"
#include "Vec2.h"

NS_JK_BEGIN
class Node
{
public:
	Node();
	Node(const Vec2& origin, const Vec2& position, const float& rotation, const Vec2& scale);
	~Node();

#pragma region GET-SET
	Vec2 getPosition() const;
	void setPosition(const Vec2& position);

	float getRotation() const;
	void setRotation(const float& rotation);

	Vec2 getScale() const;
	void setScale(const Vec2& scale);

	Vec2 getOrigin() const;
	void setOrigin(const Vec2& origin);
#pragma endregion

	Matrix GetTransformMatrix();
	

private:

	Vec2 _origin;


	Vec2 _position;


	float _rotation;


	Vec2 _scale;
	
	
};

NS_JK_END
#endif // __NODE_H__