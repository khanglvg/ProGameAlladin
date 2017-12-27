#ifndef __SPRITETEXT_H__

#define __SPRITETEXT_H__
#include "../Framework/definitions.h"
#include "../Framework/Texture.h"
#include "../Framework/Node.h"

NS_JK_BEGIN
class SpriteText: public Node
{
public:
	enum
	{
		ZERO,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
		DOT,
		OPEN_PARENTHESES,
		CLOSE_PARENTHESES
	};
	
	enum SpriteTextType
	{	
		NONE,
		ALA_LIFE,
		APPLE_UNIT,
		APPLE_TENS, 
		RUBY_UNIT,
		RUBY_TENS,
		SCORE_1,
		SCORE_2,
		SCORE_3,
		SCORE_4
	};
public:
	SpriteText(const string& sourceFile, const int& eValue, const int& layer);
	~SpriteText();

	void update() override;
	void init() override;
	void render() override;

	int getLayer() const;
	void setLayer(const int& layer);

	void setType(const SpriteTextType& type);
	void setVisible(const bool& visible);

	int getValue()const;
	void setValue(const int& value);
private:

	map<string, vector<Rect>> _animations;
	int _value;
	string _srcFile;
	int _layer;

	int _alpha;
	Texture _texture;
	int _type;
	
};
NS_JK_END

#endif //!__SPRITETEXT_H__
