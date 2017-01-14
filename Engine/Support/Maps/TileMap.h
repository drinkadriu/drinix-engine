#pragma once
#ifndef TileMap_h
#define TileMap_h

class TileMap
{
public:
	vector <int> Tiles;
	vector <EntMap> EntityMap;
	int Width;
	int Height;
	void AddEnt(Entity* newe, int ID) {
		EntityMap.push_back(EntMap(newe, ID));
	}
	void SetTiles(vector <int> newt) {
		Tiles = newt;
		Height = Tiles.size() / Width;
	}
	void Draw() {
		b2Vec2 pos = b2Vec2(0, 0);
		for (int y = 0; y < Width; y++) {
			for (int x = 0; x < Width; x++) {
				for (int i = 0; i < EntityMap.size(); i++) {
					if ((Tiles.at(y * Width) + x) == EntityMap.at(i).ID) {
						// Create Entity at i
						Entity* ent = new Entity();
						ent = EntityMap.at(i).Ent;
						ent->GetComponent<Transfrm>()->Position = b2Vec2(x * Width, y * Height);
					}
				}
			}
		}
	}
	TileMap() {};
	TileMap(int wid) {
		Width = wid;
	}
	~TileMap();
};
#endif