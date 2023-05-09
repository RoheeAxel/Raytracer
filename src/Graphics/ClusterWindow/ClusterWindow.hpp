/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** ClusterWindow
*/

#ifndef ClusterWindow_HPP_
    #define ClusterWindow_HPP_

    #include "Input.hpp"

namespace Graphics {
    class ClusterWindow {
        public:
            ClusterWindow(sf::Vector2f position, sf::Vector2f size, sf::Font &font);
            void handleEvent(sf::Event &event);
            void draw(sf::RenderWindow &window, sf::RenderStates states);
            void createCloseButton();
            void createInputs();
            void updateInputPositions();
            bool getInputClose();
            void setInputClose(bool close);
            void setFont(sf::Font font);

        private:
            sf::Text _title;
            sf::RectangleShape _background;
            sf::RectangleShape _close_button;
            bool _has_focus;
            bool _is_closed;
            sf::Text _close_text;
            sf::Font _font;
            std::vector<Input> _inputs;
    };
}

#endif /* !ClusterWindow_HPP_ */
