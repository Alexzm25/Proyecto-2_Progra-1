#include "../header/GUI.h"

void GUI::runWindow() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "UNOVA ROUTES");
	sf::Texture backgroundTxt;
	sf::Texture startOptionTxt;
	sf::Texture startOption2Txt;
	sf::Texture startOption3Txt;
	sf::Texture closeOptionTxt;
	sf::Texture closeOption2Txt;

	backgroundTxt.loadFromFile("../assets/images/img_unovaRoutes.png");
	startOptionTxt.loadFromFile("../assets/images/img_start1.png");
	startOption2Txt.loadFromFile("../assets/images/img_start2.png");
	startOption3Txt.loadFromFile("../assets/images/img_start3.png");
	closeOptionTxt.loadFromFile("../assets/images/img_close1.png");
	closeOption2Txt.loadFromFile("../assets/images/img_close3.png");

	sf::Sprite backgroundSpr(backgroundTxt);
	sf::Sprite startOptionSpr(startOptionTxt);
	sf::Sprite startOption2Spr(startOption2Txt);
	sf::Sprite startOption3Spr(startOption3Txt);
	sf::Sprite closeOptionSpr(closeOptionTxt);
	sf::Sprite closeOption2Spr(closeOption2Txt);

	startOptionSpr.setPosition(400, 330);
	startOption2Spr.setPosition(400, 330);
	startOption3Spr.setPosition(403, 330);

	closeOptionSpr.setPosition(400, 480);
	closeOption2Spr.setPosition(400, 480);
	int posX, posY;

	while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		

		if (event.type==sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

			posX = event.mouseButton.x;
			posY = event.mouseButton.y;
			
			std::cout << "X: " << posX << "\n";
			std::cout << "Y: " << posY << "\n";
		}

		window.clear();
		window.draw(backgroundSpr);
		window.draw(startOptionSpr);
		window.draw(closeOptionSpr);

		if (event.type == sf::Event::MouseMoved) {
			if ((event.mouseMove.x >= 469 && event.mouseMove.y >= 383) && (event.mouseMove.x <= 862 && event.mouseMove.y <= 460)) {
				window.draw(startOption3Spr);
			}
			if ((event.mouseMove.x >= 480 && event.mouseMove.y >= 528) && (event.mouseMove.x <= 858 && event.mouseMove.y <= 605)) {
				window.draw(closeOption2Spr);
			}
		}


		window.display();
	}
}