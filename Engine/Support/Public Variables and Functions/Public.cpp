#include "stdafx.h"
#include "Public.h"

// SETTINGS:

bool VSync = false;
const int MaxFps = 60;
bool GameRunning;
int Width = 640;
int Height = 384;
string Title = "drinix-engine";

void SetTScale(float newt)
{
	CurrentWorld->SetTScale(newt);
	Time::once = false;
}

void SetGame(bool newG) {
	GameRunning = newG;
}
void SetResolution(int newWidth, int newHeight) {
	Width = newWidth;
	Height = newHeight;
	CurrentWindow->create(VideoMode(Width, Height), Title);
}

float Instant = 0.00001f;
unsigned SprtIDCounter = 0;
unsigned counter = 0;
unsigned NamCounter = 0;
unsigned TagCounter = 0;
unsigned CamCounter = 0;
vector <string> AllNames;
vector <string> AllTags;
bool Changed;
World* CurrentWorld = new World("cW");
b2World* CurrentPhysicsWorld;
vector <World*> AllWorlds;
vector <Key*> AllKeys;
Key* LastKey;
vector <Buttons*> AllButtons;
vector <Txt*> AllTexts;
vector <SprtRend*> AllSprites;
Cam* CurrentCam = new Cam();

void ChangeCam(Cam* newC) {
	CurrentCam = newC;
	CurrentWindow->setView(CurrentCam->view);
}

RenderWindow* CurrentWindow;
void SetCurrentWindow(RenderWindow* newW) {
	CurrentWindow = newW;
}

void RunWorld(PhWorld* newpWrld) {
	cout << "Changed World To: " << newpWrld->Name << endl;
	Changed = true;
	CurrentWorld = newpWrld;
}
void RunWorld(World* newWrld) {
	cout << "Changed World To: " << newWrld->Name << endl;
	Changed = true;
	CurrentWorld = newWrld;
}
void RunWorld(string name) {
	for (unsigned i = 0; i < AllWorlds.size(); i++) {
		cout << "World IT: " << AllWorlds.at(i)->Name << endl;
		if (AllWorlds.at(i)->GetName() == name) {
			Changed = true;
			cout << "Changed World To: " << AllWorlds.at(i)->Name << endl;
			CurrentWorld = AllWorlds.at(i);
			break;
		}
	}
}

Color GetRandColor()
{
	int red = Randomi(0, 255);
	int green = Randomi(0, 255);
	int blue = Randomi(0, 255);
	return Color(red, green, blue, 100);
}

int Randomi(int min, int max)
{
	double x = rand() / static_cast<double>(RAND_MAX + 1);
	int that = min + static_cast<int>(x * (max - min));
	return that;
}

float Randomf(float min, float max)
{
	double x = rand() / static_cast<double>(RAND_MAX + 1);
	float that = min + static_cast<float>(x * (max - min));
	return that;
}

void KillName(string name, float time) {
	CurrentWorld->GetEntityName(name)->Kill(time);
}
void KillTag(string tag, float time) {
	CurrentWorld->GetEntityTag(tag)->Kill(time);
}
void Kill(string name, string tag, float time) {
	CurrentWorld->GetEntity(name, tag)->Kill(time);
}

int GetSprtCounter() {
	return SprtIDCounter++;
}
int GetCounter() {
	return counter++;
}
int GetNamCounter() {
	return NamCounter++;
}
int GetTagCounter() {
	return TagCounter++;
}
int GetCamCounter() {
	return NamCounter++;
}
string UniqueName(string uN) {
	if (uN == "lol")
		return "Entity_" + to_string(GetNamCounter());
	for (unsigned i = 0; i < AllNames.size(); i++) {
		if (AllNames.at(i) == uN) {
			return "Entity_" + to_string(GetNamCounter());
			break;
		}
	}
	AllNames.push_back(uN);
	return uN;
}
string UniqueTag(string uT) {
	if (uT == "lol")
		return "Tag_" + to_string(GetTagCounter());
	for (unsigned i = 0; i < AllTags.size(); i++) {
		if (AllTags.at(i) == uT) {
			return "Tag_" + to_string(GetTagCounter());
			break;
		}
	}
	AllTags.push_back(uT);
	return uT;
}
int Quit() {
	SetGame(false);
	return 0;
}