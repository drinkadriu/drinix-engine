#pragma once
#ifndef Key_h
#define Key_h

class Key
{
public:
	bool HasBeenPushed = false;
	bool Hold = false;
	bool Press = false;
	bool Release = false;
	int Counter = 0;
	Mouse::Button mousecode;
	Keyboard::Key keycode;
	bool IsMouseInput;
	Key(Mouse::Button);
	Key(Keyboard::Key);
	Key();
	bool WasPressed = false;
	bool IsPressed;
	void Update();
	bool Key::GetKey();
	bool Key::GetKeyDown();
	bool Key::GetKeyUp();
	void SetKeyCode(Keyboard::Key newKeyCode);
	void SetMouseCode(Mouse::Button newmcode);
	~Key();
};
#endif