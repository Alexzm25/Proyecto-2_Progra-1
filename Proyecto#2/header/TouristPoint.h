#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class TouristPoint {
private:
	float posX;
	float posY;
	string pointName;
	Color pointColor;
public:
	TouristPoint() : posX(0.0), posY(0.0), pointName(" "), pointColor() {}
	TouristPoint(float x, float y,  string name, int r, int g, int b):posX(x), posY(y), pointName(name), pointColor(r, g, b, 255) {}
	float getPosX() { return posX; }
	float getPosY() { return posY; }
	string getPointName() { return pointName; }
	void setPointName(string pointName) { this->pointName = pointName; }
	Color getPointColor() { return pointColor; }
	void setPointColor(Color pointColor) { this->pointColor = pointColor; }
};