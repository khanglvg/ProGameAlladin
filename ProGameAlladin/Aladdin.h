#ifndef __ALADDIN_H__

#define __ALADDIN_H_

#include "Framework/Node.h"
#include "Framework/Texture.h"
#include "Framework/Graphics.h"
#include "Framework/Input.h"

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

private:
	int i = 0;
	bool _isAlready = false;
	Texture _textureAla;
	vector<Rect> _vectRect;
	vector<Rect> _throwAni;
	
};

NS_JK_END

#endif __ALADDIN_H__

