#ifndef __ALADDINANDABU_H__

#define __ALADDINANDABU_H__
#include "../Framework/definitions.h"
#include "../Framework/Node.h"
#include "../Framework/Texture.h"

NS_JK_BEGIN
class AladdinAndAbu : public Node
{
public:
	AladdinAndAbu(const string& srcTexture, const int& layer);
	~AladdinAndAbu();

	void init() override;
	void update() override;
	void render() override;
	void release() override;

	void setActionName(const string& actionName);
	string getActionName() const;

private:
	map<string, vector<Rect>> _animations;
	int _animationIndex = 0;	
	float _index = 0;
	string _actionName;

	Texture _texture;
	string _srcTexture;
	int _layer = 0;

};

NS_JK_END

#endif //!__ALADDINANDABU_H__
