# Raytracer

## Introduction

This project is a raytracer, a program that simulates image rendering by tracing rays of light through a virtual scene. The raytracer implemented here supports various geometric shapes, including spheres, cones, cylinders, and triangles.

## Compilation

The program can be compiled using a Makefile.
Rule are make to compile
    make clean to remove compilation object
    make fclean to clean all the project
    and make re to recompile entirely the project

## Usage 
Launch the program by using 
./raytracer [path to configuration file]

## Configuration File
Configuration file explication are in the HowToConfig File

## Load a New Scene from a file
Press the `N` key to Load a new scene.
A prompt appear in the terminal to write the name of the input file wich represent the new scene

## Controls

- Use the `Z`, `Q`, `S`, and `D` keys to move the camera forwards, leftwards, backwards, and rightwards, respectively.
- Use the left and right arrow keys to change the field of view.
- Use the `Space` key to move upwards and `Left Shift` to move downwards.
- Use the `R` key to reload a scene

## Light
### Ambiant Light

Take a strength wich is the intensity of the light give a minimum light to any point of the scene

### Directional Light

Take a strength and a direction to set a light that will illuminate a whole line

### Point Light

Take a strength and a position to set a light at the given position that will launch many ray from the point

## Geometric Shapes

### Sphere

A sphere is defined by its position in space and radius. The intersection between a ray and a sphere is calculated using the quadratic equation.

### Cone

A cone is defined by its apex, axis, and an angle describing the cone's opening. The intersection between a ray and a cone is calculated by solving a quadratic equation.

### Limited Cone

A limited cone is similar to a regular cone but with a restricted height, effectively creating a truncated cone. It is defined by its apex, axis, angle describing the cone's opening, and height. The intersection between a ray and a limited cone is calculated by solving a quadratic equation, similar to the standard cone. However, after determining the intersection point, an additional check is performed to ensure that the intersection lies within the height limits of the cone.

### Cylinder

A cylinder is defined by its position, axis, and radius. The intersection between a ray and a cylinder is also calculated by solving a quadratic equation.

### Limited Cylinder

A limited cylinder is similar to a regular cylinder but with a restricted height, creating a cylinder with capped ends. It is defined by its position, axis, radius, and height. The intersection between a ray and a limited cylinder is also calculated by solving a quadratic equation, similar to the standard cylinder. After finding the intersection point, an additional check is performed to ensure that the intersection lies within the height limits of the cylinder. This is done by calculating the projection of the intersection point onto the axis of the cylinder and verifying that it falls within the range of 0 to the height of the cylinder.

### Triangle

A triangle is defined by three points in space. The intersection between a ray and a triangle is calculated using the Möller–Trumbore method, which determines if a ray intersects the triangle's plane and then checks if the intersection point lies inside the triangle.

## Scene Display

The scene is displayed using the SFML graphics library.

## Saving

Press the `P` key to save the image to a PPM file.
A prompt appear in the terminal to write the name of the output file
Please note that saving only works if all points of the image are loaded.


## Participants

The project was developed by Thibault Longueppe, Isaac Levy-Piquet, Leo Dumont, and Elliot Alladaye.

