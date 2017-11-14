#include "Graphics.h"
#include <minwinbase.h>
#include "Application.h"

US_NS_JK

Graphics* Graphics::_instance = NULL;

Graphics::Graphics()
{
	_pDevice = NULL;
	_pD3D = NULL;
	_surface = NULL;
}


void Graphics::release() const
{
	if (_pDevice != NULL)
		_pDevice->Release();
	if (_pD3D != NULL)
		_pD3D->Release();
	if (_surface != NULL)
		_surface->Release();
}

void Graphics::present() const
{
	_pDevice->Present(nullptr, nullptr, nullptr, nullptr);
}

void Graphics::clearScreen() const
{
	_pDevice->ColorFill(_surface, NULL, D3DCOLOR_XRGB(0, 0, 0));
}


RECT Graphics::converttoRECT(const Rect& rect)
{
	RECT r; //top-left <=> y-x			bottom-right <=> y-x
	r.left = rect.getX();
	r.top = rect.getY();
	r.right = rect.getX() + rect.getWidth();
	r.bottom = rect.getY() + rect.getHeight();

	return r;
}

void Graphics::drawSprite(const Texture& texture, const Vec2& origin, const Matrix matrix, const Color& color, const Rect& rect, const int layer) const
{
	D3DXMATRIX oldMatrix;
	D3DXMATRIX newMatrix = convertToDirectMatrix(matrix);

	D3DXVECTOR3 center = D3DXVECTOR3(abs(rect.getWidth()* origin.getX()), abs(rect.getHeight()* (origin.getY())), 0);

	_spriteHandler->GetTransform(&oldMatrix);
	_spriteHandler->SetTransform(&newMatrix);

	_spriteHandler->Draw(texture.getTexture(), 
						&converttoRECT(rect), 
						&center,
						&D3DXVECTOR3(0.f,0.f,layer), 
						D3DCOLOR_ARGB(color.getAlpha(), color.getRed(), color.getGreen(),color.getBlue()));
	
	
	_spriteHandler->SetTransform(&oldMatrix);
}


D3DXMATRIX Graphics::convertToDirectMatrix(const Matrix &matrix)
{
	D3DXMATRIX d3DxMatrix ;

	d3DxMatrix._11 = matrix.get11();
	d3DxMatrix._12 = matrix.get12();
	d3DxMatrix._13 = matrix.get13();
	d3DxMatrix._14 = matrix.get14();

	d3DxMatrix._21 = matrix.get21();
	d3DxMatrix._22 = matrix.get22();
	d3DxMatrix._23 = matrix.get23();
	d3DxMatrix._24 = matrix.get24();

	d3DxMatrix._31 = matrix.get31();
	d3DxMatrix._32 = matrix.get32();
	d3DxMatrix._33 = matrix.get33();
	d3DxMatrix._34 = matrix.get34();

	d3DxMatrix._41 = matrix.get41();
	d3DxMatrix._42 = matrix.get42();
	d3DxMatrix._43 = matrix.get43();
	d3DxMatrix._44 = matrix.get44();

	return d3DxMatrix;
}

LPDIRECT3DDEVICE9 Graphics::getDevice() const
{
	return _pDevice;
}

LPDIRECT3DSURFACE9 Graphics::getSurface() const
{
	return _surface;
}

void Graphics::loadTexture(Texture& texture, const Color& transcolor)
{
	D3DXIMAGE_INFO info; // Create a variable for Texture's info
	LPDIRECT3DTEXTURE9 directXTexture;
	HRESULT result = D3DXGetImageInfoFromFile(texture.getSrcFile().c_str(), &info);	// a variable to check if it's ok

	D3DXCreateTextureFromFileEx(
		_pDevice,
		texture.getSrcFile().c_str(),
		info.Width,
		info.Height,
		1,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(transcolor.getRed(), transcolor.getGreen(), transcolor.getBlue()),
		&info,
		nullptr,
		&directXTexture);

	texture.setTexture(directXTexture);

	if(result != D3D_OK) // Check if result will create
	{
		throw exception("Result is not OK");
	}
}

Graphics* Graphics::getInstance()
{
	if(_instance == nullptr)
	{
		_instance = new Graphics();
	}
	return _instance;
}

void Graphics::beginRender()
{
	if(_pDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0x000000, 0.0f, 0) != D3D_OK)
	{
		_pDevice->Present(0, 0, 0, 0);
	}
	_pDevice->BeginScene();
	_spriteHandler->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_BACKTOFRONT);
}

void Graphics::endRender()
{
	_spriteHandler->End();
	_pDevice->EndScene();

	_pDevice->Present(0, 0, 0, 0);
}

void Graphics::init()
{
	_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS parameter;

	ZeroMemory(&parameter, sizeof(parameter));
	parameter.SwapEffect = D3DSWAPEFFECT_DISCARD;
	parameter.Windowed = true;
	parameter.hDeviceWindow = _hWnd;
	parameter.BackBufferFormat = D3DFMT_A8R8G8B8;
	parameter.BackBufferCount = 1;
	parameter.BackBufferHeight = _screenHeight;
	parameter.BackBufferWidth = _screenWidth;

	_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&parameter,
		&_pDevice);

	if (_pDevice == NULL)
	{
		throw exception("Cannot create device!");
	}

	_pDevice->GetBackBuffer(NULL, NULL, D3DBACKBUFFER_TYPE_MONO, &_surface);
	D3DXCreateSprite(_pDevice, &_spriteHandler);
}
