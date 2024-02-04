CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan  -lEGL -lGLESv2
# LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

vulkan_engine: *.cpp *.hpp
	g++ $(CFLAGS) -o vulkan_engine *.cpp $(LDFLAGS)

.PHONY: test clean

test: vulkan_engine
	./vulkan_engine

clean:
	rm -f vulkan_engine 
