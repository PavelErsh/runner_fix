#include "Map.h"

void Map::init() {

	player = new Player(Vector2f(70, 70), "images/player1.png");

	for (int i = 0; i < HEIGHT_MAP; i++) {// цикл по высоте карты

		for (int j = 0; j < WIDTH_MAP; j++)

		{// цикл по ширине карты
			if (TileMap[i][j] == 'm') {// если встретили монетку

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");// создадим пол

				entities.push_back(floor);// добавим пол в список 

				Money* money = new Money(Vector2f(j * 60, i * 60), "images/coin.png");// создадим монетку

				entities.push_back(money);// добавим еЄ в список

			}

			if (TileMap[i][j] == 'g') {// если встретили пол 

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");// создаЄм пол

				entities.push_back(floor);// добавл€ем его в список

			}
			if (TileMap[i][j] == 'k') {// если встретили стену 

				Wall* wall = new Wall(Vector2f(j * 60, i * 60), "images/brick.png");// создаЄм стену

				entities.push_back(wall);//добавл€ем еЄ в список

			}

			if (TileMap[i][j] == 'a') {  // если на карте лучник
				//создаЄм пол

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");

				entities.push_back(floor); // добавл€ем пол
				Ranger* ranger = new Ranger(Vector2f(j * 60 + 60, i * 60), "images/ranger.png");  // создаЄм лучника
				entities.push_back(ranger);  // добавл€ем лучника
				entities.push_back(ranger->getArrow());  //добавл€ем стрелу
			}

		}
	}
}

Map::Map() {

	init();

}

void Map::update() {

	int coinsCounter = 0;

	for (auto it = entities.begin(); it != entities.end(); it++) {

		if ((*it)->getName() == "money") {

			coinsCounter++;

		}

	}

	if (coinsCounter == 0) {

		player->setState("win");

	}

	player->update();

	for (auto it = entities.begin(); it != entities.end(); it++) {
		if ((*it)->getName() == "ranger") {
			(*it)->update();
			/*Ranger* ranger = (Ranger*)(*it);
			ranger->collision(entities);*/
		}
	}

	for (auto it = entities.begin(); it != entities.end();) {
		FloatRect playerCollider = player->getSprite().getGlobalBounds();
		FloatRect otherCollider = (*it)->getSprite().getGlobalBounds();

		if (playerCollider.intersects(otherCollider) && (*it)->getName() == "money") {// если игрок столкнулс€ с монеткой 

			player->setCoins(player->getCoins() + 1);

			entities.erase(it++);//удал€ем монетку			
		}
		else if (playerCollider.intersects(otherCollider) && (*it)->getName() == "wall") {// если игрок столкнулс€ со стеной 

			player->setSpeed(Vector2f(-player->getSpeed().x, -player->getSpeed().y));// отталкиваем игрока

			player->update();// обновл€ем позицию

			it++;

		}
		else if ((*it)->getName() == "ranger") {
			Ranger* ranger = (Ranger*)(*it);

			ranger->collision(entities);

			Arrow* arrow = ranger->getArrow();

			FloatRect otherCollider = arrow->getSprite().getGlobalBounds();

			if (playerCollider.intersects(otherCollider)) {

				player->setState("loose");
			}
			it++;
		}
		else {// если мы ни с кем не столкнулись

			it++;// перейти на следующий объект списка

		}

	}
}

Player* Map::getPlayer() {

	return player;

}

void Map::draw(RenderWindow& window) {

	for (auto it = entities.begin(); it != entities.end(); it++) {// цикл по игровым объектам 
		window.draw((*it)->getSprite());
	}

	window.draw(player->getSprite());

}