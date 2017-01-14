#include "stdafx.h"
#include "Public.h"
#include "Txt.h"

Txt::Txt() : Component("Txt")
{
}

Txt::Txt(Entity* newe, string txt, string loc, unsigned siz, Color newc, float x, float y, float xoffset, float yoffset) : Component("Txt", newe)
{
	if (loc == "def")
		loc = "fonts/consola.ttf";
	SetSize(siz);
	trans = new Transfrm(b2Vec2((x + xoffset) - width / 2, (y + yoffset) - height / 2), 0, b2Vec2(1, 1));
	xOff = xoffset;
	yOff = yoffset;
	SetWords(txt);
	SetFont(loc);
	SetColor(newc);
	tekst.setPosition(trans->Position.x, trans->Position.y);
	AllTexts.push_back(this);
}
Txt::~Txt()
{
}