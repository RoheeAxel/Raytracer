/*
** EPITECH PROJECT, 2023
** final
** File description:
** Settings.hpp
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "Vec3.hpp"

namespace Raytracer {

    class Settings {
        public:
            Settings() = default;
            ~Settings() = default;

            void setWidth(int width) { _width = width; };
            void setHeight(int height) { _height = height; };
            void setPosition(Vec3 position) { _position = position; };
            void setRotation(Vec3 rotation) { _rotation = rotation; };
            void setFov(int fov) { _fov = fov; };
            void setThreads(int threads) { _threads = threads; };
            void setSamples(int samples) { _samples = samples; };
            void setMaxDepth(int max_depth) { _max_depth = max_depth; };
            void setClusters(int clusters) { _clusters = clusters; };

            int getWidth() const { return _width; };
            int getHeight() const { return _height; };
            Vec3 getPosition() const { return _position; };
            Vec3 getRotation() const { return _rotation; };
            int getFov() const { return _fov; };
            int getThreads() const { return _threads; };
            int getSamples() const { return _samples; };
            int getMaxDepth() const { return _max_depth; };
            int getClusters() const { return _clusters; };
        private:
            int _width;
            int _height;
            Vec3 _position;
            Vec3 _rotation;
            int _fov;

            int _threads;
            int _samples;
            int _max_depth;
            int _clusters;
    };

} // Raytracer

#endif //SETTINGS_HPP_
