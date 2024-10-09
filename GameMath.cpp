#include "GameMath.h"

float length(sf::Vector2f vec) {
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}
float length(sf::Vector2f vec1, sf::Vector2f vec2) {
	return length(sf::Vector2f(vec1.x - vec2.x, vec1.y - vec2.y));
}

sf::Vector2f norm(sf::Vector2f vec) {
	return sf::Vector2f(vec.x / length(vec), vec.y / length(vec));
}

float dot(sf::Vector2f vec1, sf::Vector2f vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

float polarAngle(sf::Vector2f vec) {
	double pi = M_PI;
	float angle = acos(vec.x) * 180 / pi;
	if (vec.y < 0) angle = 360 - angle;
	return angle;
}


float polarAngle(sf::Vector2f vec1, sf::Vector2f vec2) {
	float angle = abs(polarAngle(vec1) - polarAngle(vec2));
	if (angle <= 180) return angle;
	else return 360 - angle;
}


sf::Vector2f toPolarCoord(sf::Vector2f vec) {
	return sf::Vector2f(polarAngle(vec), length(vec));
}

sf::Vector2f cartesian(sf::Vector2f vec) {
	vec.y = vec.y * M_PI / 180;
	return sf::Vector2f(vec.x * cos(vec.y), vec.x * sin(vec.y));
}

