#include <SFML/Graphics.hpp>
#include "vertexTriangleUtility.h"

int main() {
    // ������� ����
    sf::ContextSettings settings;
    settings.antialiasingLevel = 3;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Triangle", sf::Style::Default, settings);

    // ������� ������ ������ ��� ������������
    sf::VertexArray triangle(sf::Triangles, 3);

    // ������ ���������� ������ ������������
    

    sf::VertexArray myTriangle = generateVertexTriangle(sf::Vector2f(400, 300), 300);
    myTriangle[0].color = sf::Color::Red;
    myTriangle[1].color = sf::Color::Green;
    myTriangle[2].color = sf::Color::Blue;

    // �������� ���� ���������
    while (window.isOpen()) {
        // ������������ �������
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ������� ����
        window.clear();



        // ������ �����������
        window.draw(myTriangle);

        // ���������� ���������� ����
        window.display();
    }

    return 0;
}
