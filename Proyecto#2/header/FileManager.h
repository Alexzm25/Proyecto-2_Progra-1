#pragma once
#include "../header/RouteList.h"
#include <string>
#include <fstream>

using namespace std;

class FileManager {
private:

	ifstream inFile;
	ofstream outFile;
	string fileName;

public:
	FileManager(string fileName) : fileName(fileName){}
	void saveRoutes(List<List<TouristPoint>>* routesList);
	void loadFileToRoutes(List<List<TouristPoint>>* routesList);
};
