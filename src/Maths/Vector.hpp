/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vector
*/

#pragma once

namespace rtx {
    class Vector3d {
        public:
            Vector3d() = default;
            Vector3d(double x, double y, double z);
            Vector3d(const Vector3d& other);
            Vector3d(const Vector3d&& other);
            ~Vector3d() = default;

            double x() const { return this->_x; }   // Getters
            double y() const { return this->_y; }
            double z() const { return this->_z; }
            void setX(double x) { this->_x = x; } // Setters
            void setY(double y) { this->_y = y; }
            void setZ(double z) { this->_z = z; }

        protected:
        private:
            double _x = .0; // .0 so that the compiler knows it's double-sized
            double _y = .0;
            double _z = .0;
    };
}
