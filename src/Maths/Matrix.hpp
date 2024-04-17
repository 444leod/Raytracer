/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Matrix
*/

#pragma once

#include <array>

namespace rtx {
    template<typename T, unsigned int M, unsigned int N>
    class Matrix {
        public:
            Matrix() = default;
            Matrix(T matrix[M][N])
            {
                for (unsigned m = 0; m < M; m++)
                    for (unsigned n = 0; n < N; n++)
                        this->_matrix[m][n] = matrix[m][n];
            }
            ~Matrix() = default;

            std::array<std::array<T, N>, M> raw() const { return this->_matrix; }
            void set(T value, unsigned int m, unsigned int n) { this->_matrix[m][n] = value; }

            template<unsigned int P>
            Matrix<T, M, P> operator*(const Matrix<T, N, P>& matrix)
            {
                Matrix<T, M, P> result;

                for (unsigned m = 0; m < M; m++) {
                    for (unsigned p = 0; p < P; p++) {
                        T value = 0;
                        for (unsigned n = 0; n < N; n++) {
                            value += this->_matrix[m][n] * matrix.raw()[n][p];
                        }
                        result.set(value, m, p);
                    }
                }
                return result;
            }

        protected:
        private:
            std::array<std::array<T, N>, M> _matrix;
    };
}

template<typename T, unsigned int M, unsigned int N>
std::ostream& operator<<(std::ostream& stream, const rtx::Matrix<T, M, N>& matrix)
{
    stream << "[ ";
    for (unsigned m = 0; m < M; m++) {
        stream << "[ ";
        for (unsigned n = 0; n < N; n++)
            stream << matrix.raw()[m][n] << (n == N - 1 ? "" : ", ");
        stream << " ], ";
    }
    stream << "]";
    return stream;
}
