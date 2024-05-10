# Guide on the config syntax for the raytracer

camera:
resolution = uint uint
position = double double double
rotation = double double double
fov = double

light:
strength = double
positions = double double double

sphere:
position = double double double
rgb = uint8 uint8 uint8 (0 to 255)
radius = double

plane:
position = double double double
rgb = uint8 uint8 uint8 (0 to 255)
normal = double double double

# Default values:
camera:
