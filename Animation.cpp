#include "GameMath.h"







class Bone{
public:
	

	Bone(sf::Vector2f Position, float Radius, unsigned int Limit) {
		position = Position;
		radius = Radius;
		limit = Limit;
	}

	sf::Vector2f getPosition() { return position; }
	void setDirection(sf::Vector2f Direction) { direction = Direction; }

	void addBone(Bone& bone) {
		bone.setDirection(toPolarCoord(bone.position - position));
		bone.update(position, direction);
		conected.push_back(&bone);
	}

	void move(sf::Vector2f offset) {
		position += offset;
		if(sizeof(conected) > 0) for (auto bone : conected) {
			bone->update(position, direction);
		}
	}

	void update(sf::Vector2f Pos, sf::Vector2f Dir) {
		direction = toPolarCoord(position - Pos);
		if (direction.x != radius) {
			direction.x = radius;			
		}
		if (polarAngle(direction, Dir) < limit) {
			if (direction.y <= Dir.y) {
				direction.y = Dir.y - limit;
			}
			else if (direction.y < Dir.y) {
				direction.y = Dir.y + limit;
			}
		}
		move(Pos + cartesian(direction) - position);
		
	}

private:
	
	std::vector <Bone*> conected;	
	sf::Vector2f position;
	sf::Vector2f direction;
	unsigned int limit;
	float radius;
	
};

