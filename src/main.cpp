#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

const int SIZE = 15;

int main()
{
	// setting the random seed
	std::srand(static_cast<unsigned int>(time(0)));
	// spaces between window sides and array
	int sideSpace = 40;
	sf::RenderWindow window(sf::VideoMode(sideSpace*2 + 50 * SIZE, 700), "Colored array");

	// create an array of int, randomize and sort it
	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i)
		arr[i] = std::rand() % 600 + 1; //1-600
	std::sort(std::begin(arr), std::end(arr));

	// create an array of columns and randomly initialize it
	sf::RectangleShape shapes[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		float spawnPositionY = 650.f;
		float columnWidth = 40.f;
		float space = 10.f;

		shapes[i].setSize(sf::Vector2f(40, arr[i]));

		// randomize colors
		int r = std::rand() % 255 + 1;
		int g = std::rand() % 255 + 1;
		int b = std::rand() % 255 + 1;

		shapes[i].setFillColor(sf::Color(r, g, b));
		shapes[i].setOrigin(0,arr[i]);
		// arrange columns one by one
		shapes[i].setPosition(sideSpace + (columnWidth + space) * i, spawnPositionY);
	}

	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		// display columns
		for (int i = 0; i < SIZE; ++i)
			window.draw(shapes[i]);
		window.display();
	}

	return 0;
}