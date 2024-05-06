/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vector
*/

#pragma once

#include <cmath>
#include <iostream>

namespace rtx {
    template<typename T>
    class Vector3 {
        public:
            Vector3() = default;
            Vector3(T x, T y, T z) : _x(x), _y(y), _z(z) {}
            Vector3(const Vector3& other) : _x(x), _y(y), _z(z) {}
            Vector3(const Vector3&& other) : _x(x), _y(y), _z(z) {}
            ~Vector3() = default;

            T x() const { return this->_x; }   // Getters
            T y() const { return this->_y; }
            T z() const { return this->_z; }
            void setX(T x) { this->_x = x; }   // Setters
            void setY(T y) { this->_y = y; }
            void setZ(T z) { this->_z = z; }

            // Operators
            Vector3<T> operator+(const Vector3<T>& other) const {
                return Vector3<T>(this->_x + other._x, this->_y + other._y, this->_z + other._z); }
            Vector3<T> operator-(const Vector3<T>& other) const {
                return Vector3<T>(this->_x - other._x, this->_y - other._y, this->_z - other._z); }
            Vector3<T> operator*(const Vector3<T>& other) const {
                return Vector3<T>(this->_x * other._x, this->_y * other._y, this->_z * other._z); }
            Vector3<T> operator/(const Vector3<T>& other) const {
                return Vector3<T>(this->_x / other._x, this->_y / other._y, this->_z / other._z); }

            template<typename U>
            Vector3<T> operator*(U factor) const {
                return Vector3<T>(this->_x * factor, this->_y * factor, this->_z * factor); }
            template<typename U>
            Vector3<T> operator/(U factor) const {
                return Vector3<T>(this->_x / factor, this->_y / factor, this->_z / factor); }

            //More operators
            void operator+=(const Vector3<T>& other) {
                this->_x += other._x; this->_y += other._y; this->_z += other._z; }
            void operator-=(const Vector3<T>& other) {
                this->_x -= other._x; this->_y -= other._y; this->_z -= other._z; }
            void operator*=(const Vector3<T>& other) {
                this->_x *= other._x; this->_y *= other._y; this->_z *= other._z; }
            void operator/=(const Vector3<T>& other) {
                this->_x /= other._x; this->_y /= other._y; this->_z /= other._z; }

            template<typename U>
            void operator*=(U factor) {
                this->_x *= factor; this->_y *= factor; this->_z *= factor; }
            template<typename U>
            void operator/=(U factor) {
                this->_x /= factor; this->_y /= factor; this->_z /= factor; }

            // Gets the length of the vector
            double size() const {
                return std::sqrt(this->_x * this->_x + this->_y * this->_y + this->_z * this->_z); }

            // Normalizes the vector
            Vector3 normalized() const {
                return *this / this->size(); }

            // Normalizes a vector
            template<typename U>
            static Vector3 normalize(const Vector3<U>& vector) {
                return vector / vector.size(); }

            // Computes the dot product with another vector
            double dot(const Vector3& vector) const {
                return this->_x * vector._x + this->_y * vector._y + this->_z * vector._z; }

            // Computes the dot product of two vectors
            static double dot(const Vector3& a, const Vector3& b) {
                return a._x * b._x + a._y * b._y + a._z * b._z; }


        protected:
        private:
            T _x = .0; // .0 so that the compiler knows it's double-sized
            T _y = .0;
            T _z = .0;
    };
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const rtx::Vector3<T>& vector)
{
    stream << "(" << vector.x() << ", " << vector.y() << ", " << vector.z() << ")";
    return stream;
}
