/*
** EPITECH PROJECT, 2024
** Parser
** File description:
** Parser
*/

#include "Parser.hpp"

rtx::Parser::Parser()
{
    _camera = std::make_shared<rtx::Camera>();
}

std::vector<std::string> rtx::Parser::split(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
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
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;
        if (key == "camera:") {
            foundCamera = true;
        } else if (foundCamera) {
            parseCamera(iss, key, foundCamera);
        }
    }
}

void rtx::Parser::verifyEqual(std::string equal)
{
    if (equal != "=")
        throw ParserException("Invalid syntax, expected '='");
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
    }
    else if (key == "position") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, position expects 3 doubles");
        verifyEqual(equal);
        _camera->setPosition(Vector3d(x, y, z));
    } else if (key == "rotation") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, rotation expects 3 doubles");
        verifyEqual(equal);
        _camera->setRotation(Vector3d(x, y, z));
    } else if (key == "fov") {
        double fov = 0;
        iss >> equal >> fov;
        if (iss.fail())
            throw ParserException("Invalid syntax, fov expects a double");
        verifyEqual(equal);
        _camera->setFov(fov);
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

std::shared_ptr<rtx::Camera> rtx::Parser::getCamera() const
{
    return _camera;
}