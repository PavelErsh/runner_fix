#include "Camera.h" 
void Camera::init() {

	view.reset(sf::FloatRect(0, 0, 800, 500));//начальные настройки 
} 

Camera::Camera(Player* player) {

	this->player = player;//задаём игрока

	init();//задаём начальные настройки камеры 

}

void Camera::setCenter() {
	int playerX = player->getPosition().x;//получим координату игрока по оси x.

	int playerY = player->getPosition().y;//получим координату игрока по оси y 

	if (playerX < LEFT_BORDER) {// настраиваем границу слева 

		playerX = LEFT_BORDER;

	}
	if (playerX > RIGHT_BORDER) {// настраиваем границу справа 

		playerX = RIGHT_BORDER;

	}

	if (playerY < UP_BORDER) {// настраиваем границу сверху

		playerY = UP_BORDER;

	}

	if (playerY > DOWN_BORDER) {// настраиваем границу снизу

		playerY = DOWN_BORDER;

	}

	view.setCenter(playerX, playerY);// задаём координату центра камеры
}

void Camera::update() {
	setCenter();
}
View Camera::getView() {
	return view;
}