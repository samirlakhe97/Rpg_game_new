
#include "Player.h"
#include "Math.h"
#include<iostream>

void Player::Init()
{
}

void Player::Load()
{
    
    if (!texture.loadFromFile("Asset/Player/texture/sprite_sheet.png"))
    {
        std::cout << "Texture not loaded\n";
    }
    else {
        std::cout << "Player Texture loaded\n";
        int xindex = 0;
        int yindex = 0;
        sprite.setTextureRect(sf::IntRect({ xindex, yindex }, { 64, 64 }));
        sprite.setPosition({ 1700.0f, 700.0f });
    }
}

void Player::Update(Skeleton& skeleton)
{
    //moving player to right
    sf::Vector2f position = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
        sprite.setPosition(position + sf::Vector2f(1, 0));

    //moving player to left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
        sprite.setPosition(position + sf::Vector2f(-1, 0));

    //moving player to up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
        sprite.setPosition(position + sf::Vector2f(0, -1));

    //moving player to down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
        sprite.setPosition(position + sf::Vector2f(0, 1));


    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        sf::CircleShape bullet(10.0f);
        bullet.setFillColor(sf::Color::Red);
        bullets.push_back(bullet);
        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }
    for (size_t i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection = Math::normalize(skeleton.sprite.getPosition() - bullets[i].getPosition());
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    for (int i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

}
