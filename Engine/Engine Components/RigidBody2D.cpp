#include "stdafx.h"
#include "Public.h"
#include "RigidBody2D.h"

RigidBody2D::RigidBody2D() : Component("RigidBody2D")
{
	Trans = new Transfrm(b2Vec2(0.f, 0.f), 0.f, b2Vec2(1.f, 1.f));
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(Trans->Position.x, Trans->Position.y);
	bodyDef.gravityScale = 1.f;
	bodyDef.fixedRotation = false;
	GScale = &bodyDef.gravityScale;
	FreezeRot = &bodyDef.fixedRotation;
	Body = CurrentPhysicsWorld->CreateBody(&bodyDef);
}

RigidBody2D::RigidBody2D(float gscale, Transfrm* t, bool fixedr) : Component("RigidBody2D")
{
	Trans = t;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(Trans->Position.x, Trans->Position.y);
	bodyDef.gravityScale = gscale;
	bodyDef.fixedRotation = fixedr;
	GScale = &bodyDef.gravityScale;
	FreezeRot = &bodyDef.fixedRotation;
	Body = CurrentPhysicsWorld->CreateBody(&bodyDef);
}
RigidBody2D::~RigidBody2D() {
	//delete Trans;
	//delete GScale;
	//delete FreezeRot;
	CurrentPhysicsWorld->DestroyBody(Body);
};