#pragma once //���������� ��������� 

#include <SFML/Graphics.hpp>// ���������� sfml 

#include "Entity.h"// ���������� Entity 

using namespace sf;// ���������� sf 

class Floor : public Entity {// ��������� ����� Floor 

private:// ��������� ����������� �������

	void init();// ��������� ���������

public:// ��������� ����������� �������

	Floor(Vector2f position, String imagePath);// �����������

};