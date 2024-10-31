#include "../header/RouteList.h"

RouteList::RouteList() {
	route = nullptr;
}

void RouteList::addRoute() {
	route = new List<TouristPoint>;
	routesList.addNode(route);

}

void RouteList::addPointToRoute(Event* event) {
	TouristPoint* newPoint = nullptr;
	string pointName;

	cout << "Digite el nombre del punto: \n";
	getline(cin, pointName);

	float posX = event->mouseButton.x;
	float posY = event->mouseButton.y;

	newPoint = new TouristPoint(posX, posY, pointName, Color::Yellow);

	route->addNode(newPoint);
	route->printNodes();
}