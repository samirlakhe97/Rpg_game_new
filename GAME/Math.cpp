#include "Math.h"

sf::Vector2f Math::normalize(sf::Vector2f bullet)
{
    float length = sqrt((bullet.x * bullet.x) + (bullet.y * bullet.y));
    if (length != 0)
        return sf::Vector2f(bullet.x / length, bullet.y / length);
    else
        return bullet;
}
