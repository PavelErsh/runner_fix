#include "Money.h"// подключение заголовочного файла монетки 

Money::Money(Vector2f position, String imagePath) : Entity(imagePath) {//конструктор класса 

	init();// метод задающий начальные параметры 

	setPosition(position);//метод задающий позицию 

	setName("money");// задаём имя

}

void Money::init() {// начальные параметры монетки. 

	width = 32;// ширина монетки

	height = 32;// высота монетки

}

