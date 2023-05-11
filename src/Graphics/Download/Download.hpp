/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Download
*/

#ifndef DOWNLOAD_HPP_
    #define DOWNLOAD_HPP_

    #include "Input.hpp"

namespace Graphics {
    class Download {
        public:
            enum Extension {
                PNG,
                JPG,
                BMP,
                TGA,
                NONE
            };

            Download(sf::Vector2f position, sf::Vector2f size, sf::Font &font);
            ~Download();
            bool handleEvent(sf::Event &event);
            void draw(sf::RenderWindow &window, sf::RenderStates states);
            void createCloseButton();
            void addExtension(sf::Vector2f size, sf::Vector2f position, std::string title);
            bool getInputClose();
            void setInputClose(bool close);
            void setFont(sf::Font font);
            std::string getValue();
            std::string getExtension();
            void reset();

        private:
            sf::Text _title;
            sf::RectangleShape _background;
            sf::RectangleShape _close_button;
            bool _has_focus;
            bool _is_closed;
            sf::Text _close_text;
            sf::Font _font;
            std::vector<Input> _input;
            std::vector<sf::RectangleShape> _extensions;
            std::vector<sf::Text> _extensions_text;
            std::string _extensionName;
            sf::RectangleShape _validateButton;
            sf::Text _validateText;
    };
}

#endif /* !DOWNLOAD_HPP_ */
