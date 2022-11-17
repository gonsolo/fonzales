OPTIX_INCLUDE 	= -I/home/gonsolo/bin/NVIDIA-OptiX-SDK-7.5.0-linux64-x86_64/include
CUDA_INCLUDE 	= $(shell pkg-config --cflags cuda-11.7)
CUDA_LIBRARY 	= $(shell pkg-config --libs cuda-11.7)
CUDART_INCLUDE 	= $(shell pkg-config --cflags cudart-11.7)
CUDART_LIBRARY 	= $(shell pkg-config --libs cudart-11.7)
INCLUDES 	= $(CUDA_INCLUDE) $(CUDART_INCLUDE) $(OPTIX_INCLUDE)
LIBRARIES 	= $(CUDA_LIBRARY) $(CUDART_LIBRARY)
WARNINGS 	= -Wall -Werror -Wextra
FLAGS 		= -std=c++17

all: compile_commands.json test
t: test
test: fonzales
	./fonzales
fonzales: main.cc
	@g++ $(INCLUDES) $(WARNINGS) $(FLAGS) -o $@ $< $(LIBRARIES)
c: clean
clean:
	rm -rf fonzales compile_commands.json
e: edit
edit:
	vi main.cc
compile_commands.json:
	bear -- make fonzales
.PHONY: c clean e edit t test
