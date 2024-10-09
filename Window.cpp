#include "GameMath.h"
#include "Animation.cpp"


class Body {
public:

	Bone* head;
	sf::Vector2f point = sf::Vector2f(0, 0);
	sf::Vector2f position;

	Body() {
		position = sf::Vector2f(0, 0);
		create();
	}

	void create() {
		segment.push_back(Bone(position, 200, 90));
		segment[0].setDirection(toPolarCoord(segment[0].getPosition() - point));
		for (int i = 1; i < 10; i++) {
			segment.push_back(Bone(sf::Vector2f(25 * i, 0), 200, 90));
			segment[i - 1].addBone(segment[i]);
		}
		for (int i = 0; i < 10; i++) {
			circles.push_back(sf::CircleShape(10));
			circles[i].setFillColor(sf::Color::White);
			circles[i].setPosition(segment[i].getPosition());
		}
	}

	void update(double time, sf::Vector2f mouse) {
		point.x -= 1;
		segment[0].setDirection(toPolarCoord(segment[0].getPosition() - point));
		segment[0].move(sf::Vector2f(-1, 0));
	}

	void draw(sf::RenderWindow& window) {
		int counter = 0;
		for (auto circle : circles) {
			circle.setPosition(segment[counter].getPosition());
			window.draw(circle);
			counter++;
		}
	}

private:

	std::vector <sf::CircleShape> circles;
	std::vector <Bone> segment;


};


class Window {
public:

	Window(float width, float height) {
		create(width, height);
	}

	void create(float width, float height) {
		window.create(sf::VideoMode(width, height), "Procedural animation", sf::Style::Fullscreen);
		window.setVerticalSyncEnabled(true);
		camera.setSize(sf::Vector2f(width, height));
		camera.setCenter(0, 0);
	}		

	sf::Vector2f getMousePosition() {
		return sf::Vector2f(sf::Mouse::getPosition(window));		
	}

	bool isOpen() { return window.isOpen(); }

	void close() {
		window.close();
	}

	bool pollEvent(sf::Event& event) {
		return window.pollEvent(event);
	}

	double getTime() {
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		return time;
	}

	void move(float x, float y) { move(sf::Vector2f(x, y)); }
	void move(sf::Vector2f offset) {
		camera.move(offset);
	}

	void update(Body& body) {
		body.update(getTime(), getMousePosition());
		window.setView(camera);
		window.clear();
		body.draw(window);
		window.display();
	}

private:

	sf::RenderWindow window;
	sf::View camera;
	sf::Clock clock;

};