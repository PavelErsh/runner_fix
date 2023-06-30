#pragma once// защита от повторного подключения

#include <SFML/Graphics.hpp> // подключение sfml

#include "MoveEntity.h"

using namespace sf; // чтобы не писать sf::

class Player : public MoveEntity { // создаем класс игрока  
								   // унаследуем класс Player от MoveEntity
private:// делаем метод init и его поля приватными 

	int coins = 0;

	String state = "start";

	void init(); // задаются начальные параметры игрока 

	void dontMoveBehindMap();// игрок не сможет проходить за карту 
public:
	float currentFrame = 0;

	Player(Vector2f position, String imagePath); // конструктор

	int getCoins();

	void setCoins(int coins);

	void setState(String state);

	String getState();
	
	void update();
};