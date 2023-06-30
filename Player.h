#pragma once// ������ �� ���������� �����������

#include <SFML/Graphics.hpp> // ����������� sfml

#include "MoveEntity.h"

using namespace sf; // ����� �� ������ sf::

class Player : public MoveEntity { // ������� ����� ������  
								   // ���������� ����� Player �� MoveEntity
private:// ������ ����� init � ��� ���� ���������� 

	int coins = 0;

	String state = "start";

	void init(); // �������� ��������� ��������� ������ 

	void dontMoveBehindMap();// ����� �� ������ ��������� �� ����� 
public:
	float currentFrame = 0;

	Player(Vector2f position, String imagePath); // �����������

	int getCoins();

	void setCoins(int coins);

	void setState(String state);

	String getState();
	
	void update();
};