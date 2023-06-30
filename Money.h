#pragma once// защита от повторного подключения 

#include <SFML/Graphics.hpp>//подключение sfml 

#include "Entity.h"

using namespace sf;//использование пространства имён sf 

class Money : public Entity {// наследуем класс Money от Entity  {//класс монетки 
private://приватный блок 

	void init();//начальные значения монетки 

public://публичный блок 

	Money(Vector2f position, String imagePath);//конструктор класса 

};