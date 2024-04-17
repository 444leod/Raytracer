/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Main
*/

#include <iostream>
#include "Vector.hpp"

int main(
    [[maybe_unused]] int ac,
    [[maybe_unused]] char **av,
    [[maybe_unused]] char **env
)
{
    rtx::Vector3 v(.1, .2, .3);
    rtx::Vector3 u(1, 2, 3);

    u *= v.normalized().size();
    v *= u.size();
    std::cout << v << std::endl;
    std::cout << u << std::endl;
    return 0;
}
