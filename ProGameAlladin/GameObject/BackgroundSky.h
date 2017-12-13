#ifndef __BACKGROUNDSKY_H__

#define __BACKGROUNDSKY_H__

#include "../Framework/Node.h"
#include "../Framework/Texture.h"
#include "../Framework/Graphics.h"

NS_JK_BEGIN

class BackgroundSky : public Node
{
public:
	BackgroundSky(const string& srcFile, const int& layer);

	~BackgroundSky();

	void update() override;

	void release() override;

	void init() override;

	void render() override;

private:
	string _srcFile;
	Texture _textureBackground;
	int _layer;
};

NS_JK_END

#endif __BACKGROUNDSKY_H__

