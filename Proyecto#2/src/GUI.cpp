#include "../header/GUI.h"

void GUI::runWindow() {

	RenderWindow window(VideoMode(1280, 720), "UNOVA ROUTES", Style::Titlebar | Style::Close);
	window.setFramerateLimit(30);

	InputHandler input;

	SoundBuffer buttonBuffer;

	buttonBuffer.loadFromFile("../assets/audio/audio_soundEffect.ogg");

	Sound buttonSound(buttonBuffer);

	Texture backgroundTxt;
	Texture startOptionTxt;
	Texture startOption2Txt;
	Texture startOption3Txt;
	Texture closeOptionTxt;
	Texture closeOption2Txt;
	Texture mapTxt;

	backgroundTxt.loadFromFile("../assets/images/img_unovaRoutes.png");
	startOptionTxt.loadFromFile("../assets/images/img_start1.png");
	startOption2Txt.loadFromFile("../assets/images/img_start2.png");
	startOption3Txt.loadFromFile("../assets/images/img_start3.png");
	closeOptionTxt.loadFromFile("../assets/images/img_close1.png");
	closeOption2Txt.loadFromFile("../assets/images/img_close3.png");
	mapTxt.loadFromFile("../assets/images/img_unovaMap.jpg");

	Sprite backgroundSpr(backgroundTxt);
	Sprite startOptionSpr(startOptionTxt);
	Sprite startOption2Spr(startOption2Txt);
	Sprite startOption3Spr(startOption3Txt);
	Sprite closeOptionSpr(closeOptionTxt);
	Sprite closeOption2Spr(closeOption2Txt);
	Sprite mapSpr(mapTxt);

	startOptionSpr.setPosition(400, 330);
	startOption2Spr.setPosition(400, 330);
	startOption3Spr.setPosition(403, 330);

	closeOptionSpr.setPosition(400, 520);
	closeOption2Spr.setPosition(400, 520);
	int posX, posY;
	bool isSoundPlayable = true;
	int gameMode = 1;

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		
		if (gameMode == MENU_MODE) {
			if (!input.isMouseOverButton(&startOptionSpr, &event) && !input.isMouseOverButton(&closeOptionSpr, &event)){
				isSoundPlayable = true;
			}
			
			window.draw(backgroundSpr);
			window.draw(startOptionSpr);
			window.draw(closeOptionSpr);

			if (input.isMouseOverButton(&startOptionSpr, &event)) {
				if (isSoundPlayable) buttonSound.play();
				sleep(milliseconds(100));
				window.draw(startOption3Spr);
				isSoundPlayable = false;
			}

			if (input.isMouseOverButton(&closeOptionSpr, &event)) {
				if (isSoundPlayable) buttonSound.play();
				sleep(milliseconds(100));
				window.draw(closeOption2Spr);
				isSoundPlayable = false;

			}

			if (input.isButtonPressed(&event)) {

				//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
				posX = event.mouseButton.x;
				posY = event.mouseButton.y;

				cout << "X: " << posX << "\n";
				cout << "Y: " << posY << "\n";
				//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
				//startOption3Spr
				if (input.isButtonPressedInSprite(&event, &startOption3Spr)) {
					gameMode = 0;
				}
				if (input.isButtonPressedInSprite(&event, &closeOptionSpr)) {
					window.close();
				}
			}
		}

		else {
			window.draw(mapSpr);
		}
		window.display();
	}
}