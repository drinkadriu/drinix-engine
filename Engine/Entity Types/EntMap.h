#pragma once
#ifndef EntMap_h
#define EntMap_h

class EntMap
{
public:
	int ID;
	Entity* Ent;
	EntMap(Entity* newe, int newid) {
		Ent = newe;
		ID = newid;
	}
	~EntMap();
};
#endif