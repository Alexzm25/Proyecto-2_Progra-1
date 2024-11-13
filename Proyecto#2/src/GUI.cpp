#include "../header/GUI.h"

GUI::GUI() {

	window = new RenderWindow(VideoMode(1280, 720), "UNOVA ROUTES", Style::Titlebar | Style::Close);
	window->setFramerateLimit(30);

	wayPoint.setRadius(10);
	wayPoint.setFillColor(currentColor);
	
	buttonSound.setBuffer(buttonBuffer);	

	isColorSelected = false;

	gameMode = MENU_MODE;

	mapMode = VIEW_MODE;
	isSoundPlayable = true;
	counterPoints = 0;
	counterRoutes = 0;
	currentColor = Color::Blue;

	loadFiles();
	setTexturesInSprite();
	setPositionSprite();
	
	textTitles.setFont(font);
	textPoints.setFont(font);
	textTitles.setFillColor(Color::White);
}

void GUI::setPositionSprite()
{
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
	loadButtonSpr.setPosition(1030, 274);
	loadButton2Spr.setPosition(1030, 274);
}

void GUI::setTexturesInSprite()
{

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
	loadButtonSpr.setTexture(loadButtonTxt);
	loadButton2Spr.setTexture(loadButton2Txt);
}

void GUI::loadFiles()
{
	backgroundMusic.openFromFile("../assets/audio/audio_backgroundMusic.ogg");
	backgroundTxt.loadFromFile("../assets/images/img_unovaRoutes.png");
	startOptionTxt.loadFromFile("../assets/images/img_start1.png");
	startOption3Txt.loadFromFile("../assets/images/img_start3.png");
	closeOptionTxt.loadFromFile("../assets/images/img_close1.png");
	closeOption2Txt.loadFromFile("../assets/images/img_close3.png");
	buttonBuffer.loadFromFile("../assets/audio/audio_soundEffect.ogg");
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
	loadButtonTxt.loadFromFile("../assets/images/img_loadButton1.png");
	loadButton2Txt.loadFromFile("../assets/images/img_loadButton2.png");
	font.loadFromFile("../assets/font/Roboto-Medium.ttf");
}

void GUI::checkIsMouseInButton(Sprite* button, Sprite button2) {

	if (input.isMouseInButton(&event, button)) {
		if (isSoundPlayable) buttonSound.play();
		sleep(milliseconds(100));
		window->draw(button2);
		isSoundPlayable = false;
	}
}

void GUI::drawTouristPoint() {
	allRoutesPointer = listOfRoutes.getRoutesList();

	if (allRoutesPointer != nullptr) {
		Node<List<TouristPoint>>* currentRouteNode = allRoutesPointer->getNode();
		
		while (currentRouteNode != nullptr) {
			
			Node<TouristPoint>* auxPoint = currentRouteNode->getData()->getNode();
			
			while (auxPoint != nullptr) {
				wayPoint.setPosition(auxPoint->getData()->getPosX() - wayPoint.getRadius(), auxPoint->getData()->getPosY() - wayPoint.getRadius());
				wayPoint.setFillColor(auxPoint->getData()->getPointColor());
				window->draw(wayPoint);
				auxPoint = auxPoint->getNext();
			}
			currentRouteNode = currentRouteNode->getNext();
		}
	}
}

void GUI::windowDisplay() {

	backgroundMusic.setLoop(true);
	backgroundMusic.setVolume(10);
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

	checkIsMouseInButton(&startOptionSpr, startOption3Spr);
	checkIsMouseInButton(&closeOptionSpr, closeOption2Spr);

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

	drawLinesBetweenRoutes();
	drawTouristPoint();
	drawRoutesNamesInScreen();
	drawTouristPointNames();

	if (mapMode == INSERT_MODE) {
		insertMode();
	}
	else if (mapMode == EDIT_MODE) {
		editMode();
	}
	else {
		viewMode();
	}
}

void GUI::viewMode()
{
	window->draw(loadButtonSpr);
	window->draw(insertButtonSpr);
	window->draw(editButtonSpr);

	if (!input.isMouseInButton(&event, &loadButtonSpr) && !input.isMouseInButton(&event, &insertButtonSpr)
		&& !input.isMouseInButton(&event, &editButtonSpr)) {
		isSoundPlayable = true;
	}

	if (input.isButtonPressedInSprite(&event, &goBackButtonSpr)) gameMode = 1;

	checkIsMouseInButton(&insertButtonSpr, insertButton2Spr);

	if (input.isButtonPressedInSprite(&event, &insertButtonSpr)) {
		mapMode = INSERT_MODE;
		listOfRoutes.addRoute();
		counterRoutes++;
	}

	checkIsMouseInButton(&editButtonSpr, editButton2Spr);

	if (input.isButtonPressedInSprite(&event, &editButton2Spr) && allRoutesPointer != nullptr) mapMode = EDIT_MODE;

	checkIsMouseInButton(&loadButtonSpr, loadButton2Spr);

	if (input.isButtonPressedInSprite(&event, &loadButtonSpr)) {
		allRoutesPointer = listOfRoutes.getRoutesList();
		filesHandler.loadFileToRoutes(allRoutesPointer);
	}
}

void GUI::editMode()
{
	if (!input.isMouseInButton(&event, &saveButtonSpr)) {
		isSoundPlayable = true;
	}

	colorSelection();

	if (isColorSelected) {
		listOfRoutes.changeTouristPointColor(&event, &input, currentColor);
	}
	else listOfRoutes.deleteTouristPointByClick(&event, &input);

	checkIsMouseInButton(&saveButtonSpr, saveButton2Spr);

	if (input.isButtonPressedInSprite(&event, &saveButtonSpr)) {
		allRoutesPointer = listOfRoutes.getRoutesList();
		filesHandler.saveRoutes(allRoutesPointer);
		mapMode = VIEW_MODE;
	}
	if (input.isButtonPressedInSprite(&event, &goBackButtonSpr)) mapMode = VIEW_MODE;
}

void GUI::insertMode()
{
	if (!input.isMouseInButton(&event, &saveButtonSpr)) {
		isSoundPlayable = true;
	}

	colorSelection();

	if (input.isButtonPressedInSprite(&event, &mapSpr) && isColorSelected == true) {
		listOfRoutes.addPointToRoute(&event, currentColor);
		drawTouristPoint();
		counterPoints++;
		isColorSelected = false;
	}
	if (counterPoints >= 2) {  //si el counter == a 2 quiere decir que hay 2 puntos minimo y ya es valido guardar una ruta

		checkIsMouseInButton(&saveButtonSpr, saveButton2Spr); 

		if (input.isButtonPressedInSprite(&event, &saveButtonSpr)) {
			counterPoints = 0;
			filesHandler.saveRoutes(allRoutesPointer);
			mapMode = VIEW_MODE;
		}
	}
}

void GUI::colorSelection() {
	if (input.isButtonPressedInSprite(&event, &colorPaletteSpr)) {
		int posX = event.mouseButton.x;

		if (posX < 1037) currentColor = Color::Red;
		else if (posX < 1089) currentColor = Color::Yellow;
		else if (posX < 1143) currentColor = Color::Green;
		else if (posX < 1196) currentColor = Color::Cyan;
		else if (posX < 1249) currentColor = Color::Magenta;

		isColorSelected = true;
	}
}

void GUI::drawRoutesNamesInScreen() {
	int posY = 29;
	
	textTitles.setCharacterSize(20);
	textTitles.setPosition(988, posY);
	
	Node<List<TouristPoint>>* currentRouteNode = allRoutesPointer->getNode();

	while (currentRouteNode != nullptr && counterRoutes <= 4) {

		textTitles.setString(currentRouteNode->getData()->getListName());
		textTitles.setPosition(988, posY);

		currentRouteNode = currentRouteNode->getNext();
		posY += 26;
		window->draw(textTitles);
	}
}
void GUI::drawTouristPointNames() {

	textPoints.setCharacterSize(14);
	textPoints.setFillColor(Color::White);
	Node<List<TouristPoint>>* currentRouteNode = allRoutesPointer->getNode();

	while (currentRouteNode != nullptr) {

		Node<TouristPoint>* currentPointNode = currentRouteNode->getData()->getNode();

		while (currentPointNode != nullptr) {
			textPoints.setString(currentPointNode->getData()->getPointName());
			float x = currentPointNode->getData()->getPosX() + 14;
			float y = currentPointNode->getData()->getPosY() - 24;
			textPoints.setPosition(x, y);
			window->draw(textPoints);

			currentPointNode = currentPointNode->getNext();
		}

		currentRouteNode = currentRouteNode->getNext();
		
	}
}
void GUI::drawLinesBetweenRoutes() {
	if (allRoutesPointer == nullptr || allRoutesPointer->getNode() == nullptr) return;

	Node<List<TouristPoint>>* currentRouteNode = allRoutesPointer->getNode();

	while (currentRouteNode != nullptr) {  
		Node<TouristPoint>* pointList = currentRouteNode->getData()->getNode();
		
		if (pointList != nullptr && pointList->getNext() != nullptr) {
			VertexArray lines(Quads);
			Color lineColor = pointList->getData()->getPointColor();
			Node<TouristPoint>* p0 = nullptr;
			Node<TouristPoint>* p1 = pointList;
			Node<TouristPoint>* p2 = pointList->getNext();
			Node<TouristPoint>* p3 = p2->getNext();

			FloatRect mapSpriteBounds = mapSpr.getGlobalBounds();

			// Bucle para iterar sobre los puntos y dibujar la curva entre ellos
			while (p2 != nullptr) {
				for (float t = 0; t <= 1; t += 0.002f) {
					float t2 = t * t;
					float t3 = t2 * t;

					// Calcular las funciones de interpolación de Hermite
					float h1 = 2 * t3 - 3 * t2 + 1;
					float h2 = -2 * t3 + 3 * t2;
					float h3 = t3 - 2 * t2 + t;
					float h4 = t3 - t2;

					// Calcular posiciones X e Y usando p0, p1, p2, p3 (si existen)
					float x = h1 * p1->getData()->getPosX() + h2 * p2->getData()->getPosX() +
						h3 * (p2->getData()->getPosX() - (p0 ? p0->getData()->getPosX() : p1->getData()->getPosX())) +
						h4 * (p3 ? p3->getData()->getPosX() - p1->getData()->getPosX() : p2->getData()->getPosX() - p1->getData()->getPosX());

					float y = h1 * p1->getData()->getPosY() + h2 * p2->getData()->getPosY() +
						h3 * (p2->getData()->getPosY() - (p0 ? p0->getData()->getPosY() : p1->getData()->getPosY())) +
						h4 * (p3 ? p3->getData()->getPosY() - p1->getData()->getPosY() : p2->getData()->getPosY() - p1->getData()->getPosY());

					if (mapSpriteBounds.contains(x, y)) {
						lines.append(Vertex(Vector2f(x - 1.2f, y - 1.2f), lineColor));
						lines.append(Vertex(Vector2f(x + 1.2f, y - 1.2f), lineColor));
						lines.append(Vertex(Vector2f(x + 1.2f, y + 1.2f), lineColor));
						lines.append(Vertex(Vector2f(x - 1.2f, y + 1.2f), lineColor));
					}
				}
				p0 = p1;
				p1 = p2;
				p2 = p3;
				p3 = (p3 != nullptr) ? p3->getNext() : nullptr;
			}
			window->draw(lines);
		}
		currentRouteNode = currentRouteNode->getNext();
	}
}