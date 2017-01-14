#include "stdafx.h"
#include "Public.h"
#include "Entity.h"

Entity::Entity(string name, string tag, bool isactive, bool isstatic)
{
	this->ID = GetCounter();
	this->Name = UniqueName(name);
	this->Tag = UniqueTag(tag);
	this->IsStatic = isstatic;
	this->IsActive = isactive;
	CurrentWorld->AllEntities.push_back(this);
	ThisWorld = CurrentWorld;
}

int Entity::GetID() { return this->ID; }
string Entity::GetName() { return this->Name; }
string Entity::GetTag() { return this->Tag; }
void Entity::PrintAll() {
	cout << "NAME: \"" << Name << "\" TAG: \"" << Tag << "\" ID: \"" << ID << "\"" << endl;
}
void Entity::PrintAllComps() {
	cout << "\"" << Name << "\", \"" << Tag << "\" Tag, Is Printing: " << GetAllCompsSize() << " Components:" << endl;
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		cout << "Component(" << i + 1 << ") = \"" << AllComponents.at(i)->Type << "\"" << endl;
	}
}
void Entity::SetAll(string newn, string newt, bool newis, bool newisa) {
	this->Name = UniqueName(newn);
	this->Tag = UniqueTag(newt);
	this->IsStatic = newisa;
	SetActive(newis);
}

void Entity::SetNewID() {
	this->ID = GetCounter();
}

bool Entity::GetStatic() {
	return this->IsStatic;
}


int Entity::GetAllCompsSize() {
	return AllComponents.size();
}

void Entity::Awake()
{
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		AllComponents[i]->Awake();
	}
}

void Entity::Start() {
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		AllComponents[i]->Start();
	}
}
void Entity::Update() {
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		if (IsActive) {
			if (AllComponents.at(i)->GetActive()) {
				AllComponents.at(i)->Update();
			}
			AllComponents.at(i)->UpdateSleep();
		}
	}
}

void Entity::FixedUpdate()
{
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		for (unsigned i = 0; i < AllComponents.size(); i++) {
			if (IsActive) {
				if (AllComponents.at(i)->GetActive()) {
					AllComponents.at(i)->FixedUpdate();
				}
			}
		}
	}
}

void Entity::OnEnabled()
{
	for (unsigned i = 0; i < AllComponents.size(); i++) {
		if (IsActive && !LastActive) {
			AllComponents.at(i)->OnEnabled();
			LastActive = IsActive;
		}
	}
}

void Entity::Kill(float time) {
	cout << "Killing: " << Name << ", " << Tag << endl;
	if (time != 0) {
		IsTarget = true;
		KillTime = time;
	}
	else {
		ThisWorld->Kill(Name, Tag);
		RemoveAllComponents();
		this->~Entity();
	}
}

Entity::~Entity()
{
}
