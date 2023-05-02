/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Input
*/

#ifndef INPUT_HPP_
    #define INPUT_HPP_

    #include <iostream>
    #include <SFML/Graphics.hpp>

namespace Graphics {
    class Input {
        public:
            Input(sf::Vector2f position, sf::Vector2f size, sf::Font &font, std::string placeholder_text = "");
            ~Input();
            void draw(sf::RenderWindow &window);
            void handleEvent(sf::Event &event);
            std::string getText() const;
            void setPosition(sf::Vector2f position);
            void setSize(sf::Vector2f size);
            void setPlaceholderText(std::string placeholder_text);
            void updateInputDisplay();
            sf::Vector2f getPosition() const;
            sf::Vector2f getSize() const;
            bool hasFocus() const;
            void setFocus(bool focus);

        private:
            sf::RectangleShape _rect;
            sf::Text _text;
            sf::Text _inputDisplay;
            std::string _inputText;
            std::string _placeholderText;
            sf::Vector2f _position;
            sf::Vector2f _size;
            sf::Text _error;
            bool _hasFocus;
    };
}

#endif /* !INPUT_HPP_ */
