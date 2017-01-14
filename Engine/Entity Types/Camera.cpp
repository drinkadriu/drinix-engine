#include "stdafx.h"
#include "Public.h"
#include "Camera.h"

Camera::Camera(b2Vec2 Pos, b2Vec2 Scl, string name, string tag, bool isactive, bool isstatic) : Entity(name, tag, isactive, isstatic)
{
	this->AddComponent<Transfrm>();
	ThisTrans = this->GetComponent<Transfrm>();
	ThisTrans->Position = Pos;
	ThisTrans->Scale = Scl;
	this->AddComponent<Cam>(this, Pos.x, Pos.y, Scl.x, Scl.y);
	ThisCam = this->GetComponent<Cam>();
	CurrentCam = ThisCam;
}

Camera::~Camera()
{
}
