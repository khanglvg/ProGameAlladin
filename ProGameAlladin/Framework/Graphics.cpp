#include "Graphics.h"
#include <minwinbase.h>

US_NS_JK

Graphics::Graphics()
{
	_pDevice = NULL;
	_pD3d = NULL;
	_surface = NULL;
}


void Graphics::release() const
{
	if (_pDevice != NULL)
		_pDevice->Release();
	if (_pD3d != NULL)
		_pD3d->Release();
	if (_surface != NULL)
		_surface->Release();
}

void Graphics::present() const
{
	_pDevice->Present(0, 0, 0, 0);
}

void Graphics::clearScreen() const
{
	_pDevice->ColorFill(_surface, NULL, D3DCOLOR_XRGB(0, 0, 0));
}

void Graphics::drawSprite(const Texture & texture, const Matrix matrix, const Color color, const Rect rect)
{
	
}

LPD3DXMATRIX Graphics::convertToDirectMatrix(Matrix &matrix)
{
	return LPD3DXMATRIX();
}

LPDIRECT3DDEVICE9 Graphics::getDevice() const
{
	return _pDevice;
}

LPDIRECT3DSURFACE9 Graphics::getSurface() const
{
	return _surface;
}

void Graphics::init(Windows* window)
{
	_pD3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS parameter;

	ZeroMemory(&parameter, sizeof(parameter));
	parameter.SwapEffect = D3DSWAPEFFECT_DISCARD;
	parameter.Windowed = !window->isFullScreen();
	parameter.hDeviceWindow = window->getWindow();
	parameter.BackBufferFormat = D3DFMT_A8R8G8B8;
	parameter.BackBufferCount = 1;
	parameter.BackBufferHeight = window->getHeight();
	parameter.BackBufferWidth = window->getWidth();

	_pD3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		window->getWindow(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&parameter,
		&_pDevice);

	if (_pDevice == NULL)
	{
		throw exception("Cannot create device!");
	}

	_pDevice->GetBackBuffer(NULL, NULL, D3DBACKBUFFER_TYPE_MONO, &_surface);
}