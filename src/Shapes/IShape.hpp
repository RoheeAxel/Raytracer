/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** IShape
*/

#ifndef IShape_HPP_
#define IShape_HPP_

#include "Vec3.hpp"

namespace Raytracer {
class IShape {
    public:
        virtual ~IShape() = default;
        virtual Vec3 intersection() = 0;
    protected:
    private:
};

}

#endif /* !IShape_HPP_ */
