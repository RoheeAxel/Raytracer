/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** Emitive
*/

#ifndef EMITIVE_HPP_
#define EMITIVE_HPP_

#include "IMaterial.hpp"
#include "Ray.hpp"
#include "ParsingUtils.hpp"
#include "ITexture.hpp"
#include "Image.hpp"

namespace Raytracer
{
class Emitive : public IMaterial {
    public:
        Emitive();
        Emitive(const Vec3& color);
        Emitive(const std::string &options);
        ~Emitive() override = default;

        Vec3 getColorAt(HitRecord record, Ray light, Vec3 lightColor) override;
        Vec3 getNewRay(HitRecord record, Vec3 light) override;
        double getReflectivity() override;
    private:
        Vec3 _base_color;
        std::shared_ptr<ITexture> _tex = nullptr;
};
}
#endif /* !EMITIVE_HPP_ */
