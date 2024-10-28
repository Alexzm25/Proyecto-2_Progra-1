#include "../header/Routes.h"

Routes::Routes() {
	route = nullptr;
}

void Routes::addRoute() {
	route = new List<TouristPoint>;
	routesList.addNode(route);
	
}

void Routes::addPointToRoute(Event* event) {
	TouristPoint* newPoint = nullptr;
	string pointName;

	cout << "Digite el nombre del punto: \n";
	cin >> pointName;;

	float posX = event->mouseButton.x;
	float posY = event->mouseButton.y;

	newPoint = new TouristPoint(posX, posY, pointName, Color::Yellow);
	
	route->addNode(newPoint);
	//route->printNodes(); estudiar sobrecarga de operadores
}