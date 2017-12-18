#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "definitions.h"
#include "Windows.h"
#include "Texture.h"
#include "Matrix.h"
#include "Color.h"
#include "Rect.h"
#include "Vec2.h"

// Tham khảo: www.stdio.vn/articles/read/600/load-sprite-trong-directx-9

NS_JK_BEGIN
	class Application;

	class Graphics
{
	friend class Application;

public:  //tat ca cac ham convert deu ghi vao class Graphics
	Graphics();
	void release() const;
	void present() const;
	void init();
	void clearScreen() const;
	void drawSprite(const Texture &texture, const Vec2& origin, const Matrix matrix, const Color& color, const Rect& rect, const int layer) const;
	static D3DXMATRIX convertToDirectMatrix(const Matrix& matrix);
	static RECT Graphics::converttoRECT(const Rect& rect);
	LPDIRECT3DDEVICE9 getDevice() const;
	LPDIRECT3DSURFACE9 getSurface() const;
	LPD3DXSPRITE getSprite() const;
	void loadTexture(Texture& texture, const Color& transcolor = Color(255,0,255,255));
	static Graphics* getInstance();

	void beginRender();
	void endRender();

private:

	static Graphics* _instance;
	LPDIRECT3D9 _pD3D;
	LPDIRECT3DDEVICE9 _pDevice;
	LPDIRECT3DSURFACE9 _surface;
	LPD3DXSPRITE _spriteHandler; //SpriteHandler ho tro ve hinh
/*	Khai báo : 
 		Sprite Handler, Texture, Information of sprite
	Khởi tạo :
		D3DXCreateSprite:				gắn sprite handler vào Direct3D và device
		D3DXGetImageInfoFromFile :		lấy thông tin Sprite
		D3DXCreateTextureFromFileEx :	khởi tạo texture chứa Sprite
	Vẽ :
		LPD3DXSPRITE::Begin
		LPD3DXSPRITE::Draw
		LPD3DXSPRITE::End*/

	HINSTANCE _hInstance;
	int _screenWidth;
	int _screenHeight;
	HWND _hWnd;


};

typedef Graphics* pDevice;

NS_JK_END
#endif