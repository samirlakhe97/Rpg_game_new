#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include<iostream>
#include<math.h>
#include<vector>

#include "Player.h"
#include "Skeleton.h"
#include "Math.h"

int main()
{       
    Player player;
    Skeleton skeleton;
	Math math;
    //------------------------------- Initialize -------------------------
    sf::ContextSettings setting;
    setting.antiAliasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode({ 1820,980 }), "My window", sf::Style::Default);
    sf::Vector2f bulletDirection;

	player.Init();
	skeleton.Init();
    //------------------------------- Initialize --------------------------
 

	//------------------------------- Load --------------------------
	player.Load();
	skeleton.Load();
	//------------------------------- Load --------------------------

   //------------------------------- Update --------------------------
    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();

        }

		skeleton.Update();
		player.Update(skeleton);

        //------------------------------- Update --------------------------


        //------------------------------- Draw --------------------------
        window.clear(sf::Color::Black);
		skeleton.Draw(window);
        player.Draw(window);

        window.display();
        //------------------------------- Draw --------------------------
    }
}