#include "Wall.h"// подключим Wall.h 

void Wall::init() {// начальные параметры 

	width = 60;// ширина

	height = 60;// высота

}

Wall::Wall(Vector2f position, String imagePath) : Entity(imagePath) {

	init();// начальные параметры

	setPosition(position);// задать позицию

	setName("wall");// задать имя

}