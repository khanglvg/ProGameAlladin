#ifndef __ALADDIN_H__

#define __ALADDIN_H_

#include "Framework/Node.h"
#include "Framework/Texture.h"
#include "Framework/Graphics.h"
#include "Framework/Input.h"
#include "pugixml/pugiconfig.hpp"
#include "pugixml/pugixml.hpp"

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
	int i = 0;
	int delta = 0;
	Texture _textureAla;

	enum {NONE, JUMP, FALL};
	int jump = NONE;
	float _maxJump = SCREEN_HEIGHT - 120;
	float _startPositon = SCREEN_HEIGHT - 50;
	string State = "idle";
	
};

NS_JK_END

#endif __ALADDIN_H__

