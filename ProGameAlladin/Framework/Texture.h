#ifndef __TEXTURE_H__

#define __TEXTURE_H__ 

#include "definitions.h"
#include "..\DirectX\Include\d3d9.h"

NS_JK_BEGIN
class Texture
{
public:
	Texture();
	~Texture();
	LPDIRECT3DTEXTURE9 getTexture() const;
	void setTexture(const LPDIRECT3DTEXTURE9& texture);
	string getName() const;
	void setName(const string &name);
private:
	string _name;
	LPDIRECT3DTEXTURE9 _texture;
};
NS_JK_END


#endif // __TEXTURE_H__