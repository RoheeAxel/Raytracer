/*
** EPITECH PROJECT, 2023
** final
** File description:
** LightFactory.hpp
*/

#ifndef LIGHTFACTORY_HPP_
#define LIGHTFACTORY_HPP_

#include "AFactory.hpp"
#include "ILight.hpp"

#include "AmbientLight.hpp"
#include "DirLight.hpp"
#include "PointLight.hpp"

namespace Raytracer {
    class LightFactory : public AFactory<ILight> {
        public:
            LightFactory();
            ~LightFactory() override = default;

        protected:
            std::shared_ptr<ILight> getFromBuiltin(const std::string &name, const std::string &options) override;
    };

} // Raytracer

#endif //LIGHTFACTORY_HPP_
