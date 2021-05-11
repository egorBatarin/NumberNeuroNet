// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	int mousedown = 0;
	sf::Texture texture;
	texture.create(800, 600);
	sf::Sprite sprite;
	sf::CircleShape circle;
	circle.setRadius(10);
	//circle.setPosition(50, 80);
	//circle.setOutlineColor(sf::Color::Red);
	//circle.setOutlineThickness(5);
	circle.setFillColor(sf::Color::Red);
	window.setFramerateLimit(860);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				circle.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
				window.draw(circle);
				texture.update(window);
				mousedown = 1;
			}
			if (event.type == sf::Event::Closed) window.close();
			if ((event.type == sf::Event::MouseMoved) && (mousedown == 1))
			{
				circle.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
				window.draw(circle);
				texture.update(window);
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				mousedown = 0;
			}
		}
		
		window.clear();
		sprite.setTexture(texture);
		window.draw(sprite);
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
