#include "stdafx.h"
#include "Public.h"
#include "Cam.h"

Cam::Cam() : Component("Cam")
{
	CurrentCam = this;
}

Cam::Cam(Entity* ent, float nx, float ny, float width, float height) : Component("Cam", ent) 
{
	trans = ThisEnt->GetComponent<Transfrm>();
	view.reset(FloatRect(nx, ny, width, height));
	CurrentCam = this;
}

Cam::~Cam()
{
}

void Cam::Update()
{
	view.setCenter(trans->Position.x, trans->Position.y);
	if (shake) {
		if (shaketime > 0) {
			view.setCenter(view.getCenter().x+Randomf(-mag, mag), view.getCenter().y + Randomf(-mag, mag));
			shaketime -= Time::countdt;
		}
		else {
			shake = false;
			shaketime = 0.f;
			mag = 0.f;
		}
	}
}
