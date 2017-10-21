#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

LPDIRECT3DTEXTURE9 Texture::getTextute()
{
	return _texture;
}

void Texture::setTexture(LPDIRECT3DTEXTURE9 texture)
{
	_texture = texture;
}

const string& Texture::getName() 
{
	return _name;
}

void Texture::setName(const string &name)
{
	_name = name;
}
