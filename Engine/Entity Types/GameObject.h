#ifndef GameObject_h
#define GameObject_h

#include "Transfrm.h"

class Entity;

class GameObject : public Entity
{
private:
	Transfrm* trans;
	Transfrm* ParentTrans;
public:
	GameObject(string name = "lol", string tag = "lol", bool isactive = true, bool isstatic = false);
	void Update();
	void Awake();
	~GameObject();
};
#endif