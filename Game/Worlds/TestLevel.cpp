#include "stdafx.h"
#include "TestLevel.h"

namespace TestLevel {
	PhWorld testlevel("testlevel");
	Camera* Cams;
	PhysicalObject* Obj;
	PhysicalObject* Otr;
	PhysicalObject* Osr;
	PhysicalObject* Odr;
	TileMap tmap;

	void Initialize() {
		tmap = TileMap(10);
		Cams = new Camera(b2Vec2(0, 0), b2Vec2(3000, 2000));
		ChangeCam(Cams->GetComponent<Cam>());
		Cams->AddComponent<Txt>(Cams, "Cam brother", "def", 100, Color::Red, 0, 0, -500, -500);
		PhysicalObject* Oti = new PhysicalObject(true, "null", -9999, -9999);
		Obj = new PhysicalObject(false, "images/pic.jpg", 0, -200);
		Obj->SetAll("OBJ", "lol");
		Otr = new PhysicalObject(true, "images/pic.jpg", 200, 0);
		Osr = new PhysicalObject(true, "images/img.jpg", 200, 0);
		Obj->AddComponent<Reight>(Obj);
		tmap.AddEnt(Otr, 3);
		tmap.AddEnt(Otr, 7);
		vector <int> newv{ 
			7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
			7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
			7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
			7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
			7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
			7, 7, 7, 7, 7, 7, 7, 7, 7, 3,
			7, 7, 7, 7, 7, 7, 7, 7, 3, 3,
			7, 7, 7, 7, 7, 7, 7, 3, 3, 3,
			7, 7, 7, 7, 7, 7, 3, 3, 3, 3,
			3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
		tmap.SetTiles(newv);
		tmap.Draw();
	}
}