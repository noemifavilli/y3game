#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std; 

const Keyboard::Key controls[4] = {
	Keyboard::A, // Player1 up
	Keyboard::Z, // Player1 down
	Keyboard::Up, // Player2 up
	Keyboard::Down // Player2 down
};

const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 120;
const int gameHeight = 600;
const float paddleSpeed = 400.f;
const float paddleOffsetWall = 10.f;

CircleShape ball;
RectangleShape paddles[2];

void Load() {
	// Set size and origin of paddles 
	for (auto &p : paddles) {
		p.setSize(paddleSize);
		p.setOrigin(paddleSize / 2.f);
	}
	// Set size and origin of ball 
	ball.setRadius(ballRadius);
	ball.setOrigin(ballRadius / 2.f, ballRadius / 2.f);  // Should be half the ball width and height
	// Reset paddle position
	paddles[0].setPosition(Vector2f(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f));
	paddles[1].setPosition(Vector2f(paddleOffsetWall + paddleSize.y / 2.f, gameHeight / 2.f));
	// Reset ball position
	ball.setPosition(40, 300);
} // Load

void Update(RenderWindow &window) {
	// Reset clock and rcalculate delta time
	static Clock clock;
	float dt = clock.restart().asSeconds();
	// Check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		} // if
	} // while 


	// Quit via ESC key 
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	} // if

	// Handle paddle movement 
	float direction = 0.0f; 
	if (Keyboard::isKeyPressed(controls[0])) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		direction++;
	}
	paddles[0].move(Vector2f(0.f, direction * paddleSpeed * dt));
} // Update

void Render(RenderWindow &window) {
	// Draw everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
} // Render 


int main () {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	} // while 
	
	return 0;
} // main	