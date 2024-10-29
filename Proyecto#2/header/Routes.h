#pragma once
#include <string>
#include "../header/List.h"
#include "../header/TouristPoint.h"


class Routes {
private:
	List<List<TouristPoint>> routesList;
	List<TouristPoint>* route;
public:
	Routes();
	void addRoute();
	void addPointToRoute(Event*);
};