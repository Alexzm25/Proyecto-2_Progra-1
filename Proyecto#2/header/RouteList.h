#pragma once
#include <string>
#include "../header/InputHandler.h"
#include "../header/List.h"
#include "../header/TouristPoint.h"


class RouteList {
private:
	List<List<TouristPoint>> routesList;
	List<TouristPoint>* route;
public:
	RouteList();
	void addRoute();
	void addPointToRoute(Event*, Color);
	void deleteTouristPointByClick(Event*, InputHandler*);
	void changeTouristPointColor(Event*, InputHandler* ,Color);
	List<List<TouristPoint>>* getRoutesList() { return &routesList; }
	List<TouristPoint>* getRoute() { return route; }
};