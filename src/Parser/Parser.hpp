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
#include "PointLight.hpp"
#include "DirectionalLight.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "LimitedCone.hpp"
#include "LimitedCylinder.hpp"
#include "Triangle.hpp"

#pragma once

namespace rtx {
    class Parser {
        public:
            Parser();
            ~Parser() = default;
            void runParser(std::string file);
            std::vector<std::shared_ptr<rtx::IPrimitive>> getPrimitives() const;
            std::vector<std::shared_ptr<rtx::ILight>> getLights() const;
            rtx::Camera getCamera() const;

            enum PARSABLE {
                NONE,
                SPHERE,
                CAMERA,
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
            std::vector<std::shared_ptr<rtx::ILight>> _lights;
            rtx::Camera _camera = rtx::Camera(rtx::RenderSettings(1080, 720, M_PI_2), Vector3d(), Vector3d());
            std::string _rest;
            PARSABLE _currentlyParsing = PARSABLE::NONE;

            void verifyEqual(std::string equal);
            void parseSphere(std::istringstream &iss, std::string key);
            void parseCamera(std::istringstream& iss, std::string key);
            void parsePointLight(std::istringstream &iss, std::string key);
            void parseDirectionalLight(std::istringstream &iss, std::string key);
            void parsePlane(std::istringstream &iss, std::string key);
            void parseCone(std::istringstream &iss, std::string key);
            void parseCylinder(std::istringstream &iss, std::string key);
            void parseLimitedCone(std::istringstream &iss, std::string key);
            void parseLimitedCylinder(std::istringstream &iss, std::string key);
            void parseTriangle(std::istringstream &iss, std::string key);
    };
}