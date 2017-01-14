#pragma once
#include "Component.h"
class StaticBody :
	public Component
{
private:
	float Density = 1.f;
	float Friction = 1.f;
	b2BodyDef bodyDef;
public:
	Transfrm* Trans;
	b2Body* Body;
	StaticBody(Transfrm* t = new Transfrm(b2Vec2(0.f, 0.f), 0.f, b2Vec2(1.f, 1.f)));
	~StaticBody();
};

