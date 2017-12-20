#ifndef __MENUSELECTOR_H__

#define __MENUSELECTOR_H__
#include "Framework/definitions.h"
#include "Framework/Scene.h"
#include "Framework/Text.h"
#include "GameObject/KnifeMenuSelector.h"

#define JK_FONT_HEIGHT 35
#define JK_FONT_WIDTH 20

#define JK_DRAW_X_1 250
#define JK_DRAW_X_2 460

#define JK_DRAW_Y_1 240
#define JK_DRAW_Y_2 315
#define JK_DRAW_Y_3 390

NS_JK_BEGIN
class MenuSelector: public Scene
{
public:
	MenuSelector();
	~MenuSelector();

	void init() override;
	void update() override;
	void render() override;
	void release() override;

	bool getStateSound() const;

private:
	KnifeMenuSelector* _knife;

	Text* _textPressStart;
	Text* _textMarket;
	Text* _textJafar;

	Text* _textOptions;
	Text* _textSound;
	Text* _textExit;

	Text* _textStateSound;

	Text* _textRecommend1;
	Text* _textRecommend2;

	// true - Sound On
	// false - Sound Off
	bool _stateSound;
};

NS_JK_END

#endif __MENUSELECTOR_H__

