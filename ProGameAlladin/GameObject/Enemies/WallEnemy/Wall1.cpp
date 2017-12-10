#include "Wall1.h"
#include "../../Framework/Graphics.h"
#include "../../Framework/GameManager.h"
#include "../../Framework/PhysicsManager.h"

US_NS_JK

Wall1::Wall1()
{
	//_startPosition = Vec2(this->getPosition().getX(), this->getPosition().getY());
	float size_x = 30;
	float size_y = 470;
	Vec2 wallPosition = Vec2(1480, 200);
	_rigidWall = new RigidBody(wallPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(size_x/2, -size_y/2), Size(size_x, size_y));
	//setPosition(_rigid->getPosition() - _rigid->getOffset());
	setPosition(_startPosition);
	setScale(Vec2(1, 1));

}

Wall1::Wall1(GameObject * player):Enemy(player)
{

//	_startPosition = Vec2(this->getPosition().getX(),this->getPosition().getY());
//	//_rigid = new RigidBody(_startPosition, Vec2(0, 0), STATIC, 1, 0, 0, Vec2(0.0f, 0.0f), 0, Vec2(-10, 0), Size(50, 100));
//	//setPosition(_rigid->getPosition() - _rigid->getOffset());
//	setPosition(_startPosition);
//	setScale(Vec2(-1, 1));
//
//#pragma region READ - XML
//	pugi::xml_document doc;
//	const auto result = doc.load_file("Resources/Enemies/Enemies.xml");
//
//	if (result)
//	{
//		for (auto animation : doc.child("Animations").children())
//		{
//			const pugi::char_t* name = animation.attribute("name").value();
//			vector<Rect> rects;
//
//			for (auto rect : animation.children())
//			{
//				rects.push_back(Rect(rect.attribute("x").as_float(),
//					rect.attribute("y").as_float(),
//					rect.attribute("w").as_float(),
//					rect.attribute("h").as_float()));
//			}
//			_animations.emplace(name, rects);
//		}
//	}
//	_currentState = new ThinEnemyIdleState(this);
}

Wall1::~Wall1()
{
}

void Wall1::init()
{
	_textureWallRigid.setName("Wall1.jpg");
	_textureWallRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureWallRigid);
}

void Wall1::release()
{
	delete this;
}

void Wall1::update()
{
	_position = _rigidWall->getPosition() - _rigidWall->getOffset();

}

void Wall1::render()
{
	Graphics::getInstance()->drawSprite(_textureWallRigid, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), 
		Rect(0,0, _rigidWall->getSize().getWidth(), _rigidWall->getSize().getHeight()), 1);

}

Rect Wall1::getRect()
{
	auto width = _animations[_actionName][_animationIndex].getWidth();
	auto height = _animations[_actionName][_animationIndex].getHeight();

	Rect rect;
	rect.setX(this->getPosition().getX() - width*this->getOrigin().getX());
	rect.setY(this->getPosition().getY() - height*this->getOrigin().getY());
	rect.setWidth(this->getWidth());
	rect.setHeight(this->getHeight());
	return rect;
}
