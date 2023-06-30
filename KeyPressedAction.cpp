#include "KeyPressedAction.h"

KeyPressedAction::KeyPressedAction() {

}

void KeyPressedAction::setPlayer(Player* player) {

	//передаём указатель на игрока

	this->player = player; //задаём поле класса KeyPressedAction

}

void KeyPressedAction::action() {

	if (Keyboard::isKeyPressed(Keyboard::Right)){ 
		//если стрелка вправо нажата 

		player->setSpeed(Vector2f(2, 0));//зададим скорость игрока направо

	player->setTextureRect(IntRect(int(player->currentFrame) * 80, 3 * 120, 80, 120));

	// зададим игроку текстуру из третьей строки, чтобы увидеть что он повернулся направо 

	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) { 
		//если стрелка влево нажата

		player->setSpeed(Vector2f(-2, 0));//зададим скорость игрока налево

		player->setTextureRect(IntRect(int(player->currentFrame) * 80, 2 * 120, 80, 120));

		// зададим игроку текстуру из второй строки, чтобы увидеть что он повернулся налево

	}
	else if (Keyboard::isKeyPressed(Keyboard::Up)) {

		//если стрелка вверх нажата

		player->setSpeed(Vector2f(0, -2));

		player->setTextureRect(IntRect(int(player->currentFrame) * 80, 1 * 120, 80, 120));

		// зададим игроку текстуру из первой строки, чтобы увидеть что он повернулся наверх

	}

	else if (Keyboard::isKeyPressed(Keyboard::Down)) {

		//если стрелка вниз нажата

		player->setSpeed(Vector2f(0, 2));

		//зададим скорость игрока вниз

		player->setTextureRect(IntRect(int(player->currentFrame) * 80, 0, 80, 120));

		// зададим игроку текстуру из нулевой строки, чтобы увидеть что он повернулся вниз

	}

	else {

		player->setSpeed(Vector2f(0, 0));//обнуляем скорость игрока

	}

	player->currentFrame = player->currentFrame + 0.1;

	if (player->currentFrame > 4) {// если currentFrame больше двух то обнулим его

		player->currentFrame = 0;//обнуляем currentFrame

	}
}