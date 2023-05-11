/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** ImagePpm
*/

#ifndef IMAGEPPM_HPP_
    #define IMAGEPPM_HPP_

    #include <SFML/Graphics.hpp>
    #include <fstream>
    #include <string>
    #include <iostream>
    #include "Raytracer.hpp"

namespace Viewer {
    class ImagePpm {
    public:
        ImagePpm();
        ~ImagePpm();
        void run(const std::string filename, sf::RenderWindow &window, std::string nbThreads);
        void configureRaytracer(sf::RenderWindow &window, std::string file, std::string nbThread);
        void draw(sf::RenderWindow &window, std::string path);
        void downloadImage(std::string nameFile, std::string extension);

    private:
        int _width;
        int _height;
        sf::Image _image;
        sf::Texture _texture;
        sf::Sprite _sprite;
        Raytracer::Raytracer _raytracer;
    };
}

#endif /* !IMAGEPPM_HPP_ */
