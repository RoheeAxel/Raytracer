/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

    #include <iostream>
    #include <SFML/Graphics.hpp>

namespace Graphics {
    enum class ButtonType {
        THREAD,
        CLUSTER,
        SETTINGS,
        LOAD,
        PLAY,
        NONE
    };

    class Button {
        public:
            Button(sf::Texture &texture, sf::Vector2f position, Graphics::ButtonType type);
            ~Button();
            Graphics::ButtonType handleClick(sf::Vector2f clickPos);
            sf::Sprite getSprite() const;

        private:
            sf::Sprite _sprite;
            Graphics::ButtonType _type;
    };
}

#endif /* !BUTTON_HPP_ */
