#pragma once// ���������� ��������� 

#include <SFML/Graphics.hpp>// ����������� sfml 

#include "Entity.h"

using namespace sf;//������������� ������������ ��� sf

class MoveEntity : public Entity {//����� ������� Entity 

protected:// ����������� � �������� ������ ��� ����������� 

	Vector2f speed;// �������� 

public:// ��������� ����������� �������

	MoveEntity(Vector2f position, String imagePath);// ����������� ������ 
	void setSpeed(Vector2f speed);// ������ ��������
	Vector2f getSpeed();// �������� ��������

};