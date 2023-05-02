/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** ImagePpm
*/

#include "ImagePpm.hpp"

Viewer::ImagePpm::ImagePpm(const std::string filename)
{
    if (filename == "")
        return;
    std::ifstream file(filename);
    sf::Color color;
    std::string format;
    int maxColor;
    float r, g, b;

    if (!file) {
        std::cerr << "Failed to open file." << std::endl;
        throw std::exception();
    }
    file >> format >> this->_width >> this->_height >> maxColor;
    this->_image.create(this->_width, this->_height);
    for (int i = 0; i < this->_height; i++) {
        for (int j = 0; j < this->_width; j++) {
            file >> r >> g >> b;
            color.r = static_cast<sf::Uint8>(r / maxColor * 255);
            color.g = static_cast<sf::Uint8>(g / maxColor * 255);
            color.b = static_cast<sf::Uint8>(b / maxColor * 255);
            this->_image.setPixel(j, i, color);
        }
    }
    this->_texture.loadFromImage(this->_image);
    this->_sprite.setTexture(this->_texture);
}


Viewer::ImagePpm::~ImagePpm()
{
}

void Viewer::ImagePpm::draw(sf::RenderWindow &window)
{
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u imageSize = this->_texture.getSize();
    float x = (windowSize.x - imageSize.x) / 2.0f;
    float y = (windowSize.y - imageSize.y) / 2.0f;
    this->_sprite.setPosition(x, y);
    window.draw(this->_sprite);
}
