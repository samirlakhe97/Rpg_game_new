#include <SFML/Graphics.hpp>

int main()
{       //------------------------------- Initialize --------------------------
        // create the window
        sf::ContextSettings setting;
        setting.antiAliasingLevel = 4;
        sf::RenderWindow window(sf::VideoMode({ 1000, 600 }), "My window",sf::Style::Default);

        sf::CircleShape Shape(50.0f);
        Shape.setFillColor(sf::Color::Cyan);
        Shape.setPosition(sf::Vector2f(100.0f, 100.0f));
        Shape.setOutlineColor(sf::Color::Magenta);
        Shape.setOutlineThickness(-3.5f);
        Shape.setOrigin({ Shape.getRadius(), Shape.getRadius() });

        sf::RectangleShape Shape1(sf::Vector2f(100.0f, 50.0f));
        Shape1.setFillColor(sf::Color::Yellow);
        Shape1.setPosition(sf::Vector2f(50.0f, 50.0f));
		Shape1.setOrigin(Shape1.getSize() / 2.0f);
        
        sf::CircleShape Triangle(50.0f, 3);
        Triangle.setPosition(sf::Vector2f(50.0f,0.0f));

        sf::CircleShape Square(50.0f, 4);
        Square.setPosition(sf::Vector2f(150.0f, 00.0f));
        Square.setOrigin({ Square.getRadius() ,Square.getRadius() });

        sf::CircleShape Pentagon(50.0f, 5);
        Pentagon.setPosition(sf::Vector2f(300.0f, 00.0f));

        sf::CircleShape Hexagon(50.0f, 6);
        Hexagon.setPosition(sf::Vector2f(450.0f, 00.0f));
        //------------------------------- Initialize --------------------------


        //------------------------------- Update --------------------------
    
        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            while (const std::optional event = window.pollEvent())
            {
                // "close requested" event: we close the window
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
        //------------------------------- Update --------------------------
        

        //------------------------------- Draw --------------------------
        // clear the window with black color
        window.clear(sf::Color::Black);
        //window.draw(Shape);
        window.draw(Triangle);
        window.draw(Square);
        window.draw(Pentagon);
        window.draw(Hexagon);
        // end the current frame
        window.display();
        //------------------------------- Draw --------------------------
    }
}