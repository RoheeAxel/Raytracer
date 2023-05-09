/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** ThreadWindow
*/

#include "ThreadWindow.hpp"

Graphics::ThreadWindow::ThreadWindow(sf::Vector2f position, sf::Vector2f size, sf::Font &font)
    : _background(size), _close_button(sf::Vector2f(20.f, 20.f)), _has_focus(false), _is_closed(false), _font(font)
{
    this->_background.setPosition(position);
    this->_background.setFillColor(sf::Color(200, 200, 200));
    this->_title.setFont(this->_font);
    this->_title.setString("Multithreading");
    this->_title.setCharacterSize(24);
    this->_title.setFillColor(sf::Color::Black);
    this->_title.setPosition(this->_background.getPosition() + sf::Vector2f(10.f, 10.f));
    createCloseButton();
    sf::Vector2f input_size(this->_background.getSize().x - 20.f, 30.f);
    Input input = Input(this->_background.getPosition() + sf::Vector2f(10.f, 4000.f), input_size, this->_font, "Nb thread");
    this->_input.push_back(input);
    this->_input[0].setPosition(this->_background.getPosition() + sf::Vector2f(10.f, 70.f + 0 * (this->_input[0].getSize().y + 20.f)));
}

Graphics::ThreadWindow::~ThreadWindow()
{
}

void Graphics::ThreadWindow::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (this->_close_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            this->_is_closed = true;
            return;
        }
    }
    for (auto& input : this->_input)
        input.handleEvent(event);
}

void Graphics::ThreadWindow::draw(sf::RenderWindow &window, sf::RenderStates states)
{
    window.draw(this->_background, states);
    window.draw(this->_close_button, states);
    window.draw(this->_close_text, states);
    window.draw(this->_title, states);
    for (auto &input : this->_input)
        input.draw(window);
}

void Graphics::ThreadWindow::createCloseButton()
{
    this->_close_button.setFillColor(sf::Color::Red);
    this->_close_button.setPosition(this->_background.getPosition() + sf::Vector2f(this->_background.getSize().x - this->_close_button.getSize().x, 0.f));
    this->_close_text.setFont(this->_font);
    this->_close_text.setString("X");
    this->_close_text.setCharacterSize(16);
    this->_close_text.setFillColor(sf::Color::White);
    this->_close_text.setPosition(this->_close_button.getPosition() + sf::Vector2f(4.f, 0.f));
}

bool Graphics::ThreadWindow::getInputClose()
{
    return this->_is_closed;
}

void Graphics::ThreadWindow::setInputClose(bool close)
{
    this->_is_closed = close;
}

void Graphics::ThreadWindow::setFont(sf::Font font)
{
    this->_font = font;
}
