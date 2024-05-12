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
        } else if (key == "sphere:") {
            _primitives.push_back(std::make_shared<rtx::Sphere>());
            _currentlyParsing = PARSABLE::SPHERE;
        } else if (key == "light:") {
            _lights.push_back(Light());
            _currentlyParsing = PARSABLE::LIGHT;
        } else if (key == "plane:") {
            _primitives.push_back(std::make_shared<rtx::Plane>());
            _currentlyParsing = PARSABLE::PLANE;
        } else if (key == "cone:") {
            _primitives.push_back(std::make_shared<rtx::Cone>());
            _currentlyParsing = PARSABLE::CONE;
        } else if (key == "cylinder:") {
            _primitives.push_back(std::make_shared<rtx::Cylinder>());
            _currentlyParsing = PARSABLE::CYLINDER;
        } else if (key == "limitedCone:") {
            _primitives.push_back(std::make_shared<rtx::LimitedCone>());
            _currentlyParsing = PARSABLE::LIMITEDCONE;
        } else if (key == "limitedCylinder:") {
            _primitives.push_back(std::make_shared<rtx::LimitedCylinder>());
            _currentlyParsing = PARSABLE::LIMITEDCYLINDER;
        } else if (key == "triangle:") {
            _primitives.push_back(std::make_shared<rtx::Triangle>());
            _currentlyParsing = PARSABLE::TRIANGLE;
        }
        switch (_currentlyParsing) {
            case PARSABLE::CAMERA: parseCamera(iss, key); break;
            case PARSABLE::SPHERE: parseSphere(iss, key); break;
            case PARSABLE::LIGHT: parseLight(iss, key); break;
            case PARSABLE::PLANE: parsePlane(iss, key); break;
            case PARSABLE::CONE: parseCone(iss, key); break;
            case PARSABLE::CYLINDER: parseCylinder(iss, key); break;
            case PARSABLE::LIMITEDCONE: parseLimitedCone(iss, key); break;
            case PARSABLE::LIMITEDCYLINDER: parseLimitedCylinder(iss, key); break;
            case PARSABLE::TRIANGLE: parseTriangle(iss, key); break;
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

void rtx::Parser::parsePlane(std::istringstream &iss, std::string key)
{
    std::string equal;
    rtx::Plane& plane = dynamic_cast<rtx::Plane&>(*_primitives.back());

    if (key == "position") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, position expects 3 doubles");
        verifyEqual(equal);
        plane.setPosition(Vector3d(x, y, z));
    } else if (key == "normal") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, normal expects 3 doubles");
        verifyEqual(equal);
        plane.setNormal(Vector3d(x, y, z));
    } else if (key == "color") {
        std::uint32_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        plane.setColor(Color(r, g, b));
    }
}

void rtx::Parser::parseCone(std::istringstream &iss, std::string key)
{
    std::string equal;
    rtx::Cone& cone = dynamic_cast<rtx::Cone&>(*_primitives.back());

    if (key == "color") {
        std::uint32_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        cone.setColor(Color(r, g, b));
    } else if (key == "apex") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, apex expects 3 doubles");
        verifyEqual(equal);
        cone.setApex(Vector3d(x, y, z));
    } else if (key == "axis") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, axis expects 3 doubles");
        verifyEqual(equal);
        cone.setAxis(Vector3d(x, y, z));
    } else if (key == "theta") {
        double theta = 0;
        iss >> equal >> theta;
        if (iss.fail())
            throw ParserException("Invalid syntax, theta expects a double");
        verifyEqual(equal);
        cone.setTheta(theta);
    }
}

void rtx::Parser::parseCylinder(std::istringstream &iss, std::string key)
{
    std::string equal;
    rtx::Cylinder& cylinder = dynamic_cast<rtx::Cylinder&>(*_primitives.back());

    if (key == "color") {
        std::uint32_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        cylinder.setColor(Color(r, g, b));
    } else if (key == "position") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, position expects 3 doubles");
        verifyEqual(equal);
        cylinder.setPosition(Vector3d(x, y, z));
    } else if (key == "axis") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, axis expects 3 doubles");
        verifyEqual(equal);
        cylinder.setAxis(Vector3d(x, y, z));
    } else if (key == "radius") {
        double radius = 0;
        iss >> equal >> radius;
        if (iss.fail())
            throw ParserException("Invalid syntax, radius expects a double");
        verifyEqual(equal);
        cylinder.setRadius(radius);
    }

}

void rtx::Parser::parseLimitedCone(std::istringstream &iss, std::string key)
{
    std::string equal;
    rtx::LimitedCone& limitedCone = dynamic_cast<rtx::LimitedCone&>(*_primitives.back());

    if (key == "color") {
        std::uint32_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        limitedCone.setColor(Color(r, g, b));
    } else if (key == "apex") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, apex expects 3 doubles");
        verifyEqual(equal);
        limitedCone.setApex(Vector3d(x, y, z));
    } else if (key == "axis") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, axis expects 3 doubles");
        verifyEqual(equal);
        limitedCone.setAxis(Vector3d(x, y, z));
    } else if (key == "theta") {
        double theta = 0;
        iss >> equal >> theta;
        if (iss.fail())
            throw ParserException("Invalid syntax, theta expects a double");
        verifyEqual(equal);
        limitedCone.setTheta(theta);
    } else if (key == "height") {
        double height = 0;
        iss >> equal >> height;
        if (iss.fail())
            throw ParserException("Invalid syntax, height expects a double");
        verifyEqual(equal);
        limitedCone.setHeight(height);
    }
}

void rtx::Parser::parseLimitedCylinder(std::istringstream &iss, std::string key)
{
    std::string equal;
    rtx::LimitedCylinder& limitedCylinder = dynamic_cast<rtx::LimitedCylinder&>(*_primitives.back());

    if (key == "color") {
        std::uint32_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        limitedCylinder.setColor(Color(r, g, b));
    } else if (key == "position") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, position expects 3 doubles");
        verifyEqual(equal);
        limitedCylinder.setPosition(Vector3d(x, y, z));
    } else if (key == "axis") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, axis expects 3 doubles");
        verifyEqual(equal);
        limitedCylinder.setAxis(Vector3d(x, y, z));
    } else if (key == "radius") {
        double radius = 0;
        iss >> equal >> radius;
        if (iss.fail())
            throw ParserException("Invalid syntax, radius expects a double");
        verifyEqual(equal);
        limitedCylinder.setRadius(radius);
    } else if (key == "height") {
        double height = 0;
        iss >> equal >> height;
        if (iss.fail())
            throw ParserException("Invalid syntax, height expects a double");
        verifyEqual(equal);
        limitedCylinder.setHeight(height);
    }
}

void rtx::Parser::parseTriangle(std::istringstream &iss, std::string key)
{
    std::string equal;
    rtx::Triangle& triangle = dynamic_cast<rtx::Triangle&>(*_primitives.back());

    if (key == "color") {
        std::uint32_t r = 0, g = 0, b = 0;
        iss >> equal >> r >> g >> b;
        if (iss.fail())
            throw ParserException("Invalid syntax, color expects 3 uint8_t");
        verifyEqual(equal);
        triangle.setColor(Color(r, g, b));
    } else if (key == "vertex1") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, vertex1 expects 3 doubles");
        verifyEqual(equal);
        triangle.setP1(Vector3d(x, y, z));
    } else if (key == "vertex2") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, vertex2 expects 3 doubles");
        verifyEqual(equal);
        triangle.setP2(Vector3d(x, y, z));
    } else if (key == "vertex3") {
        double x = 0, y = 0, z = 0;
        iss >> equal >> x >> y >> z;
        if (iss.fail())
            throw ParserException("Invalid syntax, vertex3 expects 3 doubles");
        verifyEqual(equal);
        triangle.setP3(Vector3d(x, y, z));
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