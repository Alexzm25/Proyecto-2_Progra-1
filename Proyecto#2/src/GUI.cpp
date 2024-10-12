#include "../header/GUI.h"

void GUI::runWindow() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "UNOVA ROUTES");
	
	sf::SoundBuffer buttonBuffer;

	buttonBuffer.loadFromFile("../assets/audio/audio_soundEffect.ogg");

	sf::Sound buttonSound(buttonBuffer);

	sf::Texture backgroundTxt;
	sf::Texture startOptionTxt;
	sf::Texture startOption2Txt;
	sf::Texture startOption3Txt;
	sf::Texture closeOptionTxt;
	sf::Texture closeOption2Txt;
	sf::Texture mapTxt;

	backgroundTxt.loadFromFile("../assets/images/img_unovaRoutes.png");
	startOptionTxt.loadFromFile("../assets/images/img_start1.png");
	startOption2Txt.loadFromFile("../assets/images/img_start2.png");
	startOption3Txt.loadFromFile("../assets/images/img_start3.png");
	closeOptionTxt.loadFromFile("../assets/images/img_close1.png");
	closeOption2Txt.loadFromFile("../assets/images/img_close3.png");
	mapTxt.loadFromFile("../assets/images/img_unovaMap.jpg");

	sf::Sprite backgroundSpr(backgroundTxt);
	sf::Sprite startOptionSpr(startOptionTxt);
	sf::Sprite startOption2Spr(startOption2Txt);
	sf::Sprite startOption3Spr(startOption3Txt);
	sf::Sprite closeOptionSpr(closeOptionTxt);
	sf::Sprite closeOption2Spr(closeOption2Txt);
	sf::Sprite mapSpr(mapTxt);

	startOptionSpr.setPosition(400, 330);
	startOption2Spr.setPosition(400, 330);
	startOption3Spr.setPosition(403, 330);

	closeOptionSpr.setPosition(400, 480);
	closeOption2Spr.setPosition(400, 480);
	int posX, posY;
	bool isMapActive = false;
	while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		
		if (isMapActive == false) {
			window.draw(backgroundSpr);
			window.draw(startOptionSpr);
			window.draw(closeOptionSpr);
		}
		else window.draw(mapSpr);

		
		if (startOptionSpr.getGlobalBounds().contains(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)) && isMapActive == false) {
			window.draw(startOption3Spr);
			//buttonSound.play(); //arreglar bug de que solo uno de los dos sucede, que sucedan los 2 al mismo tiempo
			//sf::sleep(sf::seconds(1));
		//startOptionSpr.setColor(sf::Color(255, 255, 255, 0));
		}
		if (closeOptionSpr.getGlobalBounds().contains(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)) && isMapActive == false) {
			window.draw(closeOption2Spr);
		}
		
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

			//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
			posX = event.mouseButton.x;
			posY = event.mouseButton.y;

			std::cout << "X: " << posX << "\n";
			std::cout << "Y: " << posY << "\n";
			//CODIGO TEMPORAL, SOLO PARA VER COORDENADAS XY
			if (startOption3Spr.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)) && isMapActive == false) {
				isMapActive = true;
			}
			if (closeOption2Spr.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)) && isMapActive == false) {
				window.close();
			}
		}
		window.display();
	}
}