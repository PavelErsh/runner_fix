#pragma once// подключаем защитника 

#include <SFML/Graphics.hpp>// подключение sfml 

#include "Entity.h"

using namespace sf;//использование пространства имён sf

class MoveEntity : public Entity {//класс потомок Entity 

protected:// модификатор с доступом только для наследников 

	Vector2f speed;// скорость 

public:// публичный модификатор доступа

	MoveEntity(Vector2f position, String imagePath);// конструктор класса 
	void setSpeed(Vector2f speed);// задать скорость
	Vector2f getSpeed();// получить скорость

};