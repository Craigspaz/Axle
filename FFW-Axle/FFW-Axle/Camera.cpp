#include "Camera.h"
#include "Exception.h"


Camera::Camera(glm::vec3 position)
{
	_position = position;
}


Camera::~Camera()
{
}

glm::vec3 Camera::getPosition()
{
	return _position;
}

float Camera::getPitch()
{
	return _pitch;
}

float Camera::getRoll()
{
	return _roll;
}

float Camera::getYaw()
{
	return _yaw;
}

void Camera::move(InputHandler* handler)
{
	checkIfNULL(handler, "Null InputHandler passed to camera", EXCEPTION_THROW);
	// TODO: Handle camera movement
}
