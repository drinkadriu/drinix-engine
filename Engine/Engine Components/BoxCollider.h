#pragma once
#include "Component.h"
#include "RigidBody2D.h"
class BoxCollider :
	public Component
{
private:
	float *Density;
	float *Friction;
	b2BodyDef bodyDef;
	b2PolygonShape Box;
public:
	b2FixtureDef fixtureDef;
	BoxCollider();
	BoxCollider(b2Body*, float, float, float nDnsty = 1.f, float nFrcton = 0.6f);
	float GetDensity() { return *Density; }
	float GetFriction() { return *Friction; }
	void SetDensity(float newd) { *Density = newd; }
	void SetFriction(float newf) { *Friction = newf; }
	~BoxCollider();
};

