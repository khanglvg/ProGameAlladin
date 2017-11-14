#ifndef __ALADDIN_H__

#define __ALADDIN_H_

#include "Framework/Node.h"
#include "Framework/Texture.h"

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
	Texture _textureAla;
	
};

NS_JK_END

#endif __ALADDIN_H__

