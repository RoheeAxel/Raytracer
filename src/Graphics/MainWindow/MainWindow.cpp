/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** MainWindow
*/

#include "MainWindow.hpp"
#include <fstream>

Graphics::MainWindow::MainWindow(sf::Vector2f size, std::string title)
    : _window(sf::VideoMode(size.x, size.y), title), _buttons(), _imageSprite(), _size(size),
    _font(), _clusterWindow(sf::Vector2f((1920 / 2) - (400 / 2), (1080 / 2) - 150), sf::Vector2f(400, 270), this->_font),
    _imagePpm(), _threadWindow(sf::Vector2f((1920 / 2) - (400 / 2), (1080 / 2) - 150), sf::Vector2f(400, 150), this->_font)
{
    this->_imageSprite.setPosition(0, 50);
    this->_window.setFramerateLimit(60);
    this->_rectangle.setFillColor(sf::Color(97, 148, 176));
    this->_rectangle.setOutlineThickness(4);
    this->_rectangle.setOutlineColor(sf::Color(0, 0, 0));
    this->_font.loadFromFile("assets/font.ttf");
    this->_clusterWindow.setFont(this->_font);
    this->_threadWindow.setFont(this->_font);

}

Graphics::MainWindow::~MainWindow()
{
}

void Graphics::MainWindow::addButton(Button button)
{
    this->_buttons.push_back(button);
}

void Graphics::MainWindow::run()
{
    Graphics::ButtonType tmp = ButtonType::NONE;

    this->_rectangle.setSize(sf::Vector2f(this->_size.x, this->_buttons[0].getSprite().getGlobalBounds().height + 10));
    while (this->_window.isOpen()) {
        sf::Event event;
        while (this->_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->_window.close();
            if (this->_clusterWindow.getInputClose() == true || this->_threadWindow.getInputClose() == true) {
                tmp = ButtonType::NONE;
                this->_clusterWindow.setInputClose(false);
                this->_threadWindow.setInputClose(false);
            } if (tmp == ButtonType::CLUSTER && this->_clusterWindow.getInputClose() == false)
                this->_clusterWindow.handleEvent(event);
            else if (tmp == ButtonType::THREAD && this->_threadWindow.getInputClose() == false)
                this->_threadWindow.handleEvent(event);
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (Button& button : this->_buttons) {
                    tmp = button.handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                    if (tmp == ButtonType::LOAD) {
                        try {
                            std::system("zenity --file-selection --file-filter=*.ppm > path.txt");
                            this->fillPathPpm();
                            std::system("rm path.txt");
                            this->_imagePpm.run(this->_path, this->_window, this->_threadWindow.getValue());
                            tmp = ButtonType::NONE;
                        } catch (const std::exception& e) {
                            std::cerr << e.what() << std::endl;
                        }
                    } else if (tmp == ButtonType::PLAY) {
                        try {
                            std::system("zenity --file-selection --file-filter=*.cfg > path.txt");
                            this->fillPathPpm();
                            std::system("rm path.txt");
                            this->_imagePpm.configureRaytracer(this->_window, this->_path, this->_threadWindow.getValue());
                            tmp = ButtonType::NONE;
                        } catch (const std::exception& e) {
                            std::cerr << e.what() << std::endl;
                        }
                    } else if (tmp != ButtonType::NONE)
                        break;
                }
            }
        }
        this->_window.clear(sf::Color(152, 152, 152));
        this->_window.draw(this->_rectangle);
        for (Button& button : this->_buttons)
            this->_window.draw(button.getSprite());
        this->_imagePpm.draw(this->_window, this->_path);
        if (tmp == ButtonType::CLUSTER)
            this->_clusterWindow.draw(this->_window, sf::BlendAlpha);
        if (tmp == ButtonType::THREAD)
            this->_threadWindow.draw(this->_window, sf::BlendAlpha);
        this->_window.display();
    }
}

void Graphics::MainWindow::fillPathPpm()
{
    std::ifstream file("path.txt");

    if (file.is_open()) {
        std::getline(file, this->_path, '\n');
        file.close();
    } else
        this->_path = "";
}
