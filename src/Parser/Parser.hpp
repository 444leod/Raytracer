/*
** EPITECH PROJECT, 2024
** Parser
** File description:
** Parser
*/

#include <vector>
#include <memory>
#include <sstream>
#include <fstream>

#include "Camera.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
// #include "Light.hpp"

#pragma once

namespace rtx {
    class Parser {
        public:
            Parser();
            ~Parser() = default;
            void runParser(std::string file);
            std::vector<std::shared_ptr<rtx::IPrimitive>> getPrimitives() const;
            // std::vector<Light> getLights() const;
            std::shared_ptr<rtx::Camera> getCamera() const;


        class ParserException : public std::exception {
            public:
                ParserException(const std::string &message)
                {
                    std::stringstream ss;
                    ss << "ParserException: " << message;
                    _message = ss.str();
                }
                const char *what() const noexcept override {
                    return _message.c_str();
                }
            private:
                std::string _message;
        };

        private:
            std::vector<std::shared_ptr<IPrimitive>> _primitives;
            // std::vector<Light> _lights;
            std::shared_ptr<rtx::Camera> _camera;
            std::pair <u_int32_t, u_int32_t> _resolution; 
            std::string _rest;

            void verifyEqual(std::string equal);
            std::vector<std::string> split(std::string s, std::string delimiter);
            void parseCamera(std::istringstream& iss, std::string key, bool& foundCamera);
    };
}