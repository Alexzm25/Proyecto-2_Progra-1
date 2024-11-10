#include "../header/GUI.h"

GUI::GUI() {

	window = new RenderWindow(VideoMode(1280, 720), "UNOVA ROUTES", Style::Titlebar | Style::Close);
	window->setFramerateLimit(30);

	wayPoint.setRadius(10);
	wayPoint.setFillColor(Color::Blue);
	
	buttonSound.setBuffer(buttonBuffer);	

	gameMode = MENU_MODE;

	mapMode = VIEW_MODE;
	isSoundPlayable = true;
	counter = 0;

	loadFiles();
	setTexturesInSprite();

	setPositionSprite();

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
}

void GUI::drawTouristPoint() {
	allRoutesPointer = listOfRoutes.getRoutesList();

	if (allRoutesPointer != nullptr) {
		Node<List<TouristPoint>>* currentRouteNode = allRoutesPointer->getNode();
		
		while (currentRouteNode != nullptr) {
			
			Node<TouristPoint>* auxPoint = currentRouteNode->getData()->getNode();
			
			while (auxPoint != nullptr) {
				wayPoint.setPosition(auxPoint->getData()->getPosX() - wayPoint.getRadius(), auxPoint->getData()->getPosY() - wayPoint.getRadius());
				window->draw(wayPoint);
				auxPoint = auxPoint->getNext();
			}

			currentRouteNode = currentRouteNode->getNext();
		}

	}
	
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

	drawRoutes();
	drawTouristPoint();

	if (mapMode == INSERT_MODE) {

		if (input.isButtonPressedInSprite(&event, &mapSpr)) {
			
			listOfRoutes.addPointToRoute(&event);
			drawTouristPoint();
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

VertexArray GUI::generateSpline(const Vector2f* points, int numPoints) {
	VertexArray curve(LineStrip);

	if (numPoints < 2) return curve;

	for (int i = 0; i < numPoints - 1; ++i) {
		Vector2f p0 = points[i];
		Vector2f p1 = points[i + 1];

		// Calcula los vectores de tangente en p0 y p1
		Vector2f m0 = (i == 0) ? MathUtils::calculateTangent(p0, points[i + 1]) :
			MathUtils::calculateTangent(points[i - 1], points[i + 1]);
		Vector2f m1 = (i == numPoints - 2) ? MathUtils::calculateTangent(points[i], p1) :
			MathUtils::calculateTangent(points[i], points[i + 2]);

		// Genera los puntos interpolados para el segmento entre p0 y p1
		for (float t = 0; t < 1.0f; t += 0.05f) {
			Vector2f interpolatedPoint = MathUtils::interpolate(p0, p1, m0, m1, t);
			curve.append(Vertex(interpolatedPoint, Color::Blue));
		}
	}
	return curve;
}

void GUI::drawRoutes() {
	allRoutesPointer = listOfRoutes.getRoutesList();

	Node<List<TouristPoint>>* currentRouteNode = allRoutesPointer->getNode();

	while (currentRouteNode != nullptr) {
		List<TouristPoint>* route = currentRouteNode->getData();

		// Contar manualmente los puntos en route
		int numPoints = 0;
		Node<TouristPoint>* tempNode = route->getNode();
		while (tempNode != nullptr) {
			numPoints++;
			tempNode = tempNode->getNext();
		}

		// Crear el arreglo de puntos
		Vector2f* points = new Vector2f[numPoints];

		// Llenar el arreglo con los puntos de TouristPoint
		int index = 0;
		tempNode = route->getNode();
		while (tempNode != nullptr) {
			points[index++] = Vector2f(tempNode->getData()->getPosX(), tempNode->getData()->getPosY());
			tempNode = tempNode->getNext();
		}

		// Generar la línea de la ruta y dibujarla
		VertexArray spline = generateSpline(points, numPoints);
		window->draw(spline);

		// Liberar la memoria de points
		delete[] points;

		currentRouteNode = currentRouteNode->getNext();
	}
}