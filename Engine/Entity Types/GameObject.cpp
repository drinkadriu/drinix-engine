#include "stdafx.h"
#include "Public.h"
#include "GameObject.h"

GameObject::GameObject(string name, string tag, bool isactive, bool isstatic) : Entity(name, tag, isactive, isstatic)
{
	this->AddComponent<Transfrm>(b2Vec2(0.f, 0.f), 0.f, b2Vec2(1.f, 1.f));
	this->AddComponent<SprtRend>(this);
	trans = this->GetComponent<Transfrm>();
}

void GameObject::Awake()
{
	ParentTrans = GetParent()->GetComponent<Transfrm>();
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		AllComponents[i]->Awake();
	}
}

void GameObject::Update()
{
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		trans->Position = ParentTrans->Position; // Make this relative not followup
		trans->Rotation = ParentTrans->Rotation;
		if (this->GetActive()) {
			if (AllComponents.at(i)->GetActive()) {
				AllComponents.at(i)->Update();
			}
			AllComponents.at(i)->UpdateSleep();
		}
	}
}

GameObject::~GameObject()
{
}