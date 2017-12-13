#ifndef __WALL_H__

#define _WALL_H__
#include "../../Framework/definitions.h"
#include "../GameObject.h"
#include "../../Framework/Texture.h"
#include "../../Framework/RigidBody.h"

NS_JK_BEGIN

class Wall: public GameObject
{

public:
	Wall();
	Wall(const float& sizeX, const float& sizeY, const Vec2& rigidPosition);
	~Wall();

	void init() override;
	void update() override;
	void render() override;
	void release() override;

	
#pragma region GET-SET
	float getSizeX() const;
	float getSizeY() const;
	Vec2 getRigidPosition() const;

	void setSizeX(const float& sizeX);
	void setSizeY(const float& sizeY);
	void setRigidPositon(const Vec2& position);
	
#pragma endregion 

	private:
	Texture _textureWallRigid;
	RigidBody *_rigidWall;
	float _size_x;
	float _size_y;
	Vec2 _rigidPosition;
	
};

NS_JK_END
#endif //!__WALL_H__
