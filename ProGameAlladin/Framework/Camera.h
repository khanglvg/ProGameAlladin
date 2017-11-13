#ifndef __CAMERA_H__

#define __CAMERA_H__

#include "Vec2.h"
#include "Rect.h"

NS_JK_BEGIN

class Camera
{
private:
	static Camera* _instance;

	// Camera's position in Game Scene, co-ordinate is defined: top-left
	Vec2 _position;

	// Camera's velocity to move 
	float _vx, _vy;

	// is Camera pause?
	bool _isPause;

	// width - height of Camera
	float _width, _height;



public: // SET-GET
	float getVX() const;
	void setVX(const float& vx);

	float getVY() const;
	void setVY(const float& vy);

	Vec2 getPosition() const;
	void setPosition(const Vec2& position);

	float getWidth() const;
	void setWidth(const float& width);

	float getHeight() const;
	void setHeight(const float& height);



public:
	// Constructor
	Camera();

	// virtual Destructor
	virtual ~Camera();

	// Camera is singleton
	static Camera* getInstance();


	// Update Camera's position with time
	// param:	FLOAT time
	// return:	void
	void Update(float time);

	// To stop the camera
	// param:	no
	// return:	void
	void Stop();

	// To set the camera to move
	// param:	no
	// return:	no
	void Move();
};

NS_JK_END

#endif __CAMERA_H__
