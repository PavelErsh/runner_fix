#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

#include "Player.h" 

class KeyPressedAction {

private:

	Player* player;//��������� �� ������ ������ Player 

public:

	KeyPressedAction();
	void setPlayer(Player* player);
	void action();//������� ���������� �� �������� 
};