# Guide on the config syntax for the raytracer

camera :
resolution = uint uint
position = double double double
rotation = double double double
fov = double

lights :
ambient = double
diffuse = double
positions = double double double, double double double ..
directional = ?? (not implemented yet)

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
