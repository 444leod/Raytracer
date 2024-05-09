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

std::vector<std::string> rtx::Parser::split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
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
    parseCamera(file);
    
    // std::stringstream buffer;
    // buffer << file.rdbuf();
    // _rest = buffer.str();
    // std::cout << _rest << std::endl;
    // std::vector<std::string> lines = split(_rest, "\n");
    // for (auto i : lines) std::cout << i << std::endl;
    // for (int i = 0; i < lines.size(); i++) {
    //     if (lines[i] == "camera:") {
    //         parseCamera();
    //     }
    // }
}

void rtx::Parser::verifyEqual(std::string equal)
{
    if (equal != "=")
        throw ParserException("Invalid syntax, expected '='");
}

void rtx::Parser::parseCamera(std::ifstream& file)
{
    double fov = 72.0; // Default values
    Vector3d position(0, 0, 0);
    Vector3d rotation(0, 0, 0);
    double x = 0, y = 0, z = 0;
    std::string equal;
    std::string line;
    bool foundCamera = false;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        iss >> key;
        if (key == "camera:") {
            foundCamera = true;
        } else if (foundCamera) {
            std::cout << key << std::endl;
            if (key == "resolution") {
                int width, height;
                iss >> equal >> width >> height;
                verifyEqual(equal);
                std::cout << width << " " << height << std::endl;
                // You may do something with the resolution if needed
            } else if (key == "position") {
                iss >> equal >> x >> y >> z;
                verifyEqual(equal);
                std::cout << x << " " << y << " " << z << std::endl;
                position.setX(x);
                position.setY(y);
                position.setZ(z);
                std::cout << position << std::endl;
            } else if (key == "rotation") {
                iss >> equal >> x >> y >> z;
                verifyEqual(equal);
                rotation.setX(x);
                rotation.setY(y);
                rotation.setZ(z);
            } else if (key == "fov") {
                iss >> equal >> fov;
                verifyEqual(equal);
            }
        }
    }
    if (!foundCamera)
        throw ParserException("No camera found in file");
    _camera = std::make_shared<rtx::Camera>(fov, position, rotation);
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