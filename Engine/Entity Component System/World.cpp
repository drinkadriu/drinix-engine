#include "stdafx.h"
#include "Public.h"
#include "World.h"

World::World(string newName)
{
	TScale = Time::TimeScale;
	Name = newName;
	AllWorlds.push_back(this);
}

World& World::operator=(const World& other) {
	this->Name = other.Name;	
	this->AllEntities = other.AllEntities;

	return *this;
}

Entity* World::GetEntityName(string name) {
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name) {
			return AllEntities.at(i);
			break;
		}
}
Entity* World::GetEntityTag(string tag) {
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetTag() == tag) {
			return AllEntities.at(i);
			break;
		}
}
Entity* World::GetEntity(string name, string tag) {
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name && AllEntities.at(i)->GetTag() == tag) {
			return AllEntities.at(i);
			break;
		}
}
Entity* World::GetEntity(int id) {
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetID() == id) {
			return AllEntities.at(i);
			break;
		}
}
void World::PrintAll() {
	cout << "\nPrinting " << AllEntities.size() << " Entities Of the World: \"" << this->Name << "\":\n\n";
	for (unsigned i = 0; i < AllEntities.size(); i++) {
		cout << "AllEntities(" << i+1 << "):\t";
		AllEntities.at(i)->PrintAll();
	}
}
void World::KillName(string name) {
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name) {
			AllEntities.at(i)->RemoveAllComponents();
			AllEntities.at(i)->~Entity();
			AllEntities.erase(AllEntities.begin() + i);
			break;
		}
}
void World::KillTag(string tag) {
	string teg = tag;
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetTag() == teg) {
			AllEntities.at(i)->RemoveAllComponents();
			AllEntities.at(i)->~Entity();
			AllEntities.erase(AllEntities.begin() + i);
			break;
		}
}
void World::Kill(string name, string tag) {
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetName() == name && AllEntities.at(i)->GetTag() == tag) {
			AllEntities.at(i)->RemoveAllComponents();
			AllEntities.at(i)->~Entity();
			AllEntities.erase(AllEntities.begin() + i);
			break;
		}
}
void World::Kill(int id) {
	for (unsigned i = 0; i < AllEntities.size(); i++)
		if (AllEntities.at(i)->GetID() == id) {
			AllEntities.at(i)->RemoveAllComponents();
			AllEntities.at(i)->~Entity();
			AllEntities.erase(AllEntities.begin() + i);
			break;
		}
}
void World::PrintNumberOfEntities() {
	cout << this->Name << ": Number of Entities: " << AllEntities.size() << endl;
}
int World::NumberOfEntities() {
	return AllEntities.size();
}

Entity World::Create(Entity prefab) {
	Entity newEnt = prefab;
	newEnt.SetNewID();
	AllEntities.push_back(&newEnt);
	return newEnt;
}

Entity* World::Create(string name, string tag, bool isstatic) {
	Entity* newE = new Entity(name, tag, isstatic, true);
	newE->SetNewID();
	AllEntities.push_back(newE);
	return newE;
}

void World::Awake()
{
	Time::TimeScale = Time::OverAllScale;
	for (unsigned i = 0; i < AllEntities.size(); i++) {
		AllEntities.at(i)->Awake();
	}
}


void World::Start()
{
	for (unsigned i = 0; i < AllEntities.size(); i++) {
		if (AllEntities.at(i)->GetActive())
			AllEntities.at(i)->Start();
	}
}

void World::Update(float dt)
{
		for (unsigned i = 0; i < AllEntities.size(); i++) {
			Entity* ent = AllEntities.at(i);
			if (ent->IsTarget) {
				if (ent->KillTime > 0) {
					ent->KillTime -= Time::countdt;
				}
				else {
					ent->Kill();
				}
			}
			ent->Update();
			ent->OnEnabled();
			delete ent;
		}
}

void World::FixedUpdate() {
		Runner += Time::dt;
		if (Runner >= 1.f) {
			for (unsigned i = 0; i < AllEntities.size(); i++) {
				AllEntities.at(i)->FixedUpdate();
			}
			Runner = 0.f;
		}
}

void World::SetTScale(float newt)
{
	this->TScale = Time::TimeScale = newt;
	Time::once = false;
}

string World::GetName()
{
	return Name;
}

World::~World()
{
}
