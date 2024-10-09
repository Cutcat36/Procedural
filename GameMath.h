#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

float length(sf::Vector2f vec);
float length(sf::Vector2f vec1, sf::Vector2f vec2);
sf::Vector2f norm(sf::Vector2f vec);
float dot(sf::Vector2f vec1, sf::Vector2f vec2);
float polarAngle(sf::Vector2f vec);
float polarAngle(sf::Vector2f vec1, sf::Vector2f vec2);
sf::Vector2f toPolarCoord(sf::Vector2f vec);
sf::Vector2f cartesian(sf::Vector2f vec);
