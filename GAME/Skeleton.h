#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Skeleton
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;
	
public:
	Skeleton() : sprite(texture) {};
	void Init();
	void Load();	
	void Update();
	void Draw(sf::RenderWindow& window);
};

