#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class TouristPoint {
private:
	float posX;
	float posY;
	int r, g, b;
	string pointName;
	Color pointColor;
public:
	TouristPoint() : posX(0.0), posY(0.0), pointName(" "), pointColor(), r(0), g(0), b(0) {}
	TouristPoint(float x, float y,  string name, int r, int g, int b):posX(x), posY(y), pointName(name), pointColor(r, g, b, 255), r(r), g(g), b(b) {}
	TouristPoint(float x, float y, string name, Color color);
	float getPosX() { return posX; }
	float getPosY() { return posY; }
	int getR() { return r; }
	int getG() { return g; }
	int getB() { return b; }
	string getPointName() { return pointName; }
	void setPointName(string pointName) { this->pointName = pointName; }
	Color getPointColor() { return pointColor; }
	void setPointColor(Color color);
	void setRGB();
	friend ostream& operator<<(ostream& os, const TouristPoint& point);
};