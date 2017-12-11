#include "Wall.h"
#include "../../Framework/Graphics.h"
US_NS_JK


Wall::Wall()
{
	float size_x = 30;
	float size_y = 470;
	Vec2 wallPosition = Vec2(0, 0);
	_rigidWall = new RigidBody(wallPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(size_x / 2, -size_y / 2), Size(size_x, size_y));
	setPosition(_rigidWall->getPosition() - _rigidWall->getOffset());
	setScale(Vec2(1, 1));
}

Wall::Wall(const float& sizeX, const float& sizeY, const Vec2& rigidPosition)
{
	_rigidWall = new RigidBody(rigidPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(sizeX / 2, -sizeY / 2), Size(sizeX, sizeY));
	setPosition(_rigidWall->getPosition() - _rigidWall->getOffset());
	setScale(Vec2(1, 1));
}

Wall::~Wall()
{
}

void Wall::init()
{
	_textureWallRigid.setName("Wall.png");
	_textureWallRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureWallRigid);
}

void Wall::update()
{
	_position = _rigidWall->getPosition() - _rigidWall->getOffset();
}

void Wall::render()
{
	Graphics::getInstance()->drawSprite(_textureWallRigid, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		Rect(0, 0, _rigidWall->getSize().getWidth(), _rigidWall->getSize().getHeight()), 1);
}

void Wall::release()
{
	_rigidWall = nullptr;
	delete _rigidWall;
	delete this;
}


#pragma region GET-SET
float Wall::getSizeX() const
{
	return _size_x;
}

float Wall::getSizeY() const
{
	return _size_y;
}

Vec2 Wall::getRigidPosition() const
{
	return _rigidPosition;
}

void Wall::setSizeX(const float& sizeX)
{
	_size_x = sizeX;
}

void Wall::setSizeY(const float& sizeY)
{
	_size_y = sizeY;
}

void Wall::setRigidPositon(const Vec2& position)
{
	_rigidPosition = position;
}
#pragma endregion 
