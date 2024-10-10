#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

const int gameWidth = 120;
const int gameHeight = 600;

void Load() {
	if (!spritesheet.loadFromFile("res/img/aliens.png")) {
		cerr << "Failed to load aliens" << std::endl; 
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(32, 32)));
}
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

}
void Render(RenderWindow& window) {
	window.draw(invader);
}
int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "ALIENS");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	} // while 

	return 0;
} // main	
