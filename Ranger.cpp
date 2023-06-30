#include "Ranger.h"  // подключим заголовочный файл Ranger.h
void Ranger::init() {  // начальные параметры
	width = 60;  // ширина
	height = 55;  // высота
}

// задать начальные параметры

Ranger::Ranger(Vector2f position, String imagePath) : Entity(imagePath) {
	init();
	setPosition(position);  // задать позицию
	setName("ranger");  // задать имя 
	arrow = new Arrow(Vector2f(position.x - width, position.y + 20), "images/arrow.png");  // создать стрелу 
	setTextureRect(IntRect(0, 0, width, height));  // задаём текстуру
	sprite.setScale(-1, 1);  // поворачиваем наш набор спрайтов
}

Arrow* Ranger::getArrow() {  // получить указатель на объект стрелы
	return arrow;  // получаем стрелу
}

void Ranger::animation() {  // анимация 
	currentFrame += 0.02;
	setTextureRect(IntRect(int(currentFrame) * width, 0, width, height));
}

void Ranger::shoot() {  // выстрел 
	if (!isShot) {
		if (currentFrame >= 4) {
			arrow->setPosition(Vector2f(position.x - width, position.y + 20));
			setTextureRect(IntRect(int(currentFrame) * width, 0, width, height));
			currentFrame -= 4;
			isShot = true;
		}
		else {

			animation();
		}
	}
	else {
		arrow->update();
	}
}

void Ranger::update() {  // обновление 
	shoot();
}

void Ranger::collision(list<Entity*> entities) {  //столкновение стрелы 
	FloatRect arrowCollider = arrow->getSprite().getGlobalBounds();
	for (auto it = entities.begin(); it != entities.end(); it++) {

		FloatRect otherCollider = (*it)->getSprite().getGlobalBounds();
		if (arrowCollider.intersects(otherCollider) && (*it)->getName() == "wall") {
			isShot = false;
		}
	}
}