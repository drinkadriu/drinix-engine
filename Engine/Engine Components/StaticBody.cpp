#include "stdafx.h"
#include "Public.h"
#include "StaticBody.h"


StaticBody::StaticBody(Transfrm* t) : Component("StaticBody")
{
	Trans = t;
	bodyDef.type = b2_kinematicBody;
	bodyDef.position.Set(Trans->Position.x, Trans->Position.y);
	Body = CurrentPhysicsWorld->CreateBody(&bodyDef);
}

StaticBody::~StaticBody()
{
	delete Trans;
	CurrentPhysicsWorld->DestroyBody(Body);
}