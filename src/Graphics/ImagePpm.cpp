/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** ImagePpm
*/

#include "ImagePpm.hpp"

Viewer::ImagePpm::ImagePpm(const std::string filename)
{
    std::ifstream file(filename, std::ios::binary);
    std::string format;
    int maxColor;

    if (!file)
        return;
    std::getline(file, format);
    file >> this->_width >> this->_height >> maxColor;
    file.get();
    this->_image.create(this->_width, this->_height);
    std::vector<sf::Color> pixelData(this->_width * this->_height);
    for (int i = 0; i < this->_height; i++) {
        for (int j = 0; j < this->_width; j++) {
            sf::Color color;
            file.read(reinterpret_cast<char*>(&color.r), 1);
            file.read(reinterpret_cast<char*>(&color.g), 1);
            file.read(reinterpret_cast<char*>(&color.b), 1);
            pixelData[i * this->_width + j] = color;
        }
    }
    for (int i = 0; i < this->_height; i++)
        for (int j = 0; j < this->_width; j++)
            this->_image.setPixel(j, i, pixelData[i * this->_width + j]);
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
