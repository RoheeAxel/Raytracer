/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Button
*/

#include "Button.hpp"

Graphics::Button::Button(sf::Texture &texture, sf::Vector2f position, Graphics::ButtonType type)
    : _sprite(texture), _type(type)
{
    this->_sprite.setPosition(position);
}

Graphics::Button::~Button()
{
}

Graphics::ButtonType Graphics::Button::handleClick(sf::Vector2f clickPos)
{
    if (this->_sprite.getGlobalBounds().contains(clickPos)) {
        switch (this->_type) {
            case ButtonType::THREAD:
                return ButtonType::THREAD;
            case ButtonType::CLUSTER:
                return ButtonType::CLUSTER;
            case ButtonType::LOAD:
                return ButtonType::LOAD;
            case ButtonType::PLAY:
                return ButtonType::PLAY;
            case ButtonType::DOWNLOAD:
                return ButtonType::DOWNLOAD;
            default:
                return ButtonType::NONE;
        }
    }
    return ButtonType::NONE;
}

sf::Sprite Graphics::Button::getSprite() const
{
    return this->_sprite;
}
