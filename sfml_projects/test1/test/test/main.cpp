#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Triangle");

    // Создаем массив вершин для треугольника
    sf::VertexArray triangle(sf::Triangles, 3);

    // Задаем координаты вершин треугольника
    triangle[0].position = sf::Vector2f(400.0f, 200.0f);  // Верхняя вершина
    triangle[1].position = sf::Vector2f(200.f, 450.f);  // Левая нижняя вершина
    triangle[2].position = sf::Vector2f(500.f, 450.f);  // Правая нижняя вершина

    // Задаем цвета вершин (опционально)
    triangle[0].color = sf::Color(232, 233, 235);
    triangle[1].color = sf::Color(90, 91, 92);
    triangle[2].color = sf::Color(90, 91, 92);

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
        window.draw(triangle);

        // Отображаем содержимое окна
        window.display();
    }

    return 0;
}
