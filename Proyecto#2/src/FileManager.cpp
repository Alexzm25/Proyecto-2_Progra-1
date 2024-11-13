#include "../header/FileManager.h"

void FileManager::saveRoutes(List<List<TouristPoint>>* routesList) {

	try {
		outFile.open(fileName);

		if (outFile.is_open()) {

			Node<List<TouristPoint>>* routeNode = routesList->getNode();


			outFile << "<Routes>\n";

			while (routeNode != nullptr) {

				List<TouristPoint>* currentRoute = routeNode->getData();
				Node<TouristPoint>* currentPoint = currentRoute->getNode();

				outFile << "<Route>\n";
				outFile << "<RouteName>" << currentRoute->getListName() << "</RouteName>\n";

				while (currentPoint != nullptr) {

					outFile << "<PosX>" << currentPoint->getData()->getPosX() << "</PosX>\n";
					outFile << "<PosY>" << currentPoint->getData()->getPosY() << "</PosY>\n";
					outFile << "<Color>"<< currentPoint->getData()->getR() << ","
						<< currentPoint->getData()->getG() << ","
						<< currentPoint->getData()->getB() << "</Color>\n";
					outFile << "<PointName>" << currentPoint->getData()->getPointName() << "</PointName>\n";

					currentPoint = currentPoint->getNext();
				}

				outFile << "</Route>\n";

				routeNode = routeNode->getNext();
			}

			outFile << "</Routes>";
			outFile.close();
		}
		else throw "Error: no se pudo abrir el archivo " + fileName + " para guardar la lista de rutas!\n";

	}
	catch (const char* error) {
		cerr << error;
	}
}

//void FileManager::loadFileToRoutes(List<List<TouristPoint>>* routesList) {
//
//	try {
//		inFile.open(fileName);
//
//		if (inFile.is_open()) {
//
//			if (inFile.peek() == EOF) {
//				cerr << "Error: el archivo " << fileName << " se encuentra vacio.\n";
//				inFile.close();
//				return;
//			}
//
//			string line, pointName, routeName;
//			float x, y;
//			int r, g, b;
//			List<List<TouristPoint>>* newRoutesList = nullptr;
//			List<TouristPoint>* newRoute = nullptr;
//
//			while (getline(inFile, line)) {
//
//				if (line.find("<Routes>") != string::npos) {
//					newRoutesList = new List<List<TouristPoint>>;
//				}
//
//				else if (line.find("<Route>") != string::npos) {
//					newRoute = new List<TouristPoint>;
//				}
//				else if (line.find("<RouteName>") != string::npos) {
//					size_t start = line.find("<RouteName>") + 11;
//					size_t end = line.find("</RouteName>");
//					routeName = line.substr(start, end - start);
//				}
//
//				else if (line.find("<PosX>") != string::npos) {
//					size_t start = line.find("<PosX>") + 6;
//					size_t end = line.find("</PosX>");
//
//					x = stof(line.substr(start, end - start));
//				}
//
//				else if (line.find("<PosY>") != string::npos) {
//					size_t start = line.find("<PosY>") + 6;
//					size_t end = line.find("</PosY>");
//
//					y = stof(line.substr(start, end - start));
//				}
//
//				else if (line.find("<Color>") != string::npos) {
//					size_t start = line.find("<Color>") + 7;
//					size_t end = line.find("</Color>");
//					string colorLine = line.substr(start, end - start);
//
//					size_t posG = colorLine.find(",");
//					size_t posB = colorLine.find(",", posG + 1);
//
//					r = stoi(colorLine.substr(0, posG));
//					g = stoi(colorLine.substr(posG + 1, posB - posG - 1));
//					b = stoi(colorLine.substr(posB + 1));
//				}
//
//				else if (line.find("<PointName>") != string::npos) {
//					size_t start = line.find("<PointName>") + 11;
//					size_t end = line.find("</PointName>");
//
//					pointName = line.substr(start, end - start);
//				}
//
//				else if (!pointName.empty() && newRoute != nullptr) {
//					TouristPoint* newPoint = new TouristPoint(x, y, pointName, r, g, b);
//					newRoute->setListName(routeName);
//					newRoute->addNode(newPoint);
//					pointName.clear();
//				}
//
//				else if (line.find("</Route>") != string::npos) {
//					if (newRoute != nullptr) {
//						newRoutesList->addNode(newRoute);
//						newRoute = nullptr;
//					}
//				}
//
//				else if (line.find("</Routes>") != string::npos) {
//					if (newRoutesList != nullptr) {
//						*routesList = *newRoutesList;
//						delete newRoutesList;
//					}
//				}
//			}
//
//			inFile.close();
//
//		}
//		else {
//			throw "Error: no se pudo abrir el archivo " + fileName + " para cargar la lista de rutas!\n";
//		}
//	}
//	catch (const char* error) {
//		cerr << error;
//	}
//}

void FileManager::loadFileToRoutes(List<List<TouristPoint>>* routesList) {

	try {
		inFile.open(fileName);

		if (inFile.is_open()) {

			if (inFile.peek() == EOF) {
				cerr << "Error: el archivo " << fileName << " se encuentra vacio.\n";
				inFile.close();
				return;
			}

			string line, pointName, routeName;
			float x, y;
			int r, g, b;
			List<List<TouristPoint>>* newRoutesList = nullptr;
			List<TouristPoint>* newRoute = nullptr;

			while (getline(inFile, line)) {

				if (line.find("<Routes>") != string::npos) {
					newRoutesList = new List<List<TouristPoint>>;
					cout << "Se encontró la etiqueta <Routes>\n";
				}

				else if (line.find("<Route>") != string::npos) {
					newRoute = new List<TouristPoint>;
					cout << "Se encontró una nueva <Route>\n";
				}

				else if (line.find("<RouteName>") != string::npos) {
					size_t start = line.find("<RouteName>") + 11;
					size_t end = line.find("</RouteName>");
					routeName = line.substr(start, end - start);
					cout << "Nombre de la ruta: " << routeName << endl;
				}

				else if (line.find("<PosX>") != string::npos) {
					size_t start = line.find("<PosX>") + 6;
					size_t end = line.find("</PosX>");

					x = stof(line.substr(start, end - start));
					cout << "Posición X: " << x << endl;
				}

				else if (line.find("<PosY>") != string::npos) {
					size_t start = line.find("<PosY>") + 6;
					size_t end = line.find("</PosY>");

					y = stof(line.substr(start, end - start));
					cout << "Posición Y: " << y << endl;
				}

				else if (line.find("<Color>") != string::npos) {
					size_t start = line.find("<Color>") + 7;
					size_t end = line.find("</Color>");
					string colorLine = line.substr(start, end - start);

					size_t posG = colorLine.find(",");
					size_t posB = colorLine.find(",", posG + 1);

					r = stoi(colorLine.substr(0, posG));
					g = stoi(colorLine.substr(posG + 1, posB - posG - 1));
					b = stoi(colorLine.substr(posB + 1));
					cout << "Color RGB: (" << r << ", " << g << ", " << b << ")\n";
				}

				else if (line.find("<PointName>") != string::npos) {
					size_t start = line.find("<PointName>") + 11;
					size_t end = line.find("</PointName>");

					pointName = line.substr(start, end - start);
					cout << "Nombre del punto: " << pointName << endl;
				}

				if (!pointName.empty() && newRoute != nullptr) {
					TouristPoint* newPoint = new TouristPoint(x, y, pointName, r, g, b);
					newRoute->setListName(routeName);
					newRoute->addNode(newPoint);
					cout << "Punto agregado a la ruta '" << routeName << "': " << pointName << " (" << x << ", " << y << "), Color: (" << r << ", " << g << ", " << b << ")\n";
					pointName.clear();
				}

				if (line.find("</Route>") != string::npos) {
					if (newRoute != nullptr) {
						newRoutesList->addNode(newRoute);
						cout << "Ruta agregada a <Routes>: " << routeName << endl;
						newRoute = nullptr;
					}
				}

				if (line.find("</Routes>") != string::npos) {
					if (newRoutesList != nullptr) {
						*routesList = *newRoutesList;
						//delete newRoutesList;
						cout << "Se finalizaron de cargar las rutas.\n";
					}
				}
			}

			inFile.close();

		}
		else {
			throw "Error: no se pudo abrir el archivo " + fileName + " para cargar la lista de rutas!\n";
		}
	}
	catch (const char* error) {
		cerr << error;
	}
}
