#include "Skeleton.h"
#include<iostream>
void Skeleton::Init()
{
}

void Skeleton::Load()
{
    
    if (!texture.loadFromFile("Asset/Player/texture/sprite_sheet.png"))
    {
        std::cout << "Texture not loaded\n";
    }
    else {
        std::cout << "skeleton Texture loaded\n";
        int xindex = 0;
        int yindex = 2;
        sprite.setTextureRect(sf::IntRect({ xindex, yindex }, { 64, 64 }));
        sprite.setPosition({ 120.0f, 120.0f });
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
