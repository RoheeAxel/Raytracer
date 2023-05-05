/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Dammier
*/

#ifndef DAMMIER_HPP_
#define DAMMIER_HPP_

#include "ITexture.hpp"

namespace Raytracer {
    class Dammier {
        public:
            Dammier();
            ~Dammier();
            Vec3 getColorAt(float x, float y);

        protected:
        private:
    };
}

#endif /* !DAMMIER_HPP_ */
