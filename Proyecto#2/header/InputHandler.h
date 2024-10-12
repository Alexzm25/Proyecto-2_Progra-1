#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class InputHandler {
private:

public:
	InputHandler(){}
	bool isButtonPressed(Event*);
	bool isMouseInButton(Sprite*, Event*);
};