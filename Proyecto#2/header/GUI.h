#pragma once
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "../header/InputHandler.h"
#include "../header/RouteList.h"
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
	FileManager filesHandler;
	RouteList listOfRoutes;
	List<List<TouristPoint>>* allRoutesPointer;

	Texture backgroundTxt, startOptionTxt, startOption2Txt, startOption3Txt, closeOptionTxt, closeOption2Txt, mapBackgroundTxt,
		insertButtonTxt, insertButton2Txt, editButtonTxt, editButton2Txt, saveButtonTxt, saveButton2Txt, loadButtonTxt,
		loadButton2Txt, goBackButtonTxt, mapTxt, colorPaletteTxt;

	Sprite backgroundSpr, startOptionSpr, startOption2Spr, startOption3Spr, closeOptionSpr, closeOption2Spr, insertButtonSpr,
		insertButton2Spr, editButtonSpr, editButton2Spr, saveButtonSpr, saveButton2Spr, loadButtonSpr, loadButton2Spr,
		goBackButtonSpr, mapBackgroundSpr, mapSpr, colorPaletteSpr;

	CircleShape wayPoint;
	Color currentColor;
	Font font;
	Text textTitles, textPoints;

	bool isSoundPlayable, isColorSelected;
	int counterPoints, counterRoutes, gameMode, mapMode;

public:
	GUI();
	void setPositionSprite();
	void setTexturesInSprite();
	void loadFiles();
	void colorSelection();
	void drawTouristPoint();
	void menuDisplay();
	void mapDisplay();
	void viewMode();
	void editMode();
	void insertMode();
	void windowDisplay();
	void drawTouristPointNames();
	void drawLinesBetweenRoutes();
	void drawRoutesNamesInScreen();
	void checkIsMouseInButton(Sprite*, Sprite);
};