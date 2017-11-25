#ifndef __CAMERA_H__

#define __CAMERA_H__

#include "Vec2.h"
#include "Rect.h"
#include "Node.h"

NS_JK_BEGIN

class Camera: public Node
{
private:
	// is Camera pause?
	bool _isStop;

	// width - height of Camera
	float _width, _height;

	float _startX;
	float _startY;

public: // SET-GET
	float getWidth() const;
	void setWidth(const float& width);

	float getHeight() const;
	void setHeight(const float& height);


public:

	Camera();
	// Constructor
	Camera(const float& width, const float& height);

	// virtual Destructor
	virtual ~Camera();

	void update() override;

	void release() override;

	void stop();

	// tạo ra ma trận biến hình (-x,-y)
	//Matrix getTransformMatrix();  
};

NS_JK_END

#endif __CAMERA_H__
