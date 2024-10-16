#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class InputHandler {
private:

public:
	InputHandler(){}
	bool isButtonPressedInSprite(Event*, Sprite*);
	bool isButtonPressed(Event*);
	bool isMouseOverButton(Sprite*, Event*);
};