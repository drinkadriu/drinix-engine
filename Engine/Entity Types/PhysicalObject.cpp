#include "stdafx.h"
#include "Public.h"
#include "PhysicalObject.h"

PhysicalObject::PhysicalObject(bool isStatic, string location, float x, float y, float boxwidth, float boxheight, float gscale, bool fixedr, float nDnsity, float nFricton, string name, string tag, bool isactive, bool isstatic) : Entity(name, tag, isactive, isstatic)
{
	IsStatic = isStatic;
	this->AddComponent<Transfrm>(b2Vec2(x, y), 0.f, b2Vec2(1.f, 1.f));
	trans = this->GetComponent<Transfrm>(); 
	if (location != "null") {
		this->AddComponent<SprtRend>(location, this);
		if (boxwidth == 0) {
			boxwidth = (this->GetComponent<SprtRend>()->rect.getSize().x)/2;
			boxheight = (this->GetComponent<SprtRend>()->rect.getSize().y)/2;
		}
	}
	else {
		this->AddComponent<SprtRend>(this);
		if (boxwidth == 0) {
			boxwidth = (this->GetComponent<SprtRend>()->rect.getSize().x) / 2;
			boxheight = (this->GetComponent<SprtRend>()->rect.getSize().y) / 2;
		}
	}
	if (isStatic) {
		this->AddComponent<StaticBody>(trans);
		sbody = this->GetComponent<StaticBody>();
		sbody->Trans = trans;
		this->AddComponent<BoxCollider>(sbody->Body, boxwidth, boxheight, nDnsity, nFricton);
	}
	else {
		this->AddComponent<RigidBody2D>(gscale, trans, fixedr);
		rigidb = this->GetComponent<RigidBody2D>();
		rigidb->Trans = trans;
		this->AddComponent<BoxCollider>(rigidb->Body, boxwidth, boxheight, nDnsity, nFricton);
	}
	boxc = this->GetComponent<BoxCollider>();
}

void PhysicalObject::Update() {
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		//trans->Position = ParentTrans->Position; // Make this relative not followup
		//trans->Rotation = ParentTrans->Rotation;
		if (this->GetActive()) {
			if (AllComponents.at(i)->GetActive()) {
				AllComponents.at(i)->Update();
			}
			AllComponents.at(i)->UpdateSleep();
		}
	} 
	if (!IsStatic) {
		trans->Position = rigidb->Body->GetPosition();
		trans->Rotation = rigidb->Body->GetAngle();
	}
}

void PhysicalObject::Awake()
{
	ParentTrans = GetParent()->GetComponent<Transfrm>();
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		AllComponents[i]->Awake();
	}
}

PhysicalObject::~PhysicalObject()
{
}
