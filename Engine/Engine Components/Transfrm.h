#pragma once
#include "Component.h"
#include "Public.h"

class Transfrm : public Component
{
public:
	Transfrm() : Component("Transfrm") {};
	Transfrm(b2Vec2 newPosition, float32 newRotation, b2Vec2 newScale) : Component("Transfrm") { Position = newPosition; Rotation = newRotation; Scale = newScale; };
	b2Vec2 Position;
	float32 Rotation;
	b2Vec2 Scale;
	~Transfrm();
};

