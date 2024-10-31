#include "../header/GUI.h"

GUI::GUI() {

	window = new RenderWindow(VideoMode(1280, 720), "UNOVA ROUTES", Style::Titlebar | Style::Close);
	window->setFramerateLimit(30);

	buttonBuffer.loadFromFile("../assets/audio/audio_soundEffect.ogg");

	buttonSound.setBuffer(buttonBuffer);

	backgroundMusic.openFromFile("../assets/audio/audio_backgroundMusic.ogg");

	gameMode = MENU_MODE;

	mapMode = VIEW_MODE;
	isSoundPlayable = true;
	counter = 0;

	backgroundTxt.loadFromFile("../assets/images/img_unovaRoutes.png");
	startOptionTxt.loadFromFile("../assets/images/img_start1.png");
	startOption2Txt.loadFromFile("../assets/images/img_start2.png");
	startOption3Txt.loadFromFile("../assets/images/img_start3.png");
	closeOptionTxt.loadFromFile("../assets/images/img_close1.png");
	closeOption2Txt.loadFromFile("../assets/images/img_close3.png");

	insertButtonTxt.loadFromFile("../assets/images/img_insertButton.png");
	insertButton2Txt.loadFromFile("../assets/images/img_insertButton2.png");
	editButtonTxt.loadFromFile("../assets/images/img_editButton.png");
	editButton2Txt.loadFromFile("../assets/images/img_editButton2.png");
	saveButtonTxt.loadFromFile("../assets/images/img_saveButton.png");
	saveButton2Txt.loadFromFile("../assets/images/img_saveButton2.png");
	goBackButtonTxt.loadFromFile("../assets/images/img_arrow.png");
	mapBackgroundTxt.loadFromFile("../assets/images/img_mapBackground.png");
	mapTxt.loadFromFile("../assets/images/img_unovaMap.jpg");
	colorPaletteTxt.loadFromFile("../assets/images/img_colorPalette.png");

	backgroundSpr.setTexture(backgroundTxt);
	startOptionSpr.setTexture(startOptionTxt);
	startOption2Spr.setTexture(startOption2Txt);
	startOption3Spr.setTexture(startOption3Txt);
	closeOptionSpr.setTexture(closeOptionTxt);
	closeOption2Spr.setTexture(closeOption2Txt);

	insertButtonSpr.setTexture(insertButtonTxt);
	insertButton2Spr.setTexture(insertButton2Txt);
	editButtonSpr.setTexture(editButtonTxt);
	editButton2Spr.setTexture(editButton2Txt);
	saveButtonSpr.setTexture(saveButtonTxt);
	saveButton2Spr.setTexture(saveButton2Txt);
	goBackButtonSpr.setTexture(goBackButtonTxt);
	mapBackgroundSpr.setTexture(mapBackgroundTxt);
	mapSpr.setTexture(mapTxt);
	colorPaletteSpr.setTexture(colorPaletteTxt);

	startOptionSpr.setPosition(400, 330);
	startOption2Spr.setPosition(400, 330);
	startOption3Spr.setPosition(403, 330);

	closeOptionSpr.setPosition(400, 520);
	closeOption2Spr.setPosition(400, 520);

	insertButtonSpr.setPosition(160, 580);
	insertButton2Spr.setPosition(160, 580);

	editButtonSpr.setPosition(535, 580);
	editButton2Spr.setPosition(535, 580);

	saveButtonSpr.setPosition(1030, 425);
	saveButton2Spr.setPosition(1030, 425);

	goBackButtonSpr.setPosition(1, 670);

	colorPaletteSpr.setPosition(984, 580);

}

void GUI::windowDisplay() {

	backgroundMusic.setLoop(true);
	backgroundMusic.setVolume(7);
	backgroundMusic.play();
	
	while (window->isOpen()) {
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed)
				window->close();
		}

		if (gameMode == MENU_MODE) {
			menuDisplay();
		}
		else {
			mapDisplay();
		}

		window->display();
	}
}

void GUI::menuDisplay() {

	if (!input.isMouseInButton(&event, &startOptionSpr) && !input.isMouseInButton(&event, &closeOptionSpr)) {
		isSoundPlayable = true;
	}

	window->draw(backgroundSpr);
	window->draw(startOptionSpr);
	window->draw(closeOptionSpr);

	if (input.isMouseInButton(&event, &startOptionSpr)) {
		if (isSoundPlayable) buttonSound.play();
		sleep(milliseconds(100));
		window->draw(startOption3Spr);
		isSoundPlayable = false;
	}

	if (input.isMouseInButton(&event, &closeOptionSpr)) {
		if (isSoundPlayable) buttonSound.play();
		sleep(milliseconds(100));
		window->draw(closeOption2Spr);
		isSoundPlayable = false;

	}

	if (input.isButtonPressedInSprite(&event, &startOption3Spr)) {
		gameMode = MAP_MODE;
	}
	if (input.isButtonPressedInSprite(&event, &closeOption2Spr)) {
		window->close();
	}
}

void GUI::mapDisplay() {

	window->draw(mapBackgroundSpr);
	window->draw(mapSpr);
	window->draw(colorPaletteSpr);
	window->draw(goBackButtonSpr);

	window->draw(saveButtonSpr);

	if (mapMode == INSERT_MODE) {

		if (input.isButtonPressedInSprite(&event, &mapSpr)) {
			listOfRoutes.addPointToRoute(&event);
			counter++;
		}
		if (input.isMouseInButton(&event, &saveButtonSpr)) {
			window->draw(saveButton2Spr);
		}
		if (input.isButtonPressedInSprite(&event, &saveButtonSpr) && counter >= 2) { //si el counter == a 2 quiere decir que hay 2 puntos minimo
			counter = 0;
			mapMode = VIEW_MODE;
			//programar funcion para guardar los puntos en un archivo.txt
		}
	}
	else if (mapMode == EDIT_MODE) {
		//programarlo luego
	}
	else {

		window->draw(insertButtonSpr);
		window->draw(editButtonSpr);

		if (input.isButtonPressedInSprite(&event, &goBackButtonSpr)) gameMode = 1;

		if (input.isMouseInButton(&event, &insertButtonSpr)) {
			window->draw(insertButton2Spr);
		}
		if (input.isButtonPressedInSprite(&event, &insertButtonSpr)) {
			mapMode = INSERT_MODE;
			listOfRoutes.addRoute();
		}
		if (input.isMouseInButton(&event, &editButtonSpr)) {
			window->draw(editButton2Spr);
		}
		if (input.isButtonPressedInSprite(&event, &editButton2Spr)) {
			mapMode = EDIT_MODE;
		}
		if (input.isButtonPressed(&event)) {
			//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
			//posX = event.mouseButton.x;
			//posY = event.mouseButton.y;

			//cout << "X: " << posX << "\n";
			//cout << "Y: " << posY << "\n";
			//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
		}
	}
}

