OPTIX_INCLUDE 	= -I/home/gonsolo/bin/NVIDIA-OptiX-SDK-7.5.0-linux64-x86_64/include
CUDA_INCLUDE 	= $(shell pkg-config --cflags cudart-11.7)
CUDA_LIBRARY 	= $(shell pkg-config --libs cudart-11.7)

all: compile_commands.json test
t: test
test: fonzales
	./fonzales
fonzales: main.cc
	@g++ $(OPTIX_INCLUDE) $(CUDA_INCLUDE) -Wall -Werror -Wextra -std=c++17 -o $@ $< $(CUDA_LIBRARY)
c: clean
clean:
	rm -rf fonzales compile_commands.json
e: edit
edit:
	vi main.cc
compile_commands.json:
	bear -- make fonzales
.PHONY: c clean e edit t test
