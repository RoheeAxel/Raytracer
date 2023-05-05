/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Image
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "ITexture.hpp"

namespace Raytracer {
    class Image : public ITexture{
        public:
            Image(const std::string &path);
            Image();
            ~Image();
            Vec3 getColorAt(float x, float y) override;

        protected:
        private:
            std::pair<int, int> _size;
            int _channels;
            std::string _path;
            unsigned char *_data;
    };
}

#endif /* !IMAGE_HPP_ */
