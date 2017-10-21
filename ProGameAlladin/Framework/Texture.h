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
	LPDIRECT3DTEXTURE9 getTextute();
	void setTexture(LPDIRECT3DTEXTURE9);
	const string& getName();
	void setName(const string &name);
private:
	string _name;
	LPDIRECT3DTEXTURE9 _texture;
};
NS_JK_END


#endif // __TEXTURE_H__