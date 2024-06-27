#include <SFML/Graphics.hpp>
#include "vertexTriangleUtility.h"

int main() {
    // Создаем окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 3;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Triangle", sf::Style::Default, settings);

    // Создаем массив вершин для треугольника
    sf::VertexArray triangle(sf::Triangles, 3);

    // Задаем координаты вершин треугольника
    

    sf::VertexArray myTriangle = generateVertexTriangle(sf::Vector2f(400, 300), 300);
    myTriangle[0].color = sf::Color::Red;
    myTriangle[1].color = sf::Color::Green;
    myTriangle[2].color = sf::Color::Blue;

    // Основной цикл программы
    while (window.isOpen()) {
        // Обрабатываем события
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Очищаем окно
        window.clear();



        // Рисуем треугольник
        window.draw(myTriangle);

        // Отображаем содержимое окна
        window.display();
    }

    return 0;
}
