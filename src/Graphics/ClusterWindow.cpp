/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** ClusterWindow
*/

#include "ClusterWindow.hpp"

Graphics::ClusterWindow::ClusterWindow(sf::Vector2f position, sf::Vector2f size, sf::Font &font)
    : _background(size), _close_button(sf::Vector2f(20.f, 20.f)), _has_focus(false), _is_closed(false), _font(font)
{
    this->_background.setPosition(position);
    this->_background.setFillColor(sf::Color(200, 200, 200));
    this->_title.setFont(this->_font);
    this->_title.setString("Clustering");
    this->_title.setCharacterSize(24);
    this->_title.setFillColor(sf::Color::Black);
    this->_title.setPosition(sf::Vector2f((this->_background.getPosition().x + this->_background.getPosition().x / 2), this->_background.getPosition().y));
    createCloseButton();
    createInputs();
}

void Graphics::ClusterWindow::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (this->_close_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            this->_is_closed = true;
            return;
        }
    }
    for (auto& input : this->_inputs)
        input.handleEvent(event);
}

void Graphics::ClusterWindow::draw(sf::RenderWindow &window, sf::RenderStates states)
{
    window.draw(this->_background, states);
    window.draw(this->_close_button, states);
    window.draw(this->_close_text, states);
    window.draw(this->_title, states);
    for (auto &input : this->_inputs)
        input.draw(window);
}

void Graphics::ClusterWindow::createBackground()
{
    this->_background.setFillColor(sf::Color(200, 200, 200));
}

void Graphics::ClusterWindow::createCloseButton()
{
    this->_close_button.setFillColor(sf::Color::Red);
    this->_close_button.setPosition(this->_background.getPosition() + sf::Vector2f(this->_background.getSize().x - this->_close_button.getSize().x, 0.f));
    this->_close_text.setFont(this->_font);
    this->_close_text.setString("X");
    this->_close_text.setCharacterSize(16);
    this->_close_text.setFillColor(sf::Color::White);
    this->_close_text.setPosition(this->_close_button.getPosition() + sf::Vector2f(4.f, 0.f));
}

void Graphics::ClusterWindow::createInputs()
{
    float input_height = 30.f;
    float input_spacing = 50.f;
    sf::Vector2f input_size(this->_background.getSize().x - 20.f, input_height);
    for (int i = 0; i < 4; i++) {
        Input input(this->_background.getPosition() + sf::Vector2f(10.f, input_spacing + i * (input_height + input_spacing)), input_size, this->_font, "Ip cluster " + std::to_string(i + 1));
        this->_inputs.push_back(input);
    }
    updateInputPositions();
}

void Graphics::ClusterWindow::updateInputPositions()
{
    for (int i = 0; i < 4; i++)
        this->_inputs[i].setPosition(this->_background.getPosition() + sf::Vector2f(10.f, 70.f + i * (this->_inputs[i].getSize().y + 20.f)));
}

void Graphics::ClusterWindow::updateInputFocus()
{
    for (auto &input : this->_inputs) {
        if (input.hasFocus()) {
            this->_has_focus = true;
            return;
        }
    }
    this->_has_focus = false;
}

bool Graphics::ClusterWindow::getInputClose()
{
    return this->_is_closed;
}

void Graphics::ClusterWindow::setInputClose(bool close)
{
    this->_is_closed = close;
}

void Graphics::ClusterWindow::setFont(sf::Font font)
{
    this->_font = font;
}
