/*
** EPITECH PROJECT, 2023
** final
** File description:
** MaterialFactory.hpp
*/

#ifndef MATERIALFACTORY_HPP_
#define MATERIALFACTORY_HPP_

#include "AFactory.hpp"
#include "IMaterial.hpp"

#include "Emitive.hpp"
#include "Glass.hpp"
#include "Lambertian.hpp"
#include "Normal.hpp"
#include "Plastic.hpp"

namespace Raytracer {
    class MaterialFactory : public AFactory<IMaterial> {
        public:
            MaterialFactory();
            ~MaterialFactory() override = default;

        protected:
            std::shared_ptr<IMaterial> getFromBuiltin(const std::string &name, const std::string &options) override;
    };
} // Raytracer
#endif //MATERIALFACTORY_HPP_
