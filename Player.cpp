#include "Player.h"

#include "Map.h"


Player::Player(Vector2f position, String imagePath) : MoveEntity(position, imagePath){

	init();

	setPosition(position);// задать позицию 

	setName("player");// задаём имя

}
void Player::init() {

	width = 80;// задать ширину 

	height = 120;// задать высоту 

	setSpeed(Vector2f(0, 0));// задать скорость 

	setTextureRect(IntRect(0, 0, 80, 120)); //первый спрайт из набора

}



void Player::update() {
	sprite.move(speed.x, speed.y);
	position = sprite.getPosition();
	dontMoveBehindMap();// не давать игроку зайти за пределы карты
}
void Player::dontMoveBehindMap() {// ограничить движение игрока за пределами карты

	if (position.x > WINDOW_WIDTH - width) {// если вышел за пределы справа

		position.x = WINDOW_WIDTH - width;// задать позицию так чтобы не вышел за экран.

		setPosition(Vector2f(position.x, position.y));// фиксируем изменения.

	}
	if (position.x < 0) {// если позиция игрока по x меньше 0

		position.x = 0;// задать позицию по x=0

		setPosition(Vector2f(position.x, position.y));//зафиксировать изменения

	}

	if (position.y < 0) {// если позиция по y меньше 0

		position.y = 0;// задать позицию по y = 0

		setPosition(Vector2f(position.x, position.y));// зафиксировать изменения

	}

	if (position.y > WINDOW_HEIGHT - height) {// если вышел за пределы сверху

		position.y = WINDOW_HEIGHT - height;// задать позицию так чтобы остановился и не выходил за границы

		setPosition(Vector2f(position.x, position.y));// зафиксировать изменения

	}
}

int Player::getCoins() {

	return coins;

}

void Player::setCoins(int coins) {
	this->coins = coins;

}

void Player::setState(String state) {
	this->state = state;

}
String Player::getState() {

	return state;

}