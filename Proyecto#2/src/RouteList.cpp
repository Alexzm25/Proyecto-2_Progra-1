#include "../header/RouteList.h"

RouteList::RouteList() {
	route = nullptr;
}

void RouteList::addRoute() {
	route = new List<TouristPoint>;
	string routeName;
	cout << "Digite el nombre de la ruta a continuacion ->\t";
	getline(cin, routeName);
	cout << "\n";

	route->setListName(routeName);
	routesList.addNode(route);
	
}

void RouteList::addPointToRoute(Event* event, Color currentColor) {
	TouristPoint* newPoint = nullptr;
	string pointName;

	cout << "Digite el nombre del punto: \n";
	getline(cin, pointName);

	float posX = event->mouseButton.x;
	float posY = event->mouseButton.y;

	newPoint = new TouristPoint(posX, posY, pointName, currentColor);

	route->addNode(newPoint);
	route->printNodes();
}

void RouteList::changeTouristPointColor(Event* event, InputHandler* input, Color colorToChange) {

	if (input->isButtonPressed(event)) {

		float posX = event->mouseButton.x;
		float posY = event->mouseButton.y;
		float radius = 10;

		Node<List<TouristPoint>>* currentRouteNode = routesList.getNode();

		while (currentRouteNode != nullptr) {

			Node<TouristPoint>* currentPointNode = currentRouteNode->getData()->getNode();

			while (currentPointNode != nullptr) {

				float pointX = currentPointNode->getData()->getPosX();
				float pointY = currentPointNode->getData()->getPosY();

				if (sqrt(pow(pointX - posX, 2) + pow(pointY - posY, 2)) <= radius) {

					currentPointNode->getData()->setPointColor(colorToChange);
				}
				currentPointNode = currentPointNode->getNext();
			}

			currentRouteNode = currentRouteNode->getNext();
		}

	}
}

void RouteList::deleteTouristPointByClick(Event* event, InputHandler* input) {

	if (input->isButtonPressed(event)) {

		float posX = event->mouseButton.x;
		float posY = event->mouseButton.y;
		float radius = 10;

		Node<List<TouristPoint>>* currentRouteNode = routesList.getNode();

		while (currentRouteNode != nullptr) {

			Node<TouristPoint>* currentPointNode = currentRouteNode->getData()->getNode();

			while (currentPointNode != nullptr) {

				float pointX = currentPointNode->getData()->getPosX();
				float pointY = currentPointNode->getData()->getPosY();

				if (sqrt(pow(pointX - posX, 2) + pow(pointY - posY, 2)) <= radius) {

					Node<TouristPoint>* nextNode = currentPointNode->getNext();
					Node<TouristPoint>* previousNode = currentPointNode->getPrevious();

					if (previousNode != nullptr) {
						previousNode->setNext(nextNode);
					}
					else {
						currentRouteNode->getData()->setHead(nextNode);
					}
					if (nextNode != nullptr) {
						nextNode->setPrevious(previousNode);
					}

					delete currentPointNode;
					return;
				}
				currentPointNode = currentPointNode->getNext();
			}

			currentRouteNode = currentRouteNode->getNext();
		}

	}
}