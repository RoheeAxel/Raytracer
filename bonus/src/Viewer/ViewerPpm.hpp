/*
** EPITECH PROJECT, 2023
** bonus
** File description:
** ViewerPpm
*/

#ifndef VIEWERPPM_HPP_
    #define VIEWERPPM_HPP_

    #include "ImagePpm.hpp"

namespace Viewer {
    class ViewerPpm {
    public:
        ViewerPpm(const std::string &filename);
        ~ViewerPpm();
        void getSize(std::string filename);
        void run();

    private:
        ImagePpm _image;
        int _width;
        int _height;
        sf::RenderWindow _window;
    };
}

#endif /* !VIEWERPPM_HPP_ */
