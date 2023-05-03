/*
** EPITECH PROJECT, 2023
** final
** File description:
** Exception.hpp
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

namespace Raytracer {
    class Exception : public std::exception {
        public:
            Exception(const std::string &msg) : _msg(msg) {}
            ~Exception() override = default;

            const char *what() const noexcept override {
                return _msg.c_str();
            }
        private:
            std::string _msg;
    };

    class FactoryNotFoundException : public Exception {
        public:
            FactoryNotFoundException(const std::string &msg) : Exception(msg) {}
            ~FactoryNotFoundException() override = default;
    };

    class InvalidPluginException : public Exception {
        public:
            InvalidPluginException(const std::string &msg) : Exception(msg) {}
            ~InvalidPluginException() override = default;
    };
}

#endif //EXCEPTION_HPP_
