#include "../header/InputHandler.h"

bool InputHandler::isButtonPressedInSprite(Event* event, Sprite* sprite) {
	if (isButtonPressed(event)) {
		return (sprite->getGlobalBounds().contains(static_cast<float>(event->mouseButton.x), static_cast<float>(event->mouseButton.y)));
	}
}
bool InputHandler::isButtonPressed(Event* event) {

	return (event->type == Event::MouseButtonPressed && event->mouseButton.button == Mouse::Left);
}
bool InputHandler::isMouseOverButton(Sprite* button, Event* event) {
	
	return (button->getGlobalBounds().contains(static_cast<float>(event->mouseMove.x), static_cast<float>(event->mouseMove.y)));
	
}