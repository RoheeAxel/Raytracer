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

namespace Viewer {
    class ImagePpm {
    public:
        ImagePpm(const std::string filename);
        ~ImagePpm();
        void draw(sf::RenderWindow &window) const;

    private:
        int _width;
        int _height;
        sf::Image _image;
        sf::Texture _texture;
        sf::Sprite _sprite;
    };
}

#endif /* !IMAGEPPM_HPP_ */
