#include "Rope.h"
#include "../GameObject//Aladdin.h"
US_NS_JK


Rope::Rope(const Vec2& position, const Size& size, GameObjectType tag):GameObject(position, size, GameObject::GameObjectType::NONE)
{
	_rigid->setDensity(1);
	_rigid->setTag("rope");
}

Rope::~Rope()
{
}

void Rope::release()
{
	delete this;
}

void Rope::init()
{
	/*_textureRope.setName("Rope.png");
	_textureRope.setSrcFile("Resources/Rope.png");
	Graphics::getInstance()->loadTexture(_textureRope);
*/
	_textureRigid.setName("Khang");
	_textureRigid.setSrcFile("Resources/red_rect.png");
	Graphics::getInstance()->loadTexture(_textureRigid);
}

void Rope::update()
{
	_position = _rigid->getPosition() - _rigid->getOffset();
}

void Rope::render()
{
	Graphics::getInstance()->drawSprite(_textureRigid, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255), 
		Rect(0, 0, _rigid->getSize().getWidth(), _rigid->getSize().getHeight()), 2);
}
