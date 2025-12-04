#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include<iostream>
#include<math.h>
#include<vector>

sf::Vector2f normalize(sf::Vector2f bullet)
{
    float length = sqrt((bullet.x * bullet.x) + (bullet.y * bullet.y));
    if (length != 0)
        return sf::Vector2f(bullet.x / length, bullet.y / length);
    else
        return bullet;
}

int main()
{       
    //------------------------------- Initialize --------------------------

    sf::ContextSettings setting;
    setting.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({ 1820,980 }), "My window", sf::Style::Default);
    sf::Vector2f bulletDirection;

    //------------------------------- Initialize --------------------------

	//------------------------------- Bullets --------------------------
	std::vector<sf::CircleShape> bullets;
	float bulletSpeed = 0.5f;
    //------------------------------- Bullets --------------------------

     //------------------------------- Load --------------------------
     
     //--------------- skeleton Texture--------------------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite(skeletonTexture);
	skeletonSprite.setPosition({ 50.0f, 100.0f });
    if (!skeletonTexture.loadFromFile("Asset/Player/texture/sprite_sheet.png"))
    {
        std::cout << "Texture not loaded\n";
        return 0;
    }
    else {
        std::cout << "skeleton Texture loaded\n";


        int xindex = 0;
        int yindex = 2;
        skeletonSprite.setTextureRect(sf::IntRect({ xindex, yindex }, { 64, 64 }));
    }
    //--------------- skeleton Texture--------------------------

	//--------------- Player Texture--------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite(playerTexture);
	playerSprite.setPosition({ 1700.0f, 700.0f });
    if (!playerTexture.loadFromFile("Asset/Player/texture/sprite_sheet.png"))
    {
        std::cout << "Texture not loaded\n";
        return 0;
    }
    else {
        std::cout << "Player Texture loaded\n";       
        int xindex = 0;
        int yindex = 0;
        playerSprite.setTextureRect(sf::IntRect({ xindex, yindex }, { 64, 64 }));
    }
    //--------------- Player Texture--------------------------

    //------------------------------- Load --------------------------


   //------------------------------- Update --------------------------

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();

        }

        //moving player to right
        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) 
            playerSprite.setPosition(position + sf::Vector2f(1, 0));   

        //moving player to left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) 
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));      

        //moving player to up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) 
            playerSprite.setPosition(position + sf::Vector2f(0, -1));       

        //moving player to down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) 
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::CircleShape bullet(10.0f);
            bullet.setFillColor(sf::Color::Red);
            bullets.push_back(bullet);
            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
            bulletDirection = normalize(skeletonSprite.getPosition() - bullets[i].getPosition());
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
        //------------------------------- Update --------------------------


        //------------------------------- Draw --------------------------

        window.clear(sf::Color::Black);

        window.draw(playerSprite);
		window.draw(skeletonSprite);

        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.display();

        //------------------------------- Draw --------------------------
    }
}//