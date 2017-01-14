#ifndef PhWorld_h
#define PhWorld_h

class PhWorld :
	public World
{
public:
	b2Vec2 Gravity;
	b2World* PhysicsWorld = new b2World(b2Vec2(0.f, 0.f));
	int32 velocityIterations = 10;
	int32 positionIterations = 5; 
	PhWorld(string name) : World(name) {
		Gravity = b2Vec2(0.f, 800.f);
		PhysicsWorld = new b2World(Gravity);
		CurrentPhysicsWorld = this->PhysicsWorld;
		CurrentWorld = this;
	}
	void Update(float dt = 0);
	~PhWorld() { 

	}
};
#endif 