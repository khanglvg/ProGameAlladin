#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "definitions.h"
#include "Windows.h"
#include "Texture.h"
#include "Matrix.h"
#include "Color.h"
#include "Rect.h"

NS_JK_BEGIN

class Graphics
{
public:
	Graphics();
	void release() const;
	void present() const;
	void init(Windows* window);
	void clearScreen() const;
	void drawSprite(const Texture &texture, const Matrix matrix, const Color color, const Rect rect);
	LPD3DXMATRIX convertToDirectMatrix(Matrix&);
	LPDIRECT3DDEVICE9 getDevice() const;
	LPDIRECT3DSURFACE9 getSurface() const;
private:
	LPDIRECT3D9 _pD3d;
	LPDIRECT3DDEVICE9 _pDevice;
	LPDIRECT3DSURFACE9 _surface;
	LPD3DXSPRITE _spriteHandler;

};

typedef Graphics* pDevice;

NS_JK_END
#endif