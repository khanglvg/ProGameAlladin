#ifndef __TITLEMENUSCENE_H__

#define __TITLEMENUSCENE_H__
#include "../Framework/definitions.h"
#include "../Framework/Node.h"
#include "../Framework/Texture.h"

NS_JK_BEGIN
class TitleMenuScene: public Node
{
public:

	enum TitleType { ALA, APPLE, RUBY };

	TitleMenuScene();
	TitleMenuScene(const string& srcFile, const Rect& rect, const int& layer);
	~TitleMenuScene();

	void init() override;
	void update() override;
	void render() override;
	void release() override;

	void setType(const TitleType& type);
	void setIcon(const bool& isIcon);

	void setVisible(const bool& visible);
private:
	Rect _rect;
	Texture _textureTitle;
	string _srcFile;
	int _layer;

	TitleType _type;

	int _alpha = 255;
	bool _isIcon = true;

};

NS_JK_END

#endif //!__TITLEMENUSCENE_H__
