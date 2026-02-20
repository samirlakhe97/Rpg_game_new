#pragma once
#include "Skeleton.h"


class Player
{
private:
	sf::Texture texture;
	std::vector<sf::CircleShape> bullets;
	float bulletSpeed = 0.5f;
	
public:
	sf::Sprite sprite;

public:
	Player() : sprite(texture) {}; 
	void Init();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};

