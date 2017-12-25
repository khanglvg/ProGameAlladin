#ifndef __TITLEMENUSCENE_H__

#define __TITLEMENUSCENE_H__
#include "../Framework/definitions.h"
#include "../Framework/Node.h"
#include "../Framework/Texture.h"

NS_JK_BEGIN
class TitleMenuScene: public Node
{
public:
	TitleMenuScene();
	TitleMenuScene(const string& srcFile, const Rect& rect, const int& layer);
	~TitleMenuScene();

	void init() override;
	void render() override;
	void release() override;
private:
	Rect _rect;
	Texture _textureTitle;
	string _srcFile;
	int _layer;

};

NS_JK_END

#endif //!__TITLEMENUSCENE_H__
