#ifndef __DEVICE_H__
#define __DEVICE_H__

#include "definitions.h"
#include "Windows.h"

NS_JK_BEGIN

class Device
{
public:
  Device(); 
  void release() const;
  void present() const;
  void init(Windows* window);
  void clearScreen() const;
  
  LPDIRECT3DDEVICE9 getDevice() const;
  LPDIRECT3DSURFACE9 getSurface() const;
private:
  LPDIRECT3D9 _pD3d;
  LPDIRECT3DDEVICE9 _pDevice;
  LPDIRECT3DSURFACE9 _surface;

};

typedef Device* pDevice;

NS_JK_END
#endif
