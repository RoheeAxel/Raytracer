/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Button
*/

#include "Button.hpp"

Graphics::Button::Button(sf::Texture &texture, sf::Vector2f position, Graphics::ButtonType type)
    : m_sprite(texture), m_type(type)
{
    m_sprite.setPosition(position);
}

Graphics::Button::~Button()
{
}

Graphics::ButtonType Graphics::Button::handleClick(sf::Vector2f clickPos)
{
    if (m_sprite.getGlobalBounds().contains(clickPos)) {
        switch (m_type) {
            case ButtonType::THREAD:
                return ButtonType::THREAD;
            case ButtonType::CLUSTER:
                return ButtonType::CLUSTER;
            case ButtonType::SETTINGS:
                return ButtonType::SETTINGS;
            case ButtonType::LOAD:
                return ButtonType::LOAD;
            case ButtonType::PLAY:
                return ButtonType::PLAY;
            default:
                return ButtonType::NONE;
        }
    }
    return ButtonType::NONE;
}

sf::Sprite Graphics::Button::getSprite() const
{
    return m_sprite;
}
