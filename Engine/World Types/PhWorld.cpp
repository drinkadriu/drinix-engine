#include "stdafx.h"
#include "Public.h"
#include "PhWorld.h"

void PhWorld::Update(float dt) {
	PhysicsWorld->Step(dt, velocityIterations, positionIterations);
	for (unsigned i = 0; i < AllEntities.size(); i++) {
		if (AllEntities.at(i)->IsTarget) {
			if (AllEntities.at(i)->KillTime > 0) {
				AllEntities.at(i)->KillTime -= Time::countdt;
			}
			else {
				AllEntities.at(i)->Kill();
			}
		}
		AllEntities.at(i)->Update();
		AllEntities.at(i)->OnEnabled();
	}
}
