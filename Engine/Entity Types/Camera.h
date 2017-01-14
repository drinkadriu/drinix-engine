#ifndef Camera_h
#define Camera_h

#include "Transfrm.h"

class Entity;

class Camera : public Entity
{
private:
	Transfrm* ThisTrans;
	Cam* ThisCam;
public:
	Camera(b2Vec2, b2Vec2, string name = "cam", string tag = "lol", bool isactive = true, bool isstatic = false);
	~Camera();
};
#endif