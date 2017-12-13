#include "Texture.h"

US_NS_JK
Texture::Texture()
	: _texture(nullptr)
{
}

Texture::~Texture()
{
}

LPDIRECT3DTEXTURE9 Texture::getTexture() const
{
	return _texture;
}

void Texture::setTexture(const LPDIRECT3DTEXTURE9& texture)
{
	_texture = texture;
}

string Texture::getName() const
{
	return _name;
}

void Texture::setName(const string &name)
{
	_name = name;
}

string Texture::getSrcFile() const
{
	return _srcFile;
}

void Texture::setSrcFile(const string& srcFile)
{
	_srcFile = srcFile;
}
