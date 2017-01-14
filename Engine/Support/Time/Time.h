#pragma once
#include "Public.h"
#ifndef Time_h
#define Time_h
	
class Timer
{
public:
	float ThisTimer;
	float StopedTimer;
	Timer() {};
	~Timer() {};
};

namespace Time
{
	extern bool once;
	extern float dt;
	extern float basedt;
	extern float countdt;
	extern float Rawdt;
	extern float Smoothdt;
	extern float TimeScale;
	extern float OverAllScale;
	extern float Framerate;
	extern int Frame;
	extern float Timers;

	extern float Now;
	extern float Last;
	extern float Lastdt;
	extern float LastLastdt;
	extern float AllRawTimer;
	extern float AllTimer;

	void Update();
	void Tick();
	void SetTScale(float newt);
	void Every(float seconds, void(*Func));
}
#endif