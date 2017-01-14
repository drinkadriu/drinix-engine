#pragma once
#include <SDL\SDL.h>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>
#include <math.h>
#include <Box2D\Box2D.h>

using namespace std;
using namespace sf;

#ifndef Component_h 
#include "Component.h"
#endif
#ifndef Entity_h
#include "Entity.h"
#endif
#ifndef GameObject_h
#include "GameObject.h"
#endif
#ifndef PhysicalObject_h
#include "PhysicalObject.h"
extern b2World* CurrentPhysicsWorld;
#endif
#ifndef Cam_h
#include "Cam.h"
extern Cam* CurrentCam;
void ChangeCam(Cam*);
#endif
#ifndef Camera_h
#include "Camera.h"
#endif

void SetTScale(float);

extern float Instant;
extern bool VSync;
extern const int MaxFps;
extern bool GameRunning;
extern int Width;
extern int Height;
extern string Title;

void SetGame(bool newG);
void SetResolution(int newWidth, int newHeight);

#ifndef Key_h
#include "Key.h"
extern vector <Key*> AllKeys;
extern Key* LastKey;
#endif

#ifndef Input_h
#include "Input.h"
#endif

#ifndef Time_h
#include "Time.h"
#endif

#ifndef AClip_h
#include "AClip.h"
#endif

#ifndef MClip_h
#include "MClip.h"
#endif

#ifndef EntMap_h
#include "EntMap.h"
#endif

#ifndef TileMap_h
#include "TileMap.h"
#endif

#ifndef Txt_h
#include "Txt.h"
extern vector <Txt*> AllTexts;
#endif	

#ifndef Buttons_h
#include "Buttons.h"
extern vector <Buttons*> AllButtons;
#endif

#ifndef SprtRend_h
#include "SprtRend.h"
extern vector <SprtRend*> AllSprites;
extern unsigned SprtIDCounter;
#endif

#ifndef World_h
#include "World.h"
extern bool Changed;
extern World* CurrentWorld;
extern vector <World*> AllWorlds;
void RunWorld(World*);
void RunWorld(string name);
#endif
#ifndef PhWorld_h
#include "PhWorld.h"
void RunWorld(PhWorld*);
#endif

extern unsigned counter;
extern unsigned NamCounter;
extern unsigned TagCounter;
extern unsigned CamCounter;
extern vector <string> AllNames;
extern vector <string> AllTags;

extern RenderWindow* CurrentWindow;
void SetCurrentWindow(RenderWindow*);

Color GetRandColor(); 
int Randomi(int, int);
float Randomf(float, float);
void KillName(string, float time = 0.f);
void KillTag(string, float time = 0.f);
void Kill(string, string, float time = 0.f);

int Quit();
int GetSprtCounter();
int GetCounter();
int GetNamCounter();
int GetTagCounter();
int GetCamCounter();
string UniqueName(string uN = "lol");
string UniqueTag(string uT = "lol");