#ifndef __BGLV1SCENE_H__

#define __BGLV1SCENE_H__

#include "Framework/Node.h"
#include "Framework/Texture.h"
#include "Framework/Graphics.h"

NS_JK_BEGIN

class BackgroundLv1Scene: public Node
{
public:
	BackgroundLv1Scene(const string& srcFile);

	~BackgroundLv1Scene();

	void release() override;

	void init() override;

	void render() override;

private:
	string _srcFile;
	Texture _textureBackground;
};

NS_JK_END

#endif __BGLV1SCENE_H__

