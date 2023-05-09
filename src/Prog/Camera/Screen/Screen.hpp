/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Screen
*/

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include "Vec3.hpp"
#include <utility>

namespace Raytracer {
class Screen {
    public:
        Screen() = default;
        Screen(const Raytracer::Vec3 &topLeft, const Raytracer::Vec3 &botRight, std::pair<int, int> res)
        {
            _topLeft = topLeft;
            _botRight = botRight;
            _resolution = res;
        };
        Screen(const Raytracer::Vec3 &topLeft, const Raytracer::Vec3 &botRight, int width, int height)
        {
            _topLeft = topLeft;
            _botRight = botRight;
            _resolution = std::pair<int, int>(width, height);
        };

        ~Screen() = default;
        std::pair<int, int> getResolution() const { return _resolution; };
        Raytracer::Vec3 getTopLeft() const { return _topLeft; };
        Raytracer::Vec3 getBotRight() const { return _botRight; };
        void setBotRight(const Raytracer::Vec3 &botRight) { _botRight = botRight; };
        void setTopLeft(const Raytracer::Vec3 &topLeft) { _topLeft = topLeft; };
    private:
        Raytracer::Vec3 _topLeft;
        Raytracer::Vec3 _botRight;
        std::pair<int, int> _resolution;
};
}

#endif /* !SCREEN_HPP_ */
