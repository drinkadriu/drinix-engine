#pragma once
#ifndef Buttons_h
#define Buttons_h
class Buttons
{
public:
	Key positive = Key();
	Key negative = Key();
	float Val = 0.f;
	float Valpos = 0.f;
	float Valneg = 0.f;
	Buttons(Key, Key);
	Buttons(Key*, Key*);
	Buttons(Keyboard::Key, Keyboard::Key);
	Buttons(Mouse::Button, Mouse::Button);
	void Update();
	float* Return();
	float Get();
	~Buttons();
};
#endif