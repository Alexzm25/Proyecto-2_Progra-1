#pragma once
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../header/InputHandler.h"
#include "../header/RouteList.h"
#include "../header/MathUtils.h"
#include "../header/FileManager.h"

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
	RouteList listOfRoutes;

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

	List<List<TouristPoint>>* allRoutesPointer;
	FileManager filesHandler;

	CircleShape wayPoint;
	Color currentColor;
	RectangleShape boxTitle;
	Font font;
	Text text;

	bool isSoundPlayable, isColorSelected;
	int counterPoints, counterRoutes;
	int gameMode;
	int mapMode;
	
	VertexArray generateSpline(const Vector2f* points, int numPoints);
	
public:
	GUI();
	void setPositionSprite();
	void setTexturesInSprite();
	void loadFiles();
	void colorSelection();
	void drawTouristPoint();
	void menuDisplay();
	void mapDisplay();
	void windowDisplay();
	void drawRoutes();
	void drawLinesBetweenRoutes();
	void drawRoutesNamesInScreen();
};