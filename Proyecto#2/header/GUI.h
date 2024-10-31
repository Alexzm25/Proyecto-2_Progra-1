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
private:
	RenderWindow* window;
	SoundBuffer buttonBuffer;
	Sound buttonSound;
	Music backgroundMusic;
	InputHandler input;
	Event event;
	Routes listOfRoutes;

	Texture backgroundTxt;
	Texture startOptionTxt;
	Texture startOption2Txt;
	Texture startOption3Txt;
	Texture closeOptionTxt;
	Texture closeOption2Txt;

	Texture mapBackgroundTxt;
	Texture insertButtonTxt;
	Texture insertButton2Txt;
	Texture editButtonTxt;
	Texture editButton2Txt;
	Texture saveButtonTxt;
	Texture saveButton2Txt;
	Texture goBackButtonTxt;
	Texture mapTxt;
	Texture colorPaletteTxt;

	Sprite backgroundSpr;
	Sprite startOptionSpr;
	Sprite startOption2Spr;
	Sprite startOption3Spr;
	Sprite closeOptionSpr;
	Sprite closeOption2Spr;

	Sprite insertButtonSpr;
	Sprite insertButton2Spr;
	Sprite editButtonSpr;
	Sprite editButton2Spr;
	Sprite saveButtonSpr;
	Sprite saveButton2Spr;
	Sprite goBackButtonSpr;
	Sprite mapBackgroundSpr;
	Sprite mapSpr;
	Sprite colorPaletteSpr;

	bool isSoundPlayable;
	int counter;
	int gameMode;
	int mapMode;
public:
	GUI();
	void menuDisplay();
	void mapDisplay();
	void windowDisplay();
	void runWindow();
};