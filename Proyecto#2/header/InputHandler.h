#include <SFML/Graphics.hpp>

using namespace sf;

class InputHandler {
private:

public:
	InputHandler(){}
	bool isButtonPressed(Event*);
	bool isMouseInButton(Event*, Sprite*);
	bool isButtonPressedInSprite(Event*, Sprite*);
};