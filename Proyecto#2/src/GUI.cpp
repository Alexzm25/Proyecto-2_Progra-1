#include "../header/GUI.h"

void GUI::runWindow() {

	RenderWindow window(VideoMode(1280, 720), "UNOVA ROUTES", Style::Titlebar | Style::Close);
	window.setFramerateLimit(30);

	InputHandler input;

	SoundBuffer buttonBuffer;

	buttonBuffer.loadFromFile("../assets/audio/audio_soundEffect.ogg");

	Sound buttonSound(buttonBuffer);

	Music backgroundMusic;

	backgroundMusic.openFromFile("../assets/audio/audio_backgroundMusic.ogg");
	backgroundMusic.setLoop(true);
	backgroundMusic.setVolume(8);
	backgroundMusic.play();

	Texture backgroundTxt;
	Texture mapBackgroundTxt;
	Texture startOptionTxt;
	Texture startOption2Txt;
	Texture startOption3Txt;
	Texture closeOptionTxt;
	Texture closeOption2Txt;
	Texture insertButtonTxt;
	Texture editButtonTxt;
	Texture saveButtonTxt;
	Texture goBackButtonTxt;
	Texture mapTxt;
	Texture colorPaletteTxt;

	backgroundTxt.loadFromFile("../assets/images/img_unovaRoutes.png");
	startOptionTxt.loadFromFile("../assets/images/img_start1.png");
	startOption2Txt.loadFromFile("../assets/images/img_start2.png");
	startOption3Txt.loadFromFile("../assets/images/img_start3.png");
	closeOptionTxt.loadFromFile("../assets/images/img_close1.png");
	closeOption2Txt.loadFromFile("../assets/images/img_close3.png");
	insertButtonTxt.loadFromFile("../assets/images/img_insertButton.png");
	editButtonTxt.loadFromFile("../assets/images/img_editButton.png");
	saveButtonTxt.loadFromFile("../assets/images/img_saveButton.png");
	goBackButtonTxt.loadFromFile("../assets/images/img_arrow.png");
	mapBackgroundTxt.loadFromFile("../assets/images/img_mapBackground.png");
	mapTxt.loadFromFile("../assets/images/img_unovaMap.jpg");
	colorPaletteTxt.loadFromFile("../assets/images/img_colorPalette.png");



	Sprite backgroundSpr(backgroundTxt);
	Sprite startOptionSpr(startOptionTxt);
	Sprite startOption2Spr(startOption2Txt);
	Sprite startOption3Spr(startOption3Txt);
	Sprite closeOptionSpr(closeOptionTxt);
	Sprite closeOption2Spr(closeOption2Txt);
	Sprite insertButtonSpr(insertButtonTxt);
	Sprite editButtonSpr(editButtonTxt);
	Sprite saveButtonSpr(saveButtonTxt);
	Sprite goBackSButtonSpr(goBackButtonTxt);
	Sprite mapBackgroundSpr(mapBackgroundTxt);
	Sprite mapSpr(mapTxt);
	Sprite colorPaletteSpr(colorPaletteTxt);

	startOptionSpr.setPosition(400, 330);
	startOption2Spr.setPosition(400, 330);
	startOption3Spr.setPosition(403, 330);

	closeOptionSpr.setPosition(400, 520);
	closeOption2Spr.setPosition(400, 520);

	insertButtonSpr.setPosition(160, 580);
	editButtonSpr.setPosition(535, 580);
	saveButtonSpr.setPosition(1030, 425);
	goBackSButtonSpr.setPosition(1, 670);

	colorPaletteSpr.setPosition(984, 580);

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
			if (!input.isMouseInButton(&event, &startOptionSpr) && !input.isMouseInButton(&event, &closeOptionSpr)) {
				isSoundPlayable = true;
			}
			

			window.draw(backgroundSpr);
			window.draw(startOptionSpr);
			window.draw(closeOptionSpr);

			

			if (input.isMouseInButton(&event, &startOptionSpr)) {
				if (isSoundPlayable) buttonSound.play();
				sleep(milliseconds(100));
				window.draw(startOption3Spr);
				isSoundPlayable = false;
			}

			if (input.isMouseInButton(&event, &closeOptionSpr)) {
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
				if (input.isButtonPressedInSprite(&event,&startOption3Spr)) {
					gameMode = 0;
				}
				if (input.isButtonPressedInSprite(&event, &closeOption2Spr)) {
					window.close();
				}
			}
		}

		else {
			window.draw(mapBackgroundSpr);
			window.draw(mapSpr);
			window.draw(colorPaletteSpr);
			window.draw(goBackSButtonSpr);
			window.draw(insertButtonSpr);
			window.draw(editButtonSpr);
			window.draw(saveButtonSpr);

			if (input.isButtonPressed(&event)) {

				if (input.isButtonPressedInSprite(&event, &goBackSButtonSpr)) gameMode = 1;


				//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
				posX = event.mouseButton.x;
				posY = event.mouseButton.y;

				cout << "X: " << posX << "\n";
				cout << "Y: " << posY << "\n";
				//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
				
			}
		}
		window.display();
	}
}