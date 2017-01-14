#include "stdafx.h"
#include "Public.h"
#include "Initialization.h"

int main(int argc, char* argv[])
{
	RenderWindow Windows(VideoMode(Width, Height), Title);

	SetCurrentWindow(&Windows);

	SetGame(CurrentWindow->isOpen());
		
	Initialize();

	do{
		Changed = false;
		CurrentWorld->Awake();
		CurrentWorld->Start();

		while (GameRunning)
		{
			Time::Tick();
			Windows.clear();
			if (Changed) 
				break;
			GlobalUpdate();

			Event Events;

			while (Windows.pollEvent(Events)) {
				if (Events.type == Event::Closed)
					Quit();
			}
			for (unsigned i = 0; i < AllKeys.size(); i++)
			{
				AllKeys.at(i)->Update();
				if (i < AllButtons.size())
					AllButtons.at(i)->Update();
			}
			for (unsigned i = 0; i < AllSprites.size(); i++)
			{
				Windows.draw(AllSprites.at(i)->rect);
			}
			for (unsigned i = 0; i < AllTexts.size(); i++)
			{
				Windows.draw(AllTexts.at(i)->GetText());
			}
			CurrentWorld->Update(Time::dt);
			CurrentWorld->FixedUpdate();
			Windows.setView(CurrentCam->view);
			Windows.display();
		}
	} while (Changed);
	CurrentWindow->close();
	CurrentWindow = nullptr;
	CurrentPhysicsWorld = nullptr;
	CurrentWorld = nullptr;
	Quit();
	return 0;
}