#include "../header/TouristPoint.h"

TouristPoint::TouristPoint(float x, float y, string name, Color color) {

	posX = x;
	posY = y;
	pointName = name;
	pointColor = color;
	
	setRGB();
}
void TouristPoint::setRGB() {
	r = pointColor.r;
	g = pointColor.g;
	b = pointColor.b;
}
void TouristPoint::setPointColor(Color pointColor) { 
	this->pointColor = pointColor; 

	setRGB();
}
ostream& operator<<(ostream& os, const TouristPoint& point) {

	os <<point.pointName <<" Coordenada X: " << point.posX << " Coordenada Y: " << point.posY;

	return os;
}