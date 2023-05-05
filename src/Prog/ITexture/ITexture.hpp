/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include "Vec3.hpp"

namespace Raytracer {
class ITexture {
    public:
        virtual ~ITexture() = default;
        virtual Vec3 getColorAt(float x, float y) = 0;
    protected:
    private:
};
}

#endif /* !TEXTURE_HPP_ */
