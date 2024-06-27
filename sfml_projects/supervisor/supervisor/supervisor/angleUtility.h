#ifndef ANGLE_UTILITY_H
#define ANGLE_UTILITY_H

#include <SFML/Graphics.hpp>
#include "quarters.hpp"

Quarters getQuarter(sf::Vector2i& firstPoint, sf::Vector2i& secondPoint);
float calculateAngle(Quarters quarter, sf::Vector2i& firstPoint, sf::Vector2i& secondPoint);

#endif // !ANGLE_UTILITY_H
