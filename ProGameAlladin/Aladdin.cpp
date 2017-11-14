#include "Aladdin.h"
#include "Framework/Graphics.h"

JaKa::Aladdin::Aladdin()
{
}

JaKa::Aladdin::~Aladdin()
{
}

void JaKa::Aladdin::init()
{
	_textureAla.setName("Aladdin.jpg");
	_textureAla.setSrcFile("aladdin.jpg");
	Graphics::getInstance()->loadTexture(_textureAla);
}

void JaKa::Aladdin::release()
{
}

void JaKa::Aladdin::update()
{
}

void JaKa::Aladdin::render()
{
	Graphics::getInstance()->drawSprite(_textureAla, Vec2(0.5, 0.5), getTransformMatrix(), Color(255, 255, 255, 255), Rect(0,0,200,200));
}
