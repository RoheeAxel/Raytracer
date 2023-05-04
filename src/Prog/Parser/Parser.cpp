/*
** EPITECH PROJECT, 2023
** final
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace Raytracer {
    Parser::Parser(const std::string &file) {
        try {
            this->_cfg.readFile(file.c_str());
        } catch (libconfig::FileIOException &e) {
            throw Config::FileNotFoundException(file);
        }
    }

    std::vector<std::shared_ptr<IShape>> Parser::parsePrimitives() {
        std::vector<std::shared_ptr<IShape>> primitives;

        if (!this->_cfg.exists("primitives"))
            throw Config::MissingGroupException("primitives");

        libconfig::Setting &primitivesGroup = this->_cfg.lookup("primitives");
        for (int i = 0; i < primitivesGroup.getLength(); i++) {
            std::string primitiveType = primitivesGroup[i].getName();
            for (int j = 0; j < primitivesGroup[i].getLength(); i++) {
                libconfig::Setting &shape = primitivesGroup[i][j];

                std::shared_ptr<IMaterial> material;
                if (shape.exists("material")) {
                    libconfig::Setting &mat = shape["material"];
                    std::string type = mat["type"];
                    mat.remove("type");
                    std::string options = convertGroup(mat);
                    try {
                        material = this->_materialFactory.get(type, options);
                    } catch (FactoryNotFoundException &e) {
                        std::cerr << e.what() << std::endl;
                        continue;
                    }
                    shape.remove("material");
                }
                std::string options = convertGroup(shape);
                try {
                    std::shared_ptr<IShape> primitive = this->_shapeFactory.get(primitiveType, options);
                    primitive->setMaterial(material);
                    primitives.push_back(primitive);
                } catch (FactoryNotFoundException &e) {
                    std::cerr << e.what() << std::endl;
                    continue;
                }
            }
        }

        return primitives;
    }

    std::vector<std::shared_ptr<ILight>> Parser::parseLights() {
        std::vector<std::shared_ptr<ILight>> lights;

        if (!this->_cfg.exists("lights"))
            throw Config::MissingGroupException("lights");

        libconfig::Setting &lightsGroup = this->_cfg.lookup("lights");
        for (int i = 0; i < lightsGroup.getLength(); i++) {
            std::string lightType = lightsGroup[i].getName();
            for (int j = 0; j < lightsGroup[i].getLength(); j++) {
                libconfig::Setting &light = lightsGroup[i][j];
                std::string options = convertGroup(light);
                try {
                    std::shared_ptr<ILight> lightPtr = this->_lightFactory.get(lightType, options);
                    lights.push_back(lightPtr);
                } catch (FactoryNotFoundException &e) {
                    std::cerr << e.what() << std::endl;
                    continue;
                }
            }
        }

        return lights;
    }

    std::string Parser::convertGroup(libconfig::Setting &array, bool isGroup) {
        std::stringstream ss;

        for (int k = 0; k < array.getLength(); k++) {
            if (!isGroup)
                ss << array[k].getName() << "=";
            if (array[k].getType() == libconfig::Setting::Type::TypeInt) {
                int value = array[k];
                ss << value;
            } else if (array[k].getType() == libconfig::Setting::Type::TypeFloat) {
                double value = array[k];
                ss << value;
            } else if (array[k].getType() == libconfig::Setting::Type::TypeString) {
                std::string value = array[k];
                ss << value;
            } else if (array[k].getType() == libconfig::Setting::Type::TypeGroup) {
                ss << "{";
                ss << this->convertGroup(array[k], true);
                ss << "}";
            }
            if (k != array.getLength() - 1)
                ss << ", ";
        }
        return ss.str();
    }

} // Raytracer