#pragma once// подключение защитника

#include <SFML/Graphics.hpp>

#include "MoveEntity.h"

using namespace sf;

class Arrow : public MoveEntity {  // класс стрелы

private:  // приватный модификатор 

	void init();  // начальные параметры 

public:  // публичный модификатор 

	Arrow(Vector2f position, String imagePath);  // конструктор 

	void update();  // обновление

};