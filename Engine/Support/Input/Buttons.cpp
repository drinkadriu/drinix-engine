#include "stdafx.h"
#include "Public.h"
#include "Buttons.h"

Buttons::Buttons(Key k1, Key k2)
{
	if (k1.IsMouseInput)
		positive.SetMouseCode(k1.mousecode);
	else
		positive.SetKeyCode(k1.keycode);
	if (k2.IsMouseInput)
		negative.SetMouseCode(k2.mousecode);
	else
		negative.SetKeyCode(k2.keycode);
	Val = 0;
	AllButtons.push_back(this);
}
Buttons::Buttons(Key* k1, Key* k2)
{
	if (k1->IsMouseInput)
		positive.SetMouseCode(k1->mousecode);
	else
		positive.SetKeyCode(k1->keycode);
	if (k2->IsMouseInput)
		negative.SetMouseCode(k2->mousecode);
	else
		negative.SetKeyCode(k2->keycode);
	Val = 0;
	AllButtons.push_back(this);
}
Buttons::Buttons(Keyboard::Key k1, Keyboard::Key k2)
{
	positive.SetKeyCode(k1);
	negative.SetKeyCode(k2);
	Val = 0;
	AllButtons.push_back(this);
}
Buttons::Buttons(Mouse::Button k1, Mouse::Button k2)
{
	positive.SetMouseCode(k1);
	negative.SetMouseCode(k2);
	Val = 0;
	AllButtons.push_back(this);
}

void Buttons::Update()
{
	if (positive.GetKey())
		Valpos = 1;
	else
		Valpos = 0;
	if (negative.GetKey())
		Valneg = -1;
	else
		Valneg = 0;
	Val = Valpos + Valneg;
}

float* Buttons::Return()
{
	return &Val;
}

float Buttons::Get()
{
	return Val;
}


Buttons::~Buttons()
{
}
