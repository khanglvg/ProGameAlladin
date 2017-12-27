#ifndef __ALADDINHEALTH_H__

#define __ALADDINHEALTH_H__
#include "../../Framework/definitions.h"
#include "../../Framework/Node.h"
#include "../../Framework/Texture.h"

NS_JK_BEGIN

class Aladdin;

class AladdinHealth : public Node
{
public:
	AladdinHealth(Aladdin* player);
	~AladdinHealth();

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

	Aladdin* _player;

};

NS_JK_END

#endif //!__ALADDINANDABU_H__
