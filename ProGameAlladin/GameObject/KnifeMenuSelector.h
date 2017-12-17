#ifndef __KNIFEMENUSELECTOR_H__

#define __KNIFEMENUSELECTOR_H__
#include "../Framework/definitions.h"
#include "../Framework/Texture.h"
#include "../Framework/Node.h"

NS_JK_BEGIN

enum
{
	PRESS_START,
	MARKET,
	JAFAR,
	OPTIONS,
	SOUND,
	EXIT_OPTIONS,
	EXIT_CHOOSE_SCENE
};

class KnifeMenuSelector: public Node
{
public:
	KnifeMenuSelector();
	KnifeMenuSelector(const string& srcFile, const int& layer);
	~KnifeMenuSelector();

	void init() override;
	void update() override;
	void render() override;
	
#pragma region GET-SET
	string getSrcFile() const;
	void setSrcFile(const string& srcFile);
	
	int getLayer() const;
	void setLayer(const int& layer);

	int getState() const;
	void setState(const int& state);

	Vec2 getPressStartPosition() const;
	Vec2 getOptionsPosition() const;
#pragma endregion 

private:
	Texture _textureKnife;
	string _srcFile;
	int _layer;
	int _state;

	float _maxX;
	float _minX;

	Vec2 _firstPosition;
	Vec2 _secondPostion;
	Vec2 _thirdPostion;

	bool _leftToRight;
	
};

NS_JK_END

#endif //!__KNIFEMENUSELECTOR_H__