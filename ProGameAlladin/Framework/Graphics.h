#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "definitions.h"
#include "Windows.h"
#include "Texture.h"
#include "Matrix.h"
#include "Color.h"
#include "Rect.h"
#include "Vec2.h"

NS_JK_BEGIN

class Graphics
{
public:  //tat ca cac ham convert deu ghi vao class Graphics
	Graphics();
	void release() const;
	void present() const;
	void init(Windows* window);
	void clearScreen() const;
	void drawSprite(const Texture &texture, const Vec2& origin, const Matrix& matrix, const Color& color, const Rect& rect) const;
	static LPD3DXMATRIX convertToDirectMatrix(const Matrix& matrix);
	static RECT Graphics::converttoRECT(const Rect& rect);
	LPDIRECT3DDEVICE9 getDevice() const;
	LPDIRECT3DSURFACE9 getSurface() const;
private:
	LPDIRECT3D9 _pD3D;
	LPDIRECT3DDEVICE9 _pDevice;
	LPDIRECT3DSURFACE9 _surface;
	LPD3DXSPRITE _spriteHandler; //SpriteHandler ho tro ve hinh

};

typedef Graphics* pDevice;

NS_JK_END
#endif