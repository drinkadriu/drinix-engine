#ifndef Cam_h
#define Cam_h

#include "Transfrm.h"

class Cam : public Component
{
private:
	float shaketime;
	float mag;
	bool shake = false;
public:
	Transfrm* trans;
	View view;
	b2Vec2 Target;
	Cam();
	Cam(Entity*, float, float, float, float);
	~Cam(); 
	void Shake(float magnitute, float time) {
		if (!shake) { 
			mag = magnitute;
			shaketime = time;
			shake = true;
		}
	}
	void Update();
};
#endif