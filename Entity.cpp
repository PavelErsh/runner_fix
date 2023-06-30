#include "Entity.h"// подключение заголовочного файла сущности

Entity::Entity(String imagePath) {

	setImagePath(imagePath);

	init();

}

void Entity::init() {// начальные параметры

	Image image;//создаем объект изображения

	image.loadFromFile(imagePath);//загружаем картинку

	texture.loadFromImage(image);//загружаем текстуру из изображения

	sprite.setTexture(texture);//задаём спрайту текстуру

}

void Entity::setPosition(Vector2f position) {// задать позицию 

	this->position = position;// задаём позицию игровой сущности

	sprite.setPosition(position.x, position.y);//задать позицию спрайту

}

void Entity::setTextureRect(IntRect rect) {//задать текстуру 

	sprite.setTextureRect(rect);//задаём спрайту текстуру

}

void Entity::setWidth(int width) {//задать ширину 

	this->width = width;//задаём ширину игровой сущности

}

void Entity::setHeight(int height) {// задать высоту 

	this->height = height;//задаём высоту игровой сущности

}

void Entity::setImagePath(String imagePath) {// задать путь к картинке 

	this->imagePath = imagePath;// задать путь к картинке игровой сущности

}

void Entity::setName(String name) {// задать имя 
	this->name = name;//задаём имя
}

Vector2f Entity::getPosition() {// получить позицию 

	return sprite.getPosition();// получаем позицию

}

Sprite Entity::getSprite() {// получить спрайт 

	return sprite;// получаем спрайт

}

int Entity::getWidth() {// получить ширину 

	return width;// получаем ширину

}

int Entity::getHeight() {// получить высоту 

	return height;// получаем высоту

}

String Entity::getImagePath() {// получить путь к картинке 

	return imagePath;// получаем путь к картинке

}

String Entity::getName() {// получить имя 
	return name;// получаем имя
}

void Entity::update() {

}