#pragma once// ���������� ��������� 
#include <SFML/Graphics.hpp>// ���������� sfml 
#include "Entity.h"// ���������� Entity 
using namespace sf;// ���������� sf 

class Wall : public Entity {// ��������� ����� Wall �� Entity 

private:// ��������� ����������� 

	void init();// ��������� ��������� 
public:// ��������� ����������� �������

	Wall(Vector2f position, String imagePath);// �����������

};
