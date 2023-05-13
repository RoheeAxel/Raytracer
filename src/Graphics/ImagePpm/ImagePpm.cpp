/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** ImagePpm
*/

#include "ImagePpm.hpp"

Viewer::ImagePpm::ImagePpm()
{
    this->_image.create(0, 0);
}

Viewer::ImagePpm::~ImagePpm()
{
}

void Viewer::ImagePpm::run(const std::string filename, sf::RenderWindow &window, std::string nbThreads)
{
    std::ifstream file(filename, std::ios::binary);
    std::string format;
    int maxColor;

    if (!file) {
        this->configureRaytracer(window, filename, nbThreads);
        return;
    }
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

void Viewer::ImagePpm::configureRaytracer(sf::RenderWindow &window, std::string file, std::string nbThreads)
{
    this->_raytracer.~Raytracer();
    this->_raytracer.run(file);
    this->_raytracer.render(nbThreads);
    this->run(this->_raytracer.getOutpoutFilename(), window, nbThreads);
}

void Viewer::ImagePpm::draw(sf::RenderWindow &window, std::string path)
{
    if (path == "")
        return;
    window.draw(this->_sprite);
}

void Viewer::ImagePpm::downloadImage(std::string nameFile, std::string extension)
{
    sf::Image image = this->_texture.copyToImage();
    image.saveToFile(nameFile + "." + extension);
}
