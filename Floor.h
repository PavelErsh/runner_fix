#pragma once //подключаем защитника 

#include <SFML/Graphics.hpp>// подключаем sfml 

#include "Entity.h"// подключаем Entity 

using namespace sf;// используем sf 

class Floor : public Entity {// объ€вл€ем класс Floor 

private:// приватный модификатор доступа

	void init();// начальные параметры

public:// публичный модификатор доступа

	Floor(Vector2f position, String imagePath);// конструктор

};