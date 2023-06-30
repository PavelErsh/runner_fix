#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

#include "Money.h"//подключаем заголовочный файл монетки 

#include "Wall.h"// подключим Wall.h 

#include "Floor.h"// подключим Floor.h

#include "Ranger.h"

#include<list>// подключим лист

using namespace sf;

using namespace std;// используем пространство имён std 

const int WINDOW_WIDTH = 1260;

const int WINDOW_HEIGHT = 720;

const int WIDTH_MAP = 21;//размер карты ширина

const int HEIGHT_MAP = 12;//размер карты высота 

class Map {
public:

	Map();

	void draw(RenderWindow& window);

	Player* getPlayer();

	void update();

private:
	sf::String TileMap[HEIGHT_MAP] = {
		"kkkkkkkkkkkkkkkkkkkkk",
		"kggggggggmgggakgmkgmk",
		"kgggggggggggggkggkggk",
		"kgggggkkkkkgggkggkggk",
		"kkkkkkkgmgkgggkggkggk",
		"kgggggggggkgggkggkggk",
		"kgggggggggkgggkggkggk",
		"kggkkkkkkkkgggkggkggk",
		"kggggggagggggggggkggk",
		"kggggggmgggggggmggggk",
		"kggggggggggggggggggak",
		"kmgkkkkkkkkkkkkkkkkkk"
	};

	Player* player;

	list<Entity*> entities;// список указателей на класс Entity 

	void init();
};