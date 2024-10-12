#include "../header/InputHandler.h"

bool InputHandler::isButtonPressed(Event* event) {
	if (event->type == Event::MouseButtonPressed && event->mouseButton.button == Mouse::Left) {
		return true;
	}
	else return false;
}
bool InputHandler::isMouseInButton(Sprite* button, Event* event) {
	if (button->getGlobalBounds().contains(static_cast<float>(event->mouseMove.x), static_cast<float>(event->mouseMove.y))) {
		return true;
	}
	else return false;
}