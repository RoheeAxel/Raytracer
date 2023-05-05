/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Input
*/

#include "Input.hpp"

Graphics::Input::Input(sf::Vector2f position, sf::Vector2f size, sf::Font &font, std::string placeholderText)
{
    this->_position = position;
    this->_size = size;
    this->_rect.setFillColor(sf::Color::White);
    this->_rect.setOutlineThickness(2.f);
    this->_rect.setOutlineColor(sf::Color::Black);
    this->_rect.setPosition(position);
    this->_rect.setSize(size);
    this->_text.setFont(font);
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setPosition(position.x + 5.f, position.y + 5.f);
    this->_text.setCharacterSize(size.y - 10.f);
    this->_text.setString(placeholderText);
    this->_inputDisplay.setFont(font);
    this->_inputDisplay.setFillColor(sf::Color::Black);
    this->_inputDisplay.setPosition(position.x + 5.f, position.y + 5.f);
    this->_inputDisplay.setCharacterSize(size.y - 10.f);
    this->_placeholderText = placeholderText;
    this->_error.setFont(font);
    this->_error.setFillColor(sf::Color::Red);
    this->_error.setPosition(position.x, position.y + 15.f);
    this->_error.setCharacterSize(size.y - 15.f);
    this->_error.setString("Max 20 characters");
    this->_hasFocus = false;
}

Graphics::Input::~Input()
{
}

void Graphics::Input::draw(sf::RenderWindow &window)
{
    window.draw(this->_rect);
    if (this->_inputText.length() >= 20)
        window.draw(this->_error);
    if (this->_inputText.empty()) {
        if (this->_hasFocus) {
            this->_text.setString("");
        } else {
            this->_text.setString(this->_placeholderText);
        }
        window.draw(this->_text);
    } else {
        this->_inputDisplay.setString(this->_inputText);
        window.draw(this->_inputDisplay);
    }
}

void Graphics::Input::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mouse_pos(event.mouseButton.x, event.mouseButton.y);
        sf::FloatRect bounds = this->_rect.getGlobalBounds();
        if (bounds.contains(mouse_pos)) {
            this->_hasFocus = true;
            this->_text.setString("");
        } else {
            this->_hasFocus = false;
            if (this->_inputText.empty()) {
                this->_inputDisplay.setString("");
                this->_text.setString(this->_placeholderText);
            }
        }
    } else if (event.type == sf::Event::TextEntered && this->_hasFocus) {
        if (event.text.unicode == '\b') {
            if (!this->_inputText.empty()) {
                this->_inputText.pop_back();
                updateInputDisplay();
            }
        } else if (event.text.unicode < 128) {
            if (this->_inputText.length() >= 20)
                return;
            this->_inputText += static_cast<char>(event.text.unicode);
            updateInputDisplay();
        }
    }
}

std::string Graphics::Input::getText() const
{
    return this->_inputText;
}

void Graphics::Input::setPosition(sf::Vector2f position)
{
    this->_position = position;
    this->_rect.setPosition(position);
    this->_text.setPosition(position.x + 5.f, position.y + 5.f);
    this->_inputDisplay.setPosition(position.x + 5.f, position.y + 5.f);
    this->_error.setPosition(position.x + 5.f, position.y + 30.f);
}

void Graphics::Input::setSize(sf::Vector2f size)
{
    this->_size = size;
    this->_rect.setSize(size);
    this->_text.setCharacterSize(size.y - 10.f);
    this->_inputDisplay.setCharacterSize(size.y - 10.f);
    updateInputDisplay();
}

void Graphics::Input::setPlaceholderText(std::string placeholderText)
{
    this->_placeholderText = placeholderText;
    if (this->_inputText.empty() && !this->_hasFocus) {
        this->_text.setString(this->_placeholderText);
    }
}

void Graphics::Input::updateInputDisplay()
{
    this->_inputDisplay.setString(this->_inputText);
    sf::FloatRect input_display_bounds = this->_inputDisplay.getLocalBounds();
    float input_display_width = input_display_bounds.width;
    while (input_display_width > this->_size.x - 10.f) {
        this->_inputText.erase(0, 1);
        this->_inputDisplay.setString(this->_inputText);
        input_display_bounds = this->_inputDisplay.getLocalBounds();
        input_display_width = input_display_bounds.width;
    }
}

sf::Vector2f Graphics::Input::getPosition() const
{
    return this->_position;
}

sf::Vector2f Graphics::Input::getSize() const
{
    return this->_size;
}

bool Graphics::Input::hasFocus() const
{
    return this->_hasFocus;
}

void Graphics::Input::setFocus(bool focus)
{
    this->_hasFocus = focus;
    if (this->_hasFocus) {
        this->_text.setString("");
    } else {
        if (this->_inputText.empty()) {
            this->_text.setString(this->_placeholderText);
        }
    }
}
