#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../header/InputHandler.h"
#include "../header/Routes.h"

#define MAP_MODE 0
#define MENU_MODE 1
#define INSERT_MODE 2
#define EDIT_MODE 3
#define VIEW_MODE 4

class GUI {
public:
	GUI(){}
	void runWindow();
};