#pragma once// подключаем защитника 
#include <SFML/Graphics.hpp>// подключаем sfml 
#include "Entity.h"// подключаем Entity 
using namespace sf;// используем sf 

class Wall : public Entity {// наследуем класс Wall от Entity 

private:// приватный модификатор 

	void init();// начальные параметры 
public:// публичный модификатор доступа

	Wall(Vector2f position, String imagePath);// конструктор

};
