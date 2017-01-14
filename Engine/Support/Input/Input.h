#pragma once
#include "Public.h"
#ifndef Input_h
#define Input_h

namespace Input
{
	bool GetKey(Key);
	bool GetKey(Key*);
	bool GetKeyDown(Key);
	bool GetKeyDown(Key*);
	bool GetKeyUp(Key);
	bool GetKeyUp(Key*);
}
#endif