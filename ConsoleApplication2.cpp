// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	std::vector <sf::Vertex> lines (1);
	sf::Texture texture;
	sf::Sprite sprite;
	texture.create(800, 600);
	int f = 0;
	texture.update(window);
	sprite.setTexture(texture);
	sprite.setColor(sf::Color::Black);

	int mousedown = 0;
	// run the program as long as the window is open
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				mousedown = 1;
				lines[0] = sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(window)));
				texture.update(window);
			}
			else if ((event.type == sf::Event::MouseMoved) && (mousedown == 1))
			{
				lines.push_back(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(window))));
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				mousedown = 0;
				texture.update(window);
				lines.clear();
				lines.resize(1);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					window.clear(sf::Color::Black);
					texture.update(window);
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}

		f = 1;
		window.clear(sf::Color::Black);

		//sprite.setTexture(texture);
		//sprite.setColor(sf::Color::Red);
		window.draw(sprite);

		window.draw(&lines[0], lines.size(), sf::LinesStrip);

		sprite.setTexture(texture);
		sprite.setColor(sf::Color::White);
		window.display();
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
