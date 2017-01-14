#include "stdafx.h"
#include "Public.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider() : Component("BoxCollider") {

}

BoxCollider::BoxCollider(b2Body* bod, float width, float height, float nDnsty, float nFrcton) : Component("BoxCollider")
{
	Box.SetAsBox(width, height);
	fixtureDef.shape = &Box;
	fixtureDef.density = nDnsty;
	fixtureDef.friction = nFrcton;
	Density = &fixtureDef.density;
	Friction = &fixtureDef.friction;
	bod->CreateFixture(&fixtureDef);
}


BoxCollider::~BoxCollider()
{
}
