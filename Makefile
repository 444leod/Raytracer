##
## EPITECH PROJECT, 2024
## PROJECT_NAME
## File description:
## Makefile
##

NAME	:= raytracer

SRC	:=	src/Main.cpp	\
		src/Maths/Ray.cpp	\
		src/Maths/Delta.cpp \
		src/Parser/Parser.cpp	\
		src/Parser/IPrimitiveFactory.cpp	\
		src/Rendering/Image.cpp	\
		src/Rendering/Camera.cpp	\
		src/Rendering/Scene.cpp	\
		src/Primitives/Sphere.cpp	\
		src/Primitives/Triangle.cpp	\
		src/Primitives/Plane.cpp	\
		src/Primitives/Cone.cpp \
		src/Primitives/Cylinder.cpp \
		src/Primitives/LimitedCylinder.cpp \
		src/Primitives/LimitedCone.cpp \
		src/Lighting/PointLight.cpp	\
		src/Lighting/DirectionalLight.cpp	\
		src/Lighting/AmbiantLight.cpp	\

OBJ	:=	$(SRC:.cpp=.o)

CC	:=	g++

CXXFLAGS	+=	-Wall -Wextra -Werror -Wpedantic
CXXFLAGS	+=	-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS 	+=	-I./src/Maths -I./src/Parser -I./src/Rendering\
	-I./src/Primitives -I./src/Lighting

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

tests_run: all

run: all

init: install-hooks install-mango

install-hooks:
	@cp .githooks/commit-msg .git/hooks/commit-msg
	@chmod +x .git/hooks/commit-msg
	@echo "Hooks installed."

install-mango:
	@chmod +x ./init/install-mango.sh
	@./init/install-mango.sh

.PHONY: all clean fclean re
.SILENT: run
