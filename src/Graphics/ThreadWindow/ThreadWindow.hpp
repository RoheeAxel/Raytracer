/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** ThreadWindow
*/

#ifndef THREADWINDOW_HPP_
    #define THREADWINDOW_HPP_

    #include "Input.hpp"

namespace Graphics {
    class ThreadWindow {
        public:
            ThreadWindow(sf::Vector2f position, sf::Vector2f size, sf::Font &font);
            ~ThreadWindow();
            void handleEvent(sf::Event &event);
            void draw(sf::RenderWindow &window, sf::RenderStates states);
            void createCloseButton();
            bool getInputClose();
            void setInputClose(bool close);
            void setFont(sf::Font font);
            std::string getValue();

        private:
            sf::Text _title;
            sf::RectangleShape _background;
            sf::RectangleShape _close_button;
            bool _has_focus;
            bool _is_closed;
            sf::Text _close_text;
            sf::Font _font;
            std::vector<Input> _input;
    };
}

#endif /* !THREADWINDOW_HPP_ */
