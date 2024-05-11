/*
** EPITECH PROJECT, 2024
** Parser
** File description:
** Parser
*/

#include "Parser.hpp"

rtx::Parser::Parser()
{
}

void rtx::Parser::runParser(std::string fileName)
{
    if (fileName.empty())
        throw ParserException("No filename set");
    std::ifstream file(fileName);
    if (!file.is_open())
        throw ParserException("Could not open file");

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;
        if (key == "camera:") {
            _currentlyParsing = PARSABLE::CAMERA;
        }
        else if (key == "sphere:") {
            _primitives.push_back(std::make_shared<rtx::Sphere>());
            _currentlyParsing = PARSABLE::SPHERE;
        }
        else if (key == "light:") {
            _lights.push_back(Light());
            _currentlyParsing = PARSABLE::LIGHT;
        }
        switch (_currentlyParsing) {
            case PARSABLE::CAMERA: parseCamera(iss, key); break;
            case PARSABLE::SPHERE: parseSphere(iss, key); break;
            case PARSABLE::LIGHT: parseLight(iss, key); break;
            default: break;
        }
    }
}

void rtx::Parser::verifyEqual(std::string equal)
{
    if (equal != "=")
        throw ParserException("Invalid syntax, expected '='");
}

void rtx::Parser::parseSphere(std::istringstream &iss, std::string key)
{
    std::string equal;
    rtx::Sphere& sphere = dynamic_cast<rtx::Sphere&>(*_primitives.back());

    if (key == "position") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, position expects 3 doubles");
        verifyEqual(equal);
        sphere.setPosition(Vector3d(x, y, z));
    } else if (key == "radius") {
        double radius = 0;
        iss >> equal >> radius;
        if (iss.fail())
            throw ParserException("Invalid syntax, radius expects a double");
        verifyEqual(equal);
        sphere.setRadius(radius);
    } else if (key == "color") {
        std::uint32_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        sphere.setColor(Color(r, g, b));
    }
}

void rtx::Parser::parseCamera(std::istringstream &iss, std::string key)
{
    std::string equal;

    if (key == "resolution") {
        int width, height;
        iss >> equal >> width >> height;
        if (iss.fail())
            throw ParserException("Invalid syntax, resolution expects 2 integers");
        verifyEqual(equal);
        _camera.setResolution(width, height);
    } else if (key == "position") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, position expects 3 doubles");
        verifyEqual(equal);
        _camera.setPosition(Vector3d(x, y, z));
    } else if (key == "rotation") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, rotation expects 3 doubles");
        verifyEqual(equal);
        _camera.setRotation(Vector3d(x, y, z));
    } else if (key == "fov") {
        double fov = 0;
        iss >> equal >> fov;
        if (iss.fail())
            throw ParserException("Invalid syntax, fov expects a double");
        verifyEqual(equal);
        _camera.setFov(fov);
    }
}

void rtx::Parser::parseLight(std::istringstream &iss, std::string key)
{
    std::string equal;
    Light& light = _lights.back();

    if (key == "position") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, position expects 3 doubles");
        verifyEqual(equal);
        light.setPosition(Vector3d(x, y, z));
    } else if (key == "strength") {
        double strength = 0;
        iss >> equal >> strength;
        if (iss.fail())
            throw ParserException("Invalid syntax, strength expects a double");
        verifyEqual(equal);
        light.setStrength(strength);
    }
}

std::vector<std::shared_ptr<rtx::IPrimitive>> rtx::Parser::getPrimitives() const
{
    return _primitives;
}

std::vector<rtx::Light> rtx::Parser::getLights() const
{
    return _lights;
}

rtx::Camera rtx::Parser::getCamera() const
{
    return _camera;
}