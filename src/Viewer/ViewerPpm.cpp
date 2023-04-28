/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** ViewerPpm
*/

#include "ViewerPpm.hpp"

Viewer::ViewerPpm::ViewerPpm(const std::string &filename)
    : _image(filename), _width(0), _height(0)
{
    this->getSize(filename);
    this->_window.create(sf::VideoMode(this->_width, this->_height), "Viewer PPM image");
}

Viewer::ViewerPpm::~ViewerPpm()
{
}

void Viewer::ViewerPpm::getSize(std::string filename)
{
    std::ifstream file(filename);
    std::string format;

    if (!file) {
        std::cerr << "Failed to open file." << std::endl;
        throw std::exception();
    }
    file >> format >> this->_width >> this->_height;
    file.close();
}

void Viewer::ViewerPpm::run()
{
    sf::Event event;

    while (this->_window.isOpen()) {
        while (this->_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->_window.close();
        }
        this->_window.clear();
        this->_image.draw(this->_window);
        this->_window.display();
    }
}
