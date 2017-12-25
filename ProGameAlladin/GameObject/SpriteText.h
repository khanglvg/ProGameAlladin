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
	
public:
	SpriteText(const string& sourceFile, const int& eValue, const int& layer);
	~SpriteText();

	void init() override;
	void render() override;

	int getLayer() const;
	void setLayer(const int& layer);

	void setVisible(const bool& visible);
private:

	map<string, vector<Rect>> _animations;
	int _value;
	string _srcFile;
	int _layer;

	int _alpha;
	Texture _texture;

	
};
NS_JK_END

#endif //!__SPRITETEXT_H__
