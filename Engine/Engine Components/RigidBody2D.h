#pragma once
#include "Component.h"
#include "Transfrm.h"		

class RigidBody2D :	public Component
{
public:
	b2BodyDef bodyDef;
	Transfrm* Trans;
	b2Body* Body;
	float* GScale;
	bool* FreezeRot;
	bool IsKinematic;

	void SetGScale(float newgs){
		*GScale = newgs;
	}
	void SetFreezeRot(bool newfr) {
		*FreezeRot = newfr;
	}
	void SetIsKinetic(bool newisk) {
		IsKinematic = newisk;
	}
	RigidBody2D();
	RigidBody2D(float gscale, Transfrm* t = new Transfrm(b2Vec2(0.f, 0.f), 0.f, b2Vec2(1.f, 1.f)), bool fixedr = false);
	~RigidBody2D();
};