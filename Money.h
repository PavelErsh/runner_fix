#pragma once// ������ �� ���������� ����������� 

#include <SFML/Graphics.hpp>//����������� sfml 

#include "Entity.h"

using namespace sf;//������������� ������������ ��� sf 

class Money : public Entity {// ��������� ����� Money �� Entity  {//����� ������� 
private://��������� ���� 

	void init();//��������� �������� ������� 

public://��������� ���� 

	Money(Vector2f position, String imagePath);//����������� ������ 

};