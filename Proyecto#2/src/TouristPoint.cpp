#include "../header/TouristPoint.h"

TouristPoint::TouristPoint(float x, float y, string name, Color color) {
	//: posX(x), posY(y), pointName(name), pointColor(color), r(0), g(0), b(0)
	posX = x;
	posY = y;
	pointName = name;
	pointColor = color;
	r = color.r;
	g = color.g;
	b = color.b;

}

ostream& operator<<(ostream& os, const TouristPoint& point) {

	os <<point.pointName <<" Coordenada X: " << point.posX << " Coordenada Y: " << point.posY;

	return os;
}