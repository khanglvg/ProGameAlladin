#ifndef __CAMERA_H__

#define __CAMERA_H__

#include "Vec2.h"
#include "Rect.h"
#include "Node.h"


NS_JK_BEGIN
class Graphics;

class Camera : public Node
{
private:
	// width - height of Camera
	float _width, _height;

	// Node that the camera will follow is.
	Node *_following;

	// Matrix view the camare show.
	D3DXMATRIX _viewMatrix;

	//
	D3DXMATRIX _identityMatrix;

	//
	D3DXMATRIX _orthographicMatrix;

	//
	Vec2 _scaleFactors;

	// Camera's position
	float _cameraX;
	float _cameraY;

	// Camera's position old
	float _oldCameraX;
	float _oldCameraY;

	bool _isStart;

	float _angle;

	static Camera *_instance;

	bool _isUp = false;

public: // SET-GET
	float getWidth() const;
	void setWidth(const float& width);

	float getHeight() const;
	void setHeight(const float& height);

	bool isUp() const;
	void setUp(const bool& isUp);

	float getCameraX() const;
	void setCameraX(const float& cameraX);

	float getCameraY() const;
	void setCameraY(const float& cameraY);

	Vec2 getScaleFactor() const;
	void setScaleFactor(const Vec2& scaleFactor);
public:
	// Constructor
	Camera();
	Camera(const float& width, const float& height, const float& angle);

	// virtual Destructor
	virtual ~Camera();

	static Camera* getInstance();

	void update() override;

	void release() override;

	void follow(Node *player);

	Node* nodeIsFollowing() const;

	bool isFollowing() const;

	void unFollow();

	void setTransform(Graphics *pDevice) const;

	static D3DXMATRIX convertToDirectMatrix(const Matrix &matrix);

	Rect getRect() override;

};

NS_JK_END

#endif __CAMERA_H__
