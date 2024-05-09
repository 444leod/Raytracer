/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Delta
*/

#pragma once

#include <optional>
#include <utility>

namespace rtx {
    class Delta {
        public:
            Delta(double a, double b, double c);

            std::optional<std::pair<double, double>> solve() const;
            ~Delta() = default;

        protected:
        private:
            double _a;
            double _b;
            double _c;
    };
}
