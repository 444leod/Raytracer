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
    bool foundCamera = false;
    bool foundSphere = false;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;
        if (key == "camera:") {
            foundCamera = true;
        } else if (foundCamera) {
            parseCamera(iss, key, foundCamera);
        } else if (key == "sphere:") {
            foundSphere = true;
            addNewSphere();
        } else if (foundSphere) {
            parseSphere(iss, key, foundSphere);
        }
    }
}

void rtx::Parser::verifyEqual(std::string equal)
{
    if (equal != "=")
        throw ParserException("Invalid syntax, expected '='");
}

void rtx::Parser::addNewSphere()
{
    _primitives.push_back(std::make_shared<rtx::Sphere>());
}

void rtx::Parser::parseSphere(std::istringstream &iss, std::string key, bool &foundSphere)
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
        u_int8_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        sphere.setColor(Color(r, g, b));
    } else {
        foundSphere = false;
    }
}

void rtx::Parser::parseCamera(std::istringstream &iss, std::string key, bool &foundCamera)
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
    } else {
        foundCamera = false;
    }
}

std::vector<std::shared_ptr<rtx::IPrimitive>> rtx::Parser::getPrimitives() const
{
    return _primitives;
}

/*
std::vector<Light> getLights() const
{
    return _lights;
}
*/

rtx::Camera rtx::Parser::getCamera() const
{
    return _camera;
}