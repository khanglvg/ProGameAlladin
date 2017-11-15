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

	vector<Rect> _vectRect;
	vector<Rect> _throwAni;

private:
	int i = 0;
	int delta = 0;
	Texture _textureAla;
	string State = "idle";
	
};

NS_JK_END

#endif __ALADDIN_H__

