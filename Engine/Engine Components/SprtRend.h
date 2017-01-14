#ifndef SprtRend_h
#define SprtRend_h

#include "Transfrm.h"

class SprtRend : public Component
{
public:
	SprtRend();
	SprtRend(Entity*, Color col = Color::White, b2Vec2 size = b2Vec2(0, 0));
	SprtRend(string, Entity*, bool smooth = true, Color col = Color::White, b2Vec2 size = b2Vec2(0, 0));

	unsigned ID;

	Color color;
	bool Smooth = true;
	RectangleShape rect;
	Texture texture;
	Transfrm* trans;
	string Location;

	void SetColor(Color newc) {
		color = newc;
		rect.setFillColor(color);
	}

	void Update() {
		rect.setPosition(Vector2f(trans->Position.x-rect.getSize().x/2, trans->Position.y - rect.getSize().y/2));
	}

	~SprtRend();
};
#endif