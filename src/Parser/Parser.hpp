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
#include "Light.hpp"

#pragma once

namespace rtx {
    class Parser {
        public:
            Parser();
            ~Parser() = default;
            void runParser(std::string file);
            std::vector<std::shared_ptr<rtx::IPrimitive>> getPrimitives() const;
            std::vector<rtx::Light> getLights() const;
            rtx::Camera getCamera() const;

            enum PARSABLE {
                NONE,
                CAMERA,
                SPHERE,
                LIGHT,
                PLANE,
                CONE,
                CYLINDER,
                LIMITEDCONE,
                LIMITEDCYLINDER,
                TRIANGLE
            };

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
            std::vector<std::shared_ptr<rtx::IPrimitive>> _primitives;
            std::vector<rtx::Light> _lights;
            rtx::Camera _camera = rtx::Camera(rtx::RenderSettings(1080, 720, M_PI_2), Vector3d(), Vector3d());
            std::string _rest;
            PARSABLE _currentlyParsing = PARSABLE::NONE;

            void verifyEqual(std::string equal);
            void parseSphere(std::istringstream &iss, std::string key);
            void parseCamera(std::istringstream& iss, std::string key);
            void parseLight(std::istringstream &iss, std::string key);
    };
}