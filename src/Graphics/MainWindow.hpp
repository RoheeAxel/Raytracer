/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** MainWindow
*/

#ifndef MAINWINDOW_HPP_
    #define MAINWINDOW_HPP_

    #include <iostream>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include "Button.hpp"
    #include "ImagePpm.hpp"

namespace Graphics {

    class MainWindow {
    public:
        MainWindow(sf::Vector2f size, std::string title);
        ~MainWindow();
        void addButton(Button button);
        void run();

    private:
        sf::RenderWindow m_window;
        sf::RectangleShape m_rectangle;
        std::vector<Button> m_buttons;
        sf::Sprite m_imageSprite;
        sf::Vector2f m_size;
    };
}

#endif /* !MAINWINDOW_HPP_ */
