#include "stdafx.h"
#include "Public.h"
#include "Key.h"

Key::Key(Mouse::Button newmousekey) {
	this->mousecode = newmousekey;
	IsMouseInput = true;
	AllKeys.push_back(this);
	LastKey = this;
	HasBeenPushed = true;
}

Key::Key(Keyboard::Key newkey){
	this->keycode = newkey;
	IsMouseInput = false;
	AllKeys.push_back(this);
	LastKey = this;
	HasBeenPushed = true;
}
Key::Key() { 
}

void Key::Update()
{
	if (IsMouseInput)
		IsPressed = Mouse::isButtonPressed(mousecode);
	else
		IsPressed = Keyboard::isKeyPressed(keycode);

	// Check if the key was pressed since last frame, aka KeyPressed.
	if (IsPressed && !WasPressed)
		Press = true;
	else
		Press = false;

	// Check if the key was held since last frame, aka KeyHeld.
	if (IsPressed && WasPressed)
		Hold = true;
	else
		Hold = false;
		// Check if the key was released since last frame, aka KeyReleased.
	if (!IsPressed && WasPressed)
		Release = true;
	else
		Release = false;
	WasPressed = IsPressed;
}

bool Key::GetKey() {
	return Hold;
}
bool Key::GetKeyDown() {
	return Press;
}
bool Key::GetKeyUp() {
	return Release;
}

void Key::SetKeyCode(Keyboard::Key newKeyCode)
{
	IsMouseInput = false;
	keycode = newKeyCode;
	if (!HasBeenPushed) {
		AllKeys.push_back(this);
		LastKey = this;
	}
}
void Key::SetMouseCode(Mouse::Button newmcode) {
	IsMouseInput = true;
	mousecode = newmcode;
	if (!HasBeenPushed) {
		AllKeys.push_back(this);
		LastKey = this;
	}
}
Key::~Key() {

}