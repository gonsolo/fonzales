OPTIX_INCLUDE = -I/home/gonsolo/bin/NVIDIA-OptiX-SDK-7.5.0-linux64-x86_64/include
CUDA_INCLUDE = -I/usr/local/cuda-11.7/targets/x86_64-linux/include

all: compile_commands.json test
t: test
test: fonzales
	./fonzales
fonzales: main.cc
	@g++ $(OPTIX_INCLUDE) $(CUDA_INCLUDE) -Wall -Werror -Wextra -std=c++17 -o $@ $<
c: clean
clean:
	rm -rf fonzales compile_commands.json
e: edit
edit:
	vi main.cc
compile_commands.json:
	bear -- make fonzales
.PHONY: c clean e edit t test
