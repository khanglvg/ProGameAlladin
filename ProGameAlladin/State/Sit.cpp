#include "Sit.h"
#include "../Aladdin.h"
#include "../Framework/Graphics.h"
#include "../Framework/Input.h"
#include "SitAndSlash.h"
#include "SitAndThrow.h"
US_NS_JK

Sit::Sit(Node* node):State(node)
{
}

Sit::~Sit()
{
}

void Sit::onEnter()
{
	const auto aladdin = static_cast<Aladdin*>(_node);

	Graphics::getInstance()->drawSprite(aladdin->getTexture(), Vec2(0.3f, 1.0f), aladdin->getTransformMatrix(), Color(255, 255, 255, 255), Rect(378, 516, 52, 34), 1);
}

void Sit::onExit()
{
}

State* Sit::checkTransition()
{
	if (!Input::getInstance()->getKey(KEY_DOWN_ARROW))
		return new Idle(_node);
	if (Input::getInstance()->getKey(KEY_S))
		return new SitAndSlash(_node);
	if (Input::getInstance()->getKey(KEY_A))
		return new SitAndThrow(_node);

	return nullptr;
}
