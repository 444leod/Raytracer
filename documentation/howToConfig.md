# Guide on the config syntax for the raytracer

camera:
resolution = uint uint
position = double double double
rotation = double double double
fov = double

light:
strength = double
position = double double double

sphere:
position = double double double
color = uint8 uint8 uint8 (0 to 255)
radius = double

plane:
color = uint8 uint8 uint8 (0 to 255)
position = double double double
normal = double double double

cone:
color = uint8 uint8 uint8 (0 to 255)
apex = double double double
axis = double double double 
theta = double

cylinder:
color = uint8 uint8 uint8 (0 to 255)
position = double double double
axis = double double double
radius = double

limitedCone:
color = uint8 uint8 uint8 (0 to 255)
apex = double double double
axis = double double double
theta = double
height = double

limitedCylinder:
color = uint8 uint8 uint8 (0 to 255)
position = double double double
axis = double double double
radius = double
height = double

triangle:
color = uint8 uint8 uint8 (0 to 255)
vertex1 = double double double
vertex2 = double double double
vertex3 = double double double
