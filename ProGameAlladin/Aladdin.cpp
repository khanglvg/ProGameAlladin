#include "Aladdin.h"

US_NS_JK

Aladdin::Aladdin()
{
}

Aladdin::~Aladdin()
{
}

void Aladdin::init()
{
	_textureAla.setName("Aladdin.jpg");
	_textureAla.setSrcFile("aladdin.jpg");
	Graphics::getInstance()->loadTexture(_textureAla);
}

void Aladdin::release()
{
}

void Aladdin::update()
{
}

void Aladdin::render()
{
	Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.5, 0.5), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,200,200));
}
