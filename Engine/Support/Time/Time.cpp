#include "stdafx.h"
#include "Time.h"

namespace Time
{
	bool once = false;
	float dt = 0;
	float basedt = 0;
	float countdt = 0;
	float Rawdt = 0;
	float Smoothdt = 0;
	float TimeScale = 1;
	float OverAllScale = 1;
	float Framerate = 1;
	int Frame = 0;
	float Timers;

	float Now = static_cast<float>(SDL_GetPerformanceCounter());
	float Last = 0;
	float Lastdt = 0;
	float LastLastdt = 0;
	float AllRawTimer = 0;
	float AllTimer = 0;

	void Update()
	{
		Frame++;
		Timers += Rawdt;
		if (Timers >= 1.f) {
			Framerate = static_cast<float>(Frame);
			dt = ((1.f / Framerate)*TimeScale);
			basedt = dt;
			Frame = 0;
			Timers = 0.f;
			once = true;
		}
		else if (!once) {
			dt = countdt;
		}
	}

	void Tick()
	{	
		Last = Now;
		Now = static_cast<float>(SDL_GetPerformanceCounter());
					
		LastLastdt = Lastdt;
		Lastdt = countdt;
		Rawdt = ((Now - Last) * 1000 / SDL_GetPerformanceFrequency())*0.001f;
		countdt = Rawdt*TimeScale;
		AllRawTimer += Rawdt;
		AllTimer += countdt;
		Smoothdt = (countdt + Lastdt + LastLastdt) / 3;
		dt = basedt*TimeScale;
		Update();
	}

	void SetTScale(float newt)
	{
		CurrentWorld->SetTScale(newt);
		once = false;
	}

	void Every(float seconds, void(*Func))
	{

	}
}