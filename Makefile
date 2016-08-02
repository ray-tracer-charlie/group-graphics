src = $(wildcard main.cpp)
obj = $(src:.cpp=.o)


LIBRARY_PATHS =

OS = $(shell uname)
ifeq ($(OS),Darwin)
	LDFLAGS = -framework Carbon -framework OpenGL -framework GLUT
	#deleted -lst
else
	LDFLAGS = -lGL -lGLEW -lglut -lGLU -lglfw -lglee -lassimp -lSOIL
	#deleted -lst, added -lassimp
	CXXFLAGS = -std=c++11
endif

main: $(obj)
	cd build && cmake ../.
	g++ -g -o $@ $^ $(LIBRARY_PATHS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) main


