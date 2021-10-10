#OBJS specifies which files to compile as part of the project
OBJS = G_box.cpp G_collisions.cpp G_dot.cpp G_game_object.cpp G_renderer_win.cpp G_sound.cpp G_text.cpp G_texture.cpp G_timer.cpp G_window.cpp 
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = sdl2-config
#-lGL -lGLU -lglut

#OBJ_NAME specifies the name of our executable
OBJ_NAME = stack_attack

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS)  $(LINKER_FLAGS) -o $(OBJ_NAME)
