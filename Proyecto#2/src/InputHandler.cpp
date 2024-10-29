#include "../header/InputHandler.h"

bool InputHandler::isButtonPressed(Event* event) {
	
	return (event->type == Event::MouseButtonPressed && event->mouseButton.button == Mouse::Left);
	
}
bool InputHandler::isMouseInButton(Event* event, Sprite* button) {

	return (button->getGlobalBounds().contains(static_cast<float>(event->mouseMove.x), static_cast<float>(event->mouseMove.y)));
}
bool InputHandler::isButtonPressedInSprite(Event* event, Sprite* sprite) {
	if (isButtonPressed(event)) {
		return (sprite->getGlobalBounds().contains(static_cast<float>(event->mouseButton.x), static_cast<float>(event->mouseButton.y)));
	}
}