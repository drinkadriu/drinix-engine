#include "stdafx.h"
#include "Input.h"

namespace Input
{
	bool GetKey(Key key) {
		return key.Hold;
	}
	bool GetKey(Key* key) {
		return key->Hold;
	}
	bool GetKeyDown(Key key) {
		return key.Press;
	}
	bool GetKeyDown(Key* key) {
		return key->Press;
	}
	bool GetKeyUp(Key key) {
		return key.Release;
	}
	bool GetKeyUp(Key* key) {
		return key->Release;
	}
}