#include "stdafx.h"
#include "Public.h"
#include "Component.h"

Component::Component(char* newt) : Type(newt) {};
Component::Component(char* newtt, Entity* newthisent) : ThisEnt(newthisent), Type(newtt) { isActive = ThisEnt->GetActive(); };

void Component::UpdateSleep() {
	if (isSleep) {
		cout << "Sleeping" << endl;
		if (SleepTime > 0) {
			SleepTime -= Time::countdt;
			isActive = false;
		}
		else {
			cout << "Sleept" << endl;
			SleepTime = 0.f;
			isSleep = false;
			isActive = true;
		}
	}
}

void Component::SetType(char* newt)
{
	Type = newt;
}

Component::~Component()
{ 
}