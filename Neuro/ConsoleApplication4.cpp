﻿#include <SFML/Graphics.hpp>
#include <vector>
#include "Data/data.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>

void neuronet();
size_t max_index(matrix::Matrix<>& matr);
const int alldata = 784;
const int nstr = 28;
const int nstl = 28;
const int xsize = 560;
const int ysize = 560;

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(xsize, ysize), "My window", sf::Style::Titlebar | sf::Style::Close);
	//sf::View myView(sf::Vector2f(200, 150), sf::Vector2f(400, 300));
	//window.setView(myView);
	std::vector <sf::Vertex> lines(1);
	sf::Vector2f Vect;
	sf::Texture texture;
	sf::Sprite sprite;
	int f = 0;
	bool neirarr[alldata] = { 0 };
	bool arr[nstr][nstl] = { 0 };
	texture.create(xsize, ysize);
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
				if (event.key.code == sf::Keyboard::Enter)
				{

					for (int i = 0; i < nstr; i++)
						for (int j = 0; j < nstl; j++)
							arr[i][j] = 0;

					sf::Image frame = texture.copyToImage();
					for (int i = 0; i < xsize; i++)
						for (int j = 0; j < ysize; j++)
							if (frame.getPixel(i, j) != sf::Color::Black)
								arr[nstr * j / ysize][nstl * i / xsize] = 1;
					for (int i = 0; i < nstr; i++)
						for (int j = 0; j < nstl; j++)
							neirarr[(28 * i) + j] = arr[i][j];

				}
				if (event.key.code == sf::Keyboard::Numpad0)
				{
					for (int i = 0; i < nstr; i++)
					{
						printf("\n");
						for (int j = 0; j < nstl; j++)
							printf("%d", arr[i][j]);
					}
					printf("\n");
					printf("\n");
					for (int i = 0; i < alldata; i++)
						printf("%d,", neirarr[i]);

					std::ofstream of("x.txt");
					if (!of.is_open())
					{
						std::cout << "Can't open file!";
						exit(EXIT_FAILURE);
					}
					for (int i = 0; i < alldata - 1; i++)
						of << neirarr[i] << ", ";
					of << neirarr[alldata - 1];
					of.close();
					neuronet();
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

void neuronet()
{
	auto&& data = ReadBook();
	/*
	data.w2 = w2.txt
	data.w3 = w3.txt
	and so on...

	Everything is a matrix - vector is too = matrix <n * 1>

	multiplication as usual *
	sub and add works too using - and +

	COMPILING: g++ main.cpp Data/data.cpp -std=c++2a
	*/
	auto z2 = (data.w2 * data.x) + data.b2;
	//std::cout << data.b2 << z2 << std::endl;
	matrix::Matrix<> a2(z2.getLines(), z2.getColumns());
	std::transform(z2.begin(), z2.end(), a2.begin(), [](double elem) -> double { return (1.0 / (1.0 + std::exp(-1 * elem))); });
	//std::cout << "a2: " << a2 << std::endl;
	auto z3 = data.w3*a2 + data.b3;
	matrix::Matrix<> a3(z3.getLines(), z3.getColumns());
	std::transform(z3.begin(), z3.end(), a3.begin(), [](double elem) -> double { return (1.0 / (1.0 + std::exp(-1 * elem))); });

	auto result = max_index(a3);
	//std::cout << "a3: " << a3 << std::endl;
	//std::cout << "result: " << result << std::endl;
	//std::cout << data.w3 * data.b2; //example of printing multiplications of matrixes
	std::ofstream fout("result.txt"); //
	fout << result; // Р·Р°РїРёСЃСЊ СЃС‚СЂРѕРєРё РІ С„Р°Р№Р»
	fout.close(); // Р·Р°РєСЂС‹РІР°РµРј С„Р°Р№Р»
}

size_t max_index(matrix::Matrix<>& matr)
{
	double max_elem = -1;
	size_t max_index = -1, index = 0;
	for (auto&& elem : matr)
	{
		if (elem > max_elem) {
			max_elem = elem;
			max_index = index;
		}
		index++;
	}
	return max_index;
}