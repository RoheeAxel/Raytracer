/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** MainWindow
*/

#include "MainWindow.hpp"

Graphics::MainWindow::MainWindow(sf::Vector2f size, std::string title)
    : m_window(sf::VideoMode(size.x, size.y), title), m_buttons(), m_imageSprite(), m_size(size)
{
    m_imageSprite.setPosition(0, 50);
    m_window.setFramerateLimit(60);
    m_rectangle.setFillColor(sf::Color(97, 148, 176));
    m_rectangle.setOutlineThickness(4);
    m_rectangle.setOutlineColor(sf::Color(0, 0, 0));
}

Graphics::MainWindow::~MainWindow()
{
}

void Graphics::MainWindow::addButton(Button button)
{
    m_buttons.push_back(button);
}

void Graphics::MainWindow::run()
{
    Graphics::ButtonType tmp;

    m_rectangle.setSize(sf::Vector2f(m_size.x, m_buttons[0].getSprite().getGlobalBounds().height + 10));
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (Button& button : m_buttons) {
                    tmp = button.handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                    if (tmp != ButtonType::NONE)
                        break;
                }
            }
        }
        m_window.clear(sf::Color(152, 152, 152));
        m_window.draw(m_rectangle);
        for (Button& button : m_buttons)
            m_window.draw(button.getSprite());
        if (tmp == ButtonType::THREAD)
            std::cout << "THREAD" << std::endl;
        else if (tmp == ButtonType::CLUSTER)
            std::cout << "CLUSTER" << std::endl;
        else if (tmp == ButtonType::SETTINGS)
            std::cout << "SETTINGS" << std::endl;
        else if (tmp == ButtonType::LOAD)
            std::cout << "LOAD" << std::endl;
        else if (tmp == ButtonType::PLAY){
            Viewer::ImagePpm image("result.ppm");
            image.draw(this->m_window);
        }
        else if (tmp == ButtonType::NONE)
            std::cout << "NONE" << std::endl;
        m_window.display();
    }
}
