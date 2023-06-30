#include "MoveEntity.h"//подключаем заголовочный файл 

MoveEntity::MoveEntity(Vector2f position, String imagePath) :	Entity(imagePath) {// конструктор класса 
	setPosition(position);//задать позицию
}

void MoveEntity::setSpeed(Vector2f speed) {//задать скорость 
	this->speed = speed;// задаём скорость 

}

Vector2f MoveEntity::getSpeed() {// получить скорость 
	return speed;// получаем скорость 
}