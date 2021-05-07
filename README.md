# NumberNeuroNet
This project is dedicated to neuronet, which recognizes numbers 0-9, painted in the popup window.
Compilation:
g++ -c ConsoleApplication4.cpp Data/data.cpp -std=c++2a
g++ ConsoleApplication4.o data.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
