#ifndef __ALADDIN_H__

#define __ALADDIN_H_

#include "Framework/Node.h"
#include "Framework/Texture.h"
#include "Framework/Graphics.h"
#include "Framework/Input.h"
#include "pugixml/pugiconfig.hpp"
#include "pugixml/pugixml.hpp"
#include "State/StateInclude.h"

NS_JK_BEGIN

class Aladdin: public Node
{
public:
		
	Aladdin();

	~Aladdin();

	void init() override;
	void release() override;
	void update() override;
	void render() override;

	std::map<string, vector<Rect>> _animations;
	
private:

	Texture _textureAla;
	float _startPosition = SCREEN_HEIGHT - 50;

	State* _currentState = new Idle(this);
};

NS_JK_END

#endif __ALADDIN_H__

