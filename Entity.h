#pragma once // подключаем защитника 
#include <SFML/Graphics.hpp>// подключение sfml 
using namespace sf;// использование пространства имён sf 
class Entity {// базовый класс игровой сущности 

protected:// модификатор с доступом только для наследников 

	Vector2f position;//позиция игровой сущности 
	Sprite sprite;// спрайт игровой сущности
	Texture texture;// текстура игровой сущности 
	int width;// ширина игровой сущности 
	int height;// высота игровой сущности
	String imagePath;// путь к картинке 
	String name;// название игровой сущности 
	virtual void init();// задаёт начальные параметры игровой сущности 

public://публичный модификатор доступа

	Entity(String imagePath);// конструктор класса 
	virtual void update();
	void setPosition(Vector2f position);// задать позицию игровой сущности 
	void setTextureRect(IntRect rect);//задать текстуру игровой сущности 
	void setWidth(int width);// задать ширину игровой сущности
	void setHeight(int height);//задать высоту игровой сущности 
	void setImagePath(String imagePath);// задать путь к картинке игровой сущности 
	void setName(String name);// задать имя
	Vector2f getPosition();// получить позицию игровой сущности 
	Sprite getSprite();// получить спрайт игровой сущности
	int getWidth();// получить ширину игровой сущности
	int getHeight();// получить высоту игровой сущности 
	String getImagePath();// получить путь к картинке игровой сущности
	String getName();// получить имя 
};