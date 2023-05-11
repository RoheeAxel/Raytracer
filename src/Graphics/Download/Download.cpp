/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Download
*/

#include "Download.hpp"

Graphics::Download::Download(sf::Vector2f position, sf::Vector2f size, sf::Font &font)
    : _background(size), _close_button(sf::Vector2f(20.f, 20.f)), _has_focus(false), _is_closed(false), _font(font)
{
    this->_background.setPosition(position);
    this->_background.setFillColor(sf::Color(200, 200, 200));
    this->_title.setFont(this->_font);
    this->_title.setString("Download");
    this->_title.setCharacterSize(24);
    this->_title.setFillColor(sf::Color::Black);
    this->_title.setPosition(this->_background.getPosition() + sf::Vector2f(10.f, 10.f));
    createCloseButton();
    sf::Vector2f input_size(this->_background.getSize().x - 20.f, 30.f);
    Input input = Input(this->_background.getPosition() + sf::Vector2f(10.f, 4000.f), input_size, this->_font, "Name of the File");
    this->_input.push_back(input);
    this->_input[0].setPosition(this->_background.getPosition() + sf::Vector2f(10.f, 70.f + 0 * (this->_input[0].getSize().y + 20.f)));
    sf::Vector2f pB = this->_background.getPosition();
    this->addExtension(sf::Vector2f(75, 50), sf::Vector2f(pB.x + 10, pB.y + 120), "png");
    this->addExtension(sf::Vector2f(75, 50), sf::Vector2f(pB.x + 110, pB.y + 120), "jpg");
    this->addExtension(sf::Vector2f(75, 50), sf::Vector2f(pB.x + 210, pB.y + 120), "bmp");
    this->addExtension(sf::Vector2f(75, 50), sf::Vector2f(pB.x + 310, pB.y + 120), "tga");
    this->_validateButton.setSize(sf::Vector2f(100.f, 30.f));
    this->_validateButton.setPosition(sf::Vector2f(pB.x + (this->_background.getSize().x / 2 - 50), pB.y + 180));
    this->_validateButton.setFillColor(sf::Color::Green);
    this->_validateText.setFont(this->_font);
    this->_validateText.setString("Valider");
    this->_validateText.setCharacterSize(24);
    this->_validateText.setFillColor(sf::Color::Black);
    this->_validateText.setPosition(this->_validateButton.getPosition() + sf::Vector2f(10.f, 0.f));
}

Graphics::Download::~Download()
{
}

bool Graphics::Download::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (this->_close_button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            this->reset();
            this->_is_closed = true;
            return false;
        }
        for (auto &extension : this->_extensions) {
            if (extension.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                extension.setFillColor(sf::Color::Cyan);
                this->_extensionName = this->_extensions_text[&extension - &this->_extensions[0]].getString();
                for (auto &extension2 : this->_extensions) {
                    if (&extension2 != &extension)
                        extension2.setFillColor(sf::Color::White);
                }
                return false;
            }
        }
        if (this->_validateButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            this->_is_closed = true;
            return true;
        }
    }
    for (auto &input : this->_input)
        input.handleEvent(event);
    return false;
}

void Graphics::Download::draw(sf::RenderWindow &window, sf::RenderStates states)
{
    window.draw(this->_background, states);
    window.draw(this->_close_button, states);
    window.draw(this->_close_text, states);
    window.draw(this->_title, states);
    for (auto &input : this->_input)
        input.draw(window);
    for (auto &extension : this->_extensions)
        window.draw(extension, states);
    for (auto &extension_text : this->_extensions_text)
        window.draw(extension_text, states);
    window.draw(this->_validateButton, states);
    window.draw(this->_validateText, states);
}

void Graphics::Download::createCloseButton()
{
    this->_close_button.setFillColor(sf::Color::Red);
    this->_close_button.setPosition(this->_background.getPosition() + sf::Vector2f(this->_background.getSize().x - this->_close_button.getSize().x, 0.f));
    this->_close_text.setFont(this->_font);
    this->_close_text.setString("X");
    this->_close_text.setCharacterSize(16);
    this->_close_text.setFillColor(sf::Color::White);
    this->_close_text.setPosition(this->_close_button.getPosition() + sf::Vector2f(4.f, 0.f));
}

void Graphics::Download::addExtension(sf::Vector2f size, sf::Vector2f position, std::string title)
{
    sf::RectangleShape extension(size);
    extension.setFillColor(sf::Color::White);
    extension.setPosition(position);
    extension.setOutlineThickness(1.f);
    extension.setOutlineColor(sf::Color::Black);
    sf::Text text;
    text.setFont(this->_font);
    text.setString(title);
    text.setCharacterSize(26);
    text.setFillColor(sf::Color::Black);
    text.setPosition(extension.getPosition() + sf::Vector2f(15, 8.f));

    this->_extensions.push_back(extension);
    this->_extensions_text.push_back(text);
}

bool Graphics::Download::getInputClose()
{
    return this->_is_closed;
}

void Graphics::Download::setInputClose(bool close)
{
    this->_is_closed = close;
}

void Graphics::Download::setFont(sf::Font font)
{
    this->_font = font;
}

std::string Graphics::Download::getValue()
{
    return this->_input[0].getText();
}

std::string Graphics::Download::getExtension()
{
    return this->_extensionName;
}

void Graphics::Download::reset()
{
    this->_is_closed = false;
    this->_input[0].setValue("");
    this->_extensionName = "";
    for (auto &extension : this->_extensions)
        extension.setFillColor(sf::Color::White);
}
