#include "Floor.h"// подключим Floor.h 
void Floor::init() {// начальные параметры 
	width = 60;// ширина

	height = 60;// высота

}

Floor::Floor(Vector2f position, String imagePath) : Entity(imagePath) {// конструктор 

	init();// начальные параметры

	setPosition(position);// задать позицию

	setName("floor");// задать имя

}