#include <SFML/Graphics.hpp>

int main() {
    // ������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Triangle");

    // ������� ������ ������ ��� ������������
    sf::VertexArray triangle(sf::Triangles, 3);

    // ������ ���������� ������ ������������
    triangle[0].position = sf::Vector2f(400.0f, 200.0f);  // ������� �������
    triangle[1].position = sf::Vector2f(200.f, 450.f);  // ����� ������ �������
    triangle[2].position = sf::Vector2f(500.f, 450.f);  // ������ ������ �������

    // ������ ����� ������ (�����������)
    triangle[0].color = sf::Color(232, 233, 235);
    triangle[1].color = sf::Color(90, 91, 92);
    triangle[2].color = sf::Color(90, 91, 92);

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
        window.draw(triangle);

        // ���������� ���������� ����
        window.display();
    }

    return 0;
}
