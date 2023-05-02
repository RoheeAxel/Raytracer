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
    #include "Input.hpp"
    #include "ClusterWindow.hpp"

namespace Graphics {
    class MainWindow {
    public:
        MainWindow(sf::Vector2f size, std::string title);
        ~MainWindow();
        void addButton(Button button);
        void run();
        void fillPathPpm();
        void createThreadWindow();
        void createClusterWindow();
        void createSettingsWindow();

    private:
        sf::RenderWindow _window;
        sf::RectangleShape _rectangle;
        std::vector<Button> _buttons;
        sf::Sprite _imageSprite;
        sf::Vector2f _size;
        std::string _path;
        sf::Font _font;
        ClusterWindow _clusterWindow;
        Viewer::ImagePpm _imagePpm;
    };
}

#endif /* !MAINWINDOW_HPP_ */
