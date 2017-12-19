#include "Jafar.h"
#include "../../Framework/Graphics.h"
US_NS_JK

Jafar::Jafar()
{
}

Jafar::Jafar(const Vec2& position, const Size& size, const GameObjectType& tag, GameObject* player)
	:Enemy(position, size, tag, player)
{
	_attackRange = 80;
	_boundaryLeft = position.x - 90;
	_boundaryRight = position.x + 90;
	setScale(Vec2(1, 1));

#pragma region READ - XML
	pugi::xml_document doc;
	const auto result = doc.load_file("Resources/Boss/Jafar.xml");

	if (result)
	{
		for (auto animation : doc.child("Animations").children())
		{
			const pugi::char_t* name = animation.attribute("name").value();
			vector<Rect> rects;

			for (auto rect : animation.children())
			{
				rects.push_back(Rect(rect.attribute("x").as_float(),
					rect.attribute("y").as_float(),
					rect.attribute("w").as_float(),
					rect.attribute("h").as_float()));
			}
			_animations.emplace(name, rects);
		}
	}
#pragma endregion 
}
Jafar::~Jafar()
{
}

void Jafar::init()
{
	_textureJafar.setSrcFile("Resources/Boss/jafar.png");
	_textureJafar.setName("Jafar");
	Graphics::getInstance()->loadTexture(_textureJafar);
}

void Jafar::release()
{
}

void Jafar::update()
{
}

void Jafar::render()
{
	Graphics::getInstance()->drawSprite(_textureJafar, Vec2(0.5f, 1.0f), getTransformMatrix(), Color(255, 255, 255, 255),
		Rect(0, 0, 0, 0), 2);
}

Rect Jafar::getRect()
{
	return Rect(0, 0, 0, 0);
}
