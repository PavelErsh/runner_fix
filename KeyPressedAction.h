#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

#include "Player.h" 

class KeyPressedAction {

private:

	Player* player;//указатель на объект класса Player 

public:

	KeyPressedAction();
	void setPlayer(Player* player);
	void action();//функция отвечающая за движение 
};