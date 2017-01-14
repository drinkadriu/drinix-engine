#include "stdafx.h"
#include "Public.h"
#include "SprtRend.h"

SprtRend::SprtRend() : Component("SprtRend") { 
	
};

SprtRend::SprtRend(Entity* newth, Color col, b2Vec2 size) : Component("SprtRend", newth) {
	SetColor(col);
	trans = ThisEnt->GetComponent<Transfrm>();
	if (size.x == 0)
		size = b2Vec2(Randomf(40.f, 150.f), Randomf(40.f, 150.f));
	rect.setSize(Vector2f(size.x, size.y));
	rect.setOutlineThickness(Randomf(10.5, 50.f));
	rect.setOutlineColor(GetRandColor());
	rect.setFillColor(GetRandColor());
	ID = GetSprtCounter(); 
	AllSprites.push_back(this);
	cout << "\"" << ThisEnt->GetName() << "\": Got Added, the size is: " << AllSprites.size() << endl;
};

SprtRend::SprtRend(string location, Entity* newth, bool smooth, Color col, b2Vec2 size) : Component("SprtRend", newth) { 
	texture.loadFromFile(location);
	Location = location;
	SetColor(col);
	if (size.x == 0) { // Very Slow
		rect.setSize(Vector2f(static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y)));
	}
	else {
		rect.setSize(Vector2f(size.x, size.y));
	}
	texture.setSmooth(smooth);
	rect.setTexture(&texture);
	trans = ThisEnt->GetComponent<Transfrm>();
	ID = GetSprtCounter();
	AllSprites.push_back(this);
	cout << "\"" << ThisEnt->GetName() << "\": Got Added, the size is: " << AllSprites.size() << endl;
};

SprtRend::~SprtRend()
{
	for (unsigned i = 0; i < AllSprites.size(); i++) {
		if (AllSprites.at(i)->ID == ID) {
			AllSprites.erase(AllSprites.begin() + i);
			if (ThisEnt != nullptr) {
				cout << "\"" << ThisEnt->GetName() << "\": Got Removed, the size is: " << AllSprites.size() << endl;
			}
			break;
		}
	}
}