#ifndef World_h
#define World_h

class World
{
public:
	float Runner = 0.f;
	float TScale;
	string Name = "";
	vector <Entity*> AllEntities;
	Entity* lastEntity;
	World(string);
	World& operator=(const World& other);
	Entity* GetEntityName(string);
	Entity* GetEntityTag(string);
	Entity* GetEntity(string, string);
	Entity* GetEntity(int);
	void PrintAll();
	void KillName(string);
	void KillTag(string);
	void Kill(string, string);
	void Kill(int);
	void PrintNumberOfEntities();
	int NumberOfEntities();
	Entity Create(Entity);
	Entity* Create(string name = "lol", string tag = "lol", bool isstatic = false);
	void Awake();
	void Start();
	virtual void Update(float dt = 0);
	void FixedUpdate();
	void SetTScale(float);
	string GetName();
	~World();
};
#endif