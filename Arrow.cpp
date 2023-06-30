#include "Arrow.h"  // подключим заголовочный файл Arrow.h
void Arrow::init() {  // начальные параметры 

	width = 47;  // ширина
	height = 22;  // высота
}

// конструктор

Arrow::Arrow(Vector2f position, String imagePath) : MoveEntity(position, imagePath) {

	init();  // начальные параметры

	setName("arrow");  // задать имя

	setSpeed(Vector2f(-2, 0));  // задать скорость

}

void Arrow::update() {  // обновить 

	sprite.move(speed.x, speed.y);  // подвигать спрайт

	position = sprite.getPosition();  // обновить позицию

}