#include "../header/TouristPoint.h"

ostream& operator<<(ostream& os, const TouristPoint& point) {

	os <<point.pointName <<" Coordenada X: " << point.posX << " Coordenada Y: " << point.posY;

	return os;
}