#include "Engine.h"// подключаем заголовочный файл


Engine::Engine() {// определяем конcтруктор

	init();

}

void Engine::draw() {

	window.clear(Color(0, 255, 0));// зелёный фон

	window.setView(camera->getView());//задаём игровому окну камеру

	map.draw(window);

	Text text;

	Font font;

	font.loadFromFile("20016.ttf");

	text.setFont(font);

	text.setCharacterSize(24);

	text.setFillColor(sf::Color::White);

	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	if (map.getPlayer()->getState() == "start") {

		text.setString("coins:" + std::to_string(map.getPlayer()->getCoins()));
		text.setPosition(camera->getView().getCenter().x + 300, camera->getView().getCenter().y - 240);

	}

	else if (map.getPlayer()->getState() == "loose") {

		window.clear();

		text.setString("You loose");

		text.setPosition(camera->getView().getCenter().x - 40, 	camera->getView().getCenter().y - 20);

	}

	else {

		window.clear();

		text.setPosition(camera->getView().getCenter().x - 40,	camera->getView().getCenter().y - 20);
		
		text.setString("You win");
	}
	window.draw(text);

	window.display(); // отображаем на окне

}

void Engine::update() {

	pressedAction.action();//вызываем метод action объекта pressedAction.

	map.update();// обновляем карту

	camera->update();// обновляем камеру 

}


void Engine::init() {//функция загрузки компонентов игры

	window.create(sf::VideoMode(1260, 720), "Game");
	window.setFramerateLimit(60);// ограничим fps игры 
	pressedAction.setPlayer(map.getPlayer());
	camera = new Camera(map.getPlayer());// создаём игровую камеру
}

void Engine::loop() {// функция игрового цикла

	while (window.isOpen())// игровой цикл

	{

		Event event;// события которые происходят в игре

		while (window.pollEvent(event))// проверяем события

		{

			if (event.type == Event::Closed) {

				window.close();// закрыть окно

			}

		}
		draw(); // рисуем
		update();// обновляем игру
	}

}
