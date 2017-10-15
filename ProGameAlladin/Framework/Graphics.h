#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "definitions.h"
#include "Windows.h"
#include "Texture.h"

NS_JK_BEGIN

class Graphics
{
public:
	Graphics();
	void release() const;
	void present() const;
	void init(Windows* window);
	void clearScreen() const;
	void drawSprite(const Texture &texture);

	LPDIRECT3DDEVICE9 getDevice() const;
	LPDIRECT3DSURFACE9 getSurface() const;
private:
	LPDIRECT3D9 _pD3d;
	LPDIRECT3DDEVICE9 _pDevice;
	LPDIRECT3DSURFACE9 _surface;

};

typedef Graphics* pDevice;

NS_JK_END
#endif