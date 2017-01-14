#pragma once
#ifndef Txt_h
#define Txt_h
#include "Component.h"
class Txt : public Component
{
	Text tekst;
	string Words;
	Font font;
	unsigned size;
	Color color;
	float xOff;
	float yOff;
	float width = 664;
	float height = 79;
public:
	Transfrm* trans;
	void SetWords(string neww) {
		Words = neww;
		tekst.setString(Words);
	}
	void SetFont(string newf) {
		font.loadFromFile(newf);
		tekst.setFont(font);
	}
	void SetSize(unsigned news) {
		if (news > 0) {
			size = news;
			tekst.setCharacterSize(size);
		}
	}
	void SetColor(Color news) {
		color = news;
		tekst.setColor(color);
	}
	Color GetColor() {
		return color;
	}
	unsigned GetSize() {
		return size;
	}
	string GetWords() {
		return Words;
	}
	Font GetFont() {
	 	return font;
	}
	Text GetText() {
		return tekst;
	}
	void Update() {
		trans->Position = ThisEnt->GetComponent<Transfrm>()->Position;
		trans->Position.x += xOff;
		trans->Position.y += yOff;
		tekst.setPosition(Vector2f(trans->Position.x - width / 2, trans->Position.y - height / 2));
	}
	Txt(); 
	Txt(Entity*, string, string loc = "def", unsigned siz = 12, Color newc = Color::White, float x = 0, float y = 0, float xoffset = 0, float yoffset = 0);
	~Txt();
};
#endif