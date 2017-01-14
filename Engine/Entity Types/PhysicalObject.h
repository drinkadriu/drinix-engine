#ifndef PhysicalObject_h
#define PhysicalObject_h

#include "Transfrm.h"
#include "RigidBody2D.h"
#include "StaticBody.h"
#include "BoxCollider.h"

class Entity;

class PhysicalObject : public Entity
{
public:
	Transfrm* trans;
	Transfrm* ParentTrans;
	RigidBody2D* rigidb;
	StaticBody* sbody;
	BoxCollider* boxc;
	bool IsStatic;
	PhysicalObject(bool isStatic = false, string location = "null", float x = 0, float y = 0, float boxwidth = 0, float boxheight = 0, float gscale = 1.f, bool fixedr = false, float nDnsity = 1.f, float nFricton = .6f, string name = "lol", string tag = "lol", bool isactive = true, bool isstatic = false);
	void Update();
	void Awake();
	void PrintCurrentPos() {
		cout << "\"" << this->GetName() << "\".Position: \tX: " << trans->Position.x << "\tY: " << trans->Position.y << endl;
	}
	~PhysicalObject();
};
#endif