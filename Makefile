CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -lwayland-client -lwayland-cursor -lwayland-egl -lEGL -lGLESv2

vulkan_engine: *.cpp *.hpp
	g++ $(CFLAGS) -o vulkan_engine *.cpp $(LDFLAGS)

.PHONY: test clean

test: vulkan_engine
	./vulkan_engine

clean:
	rm -f vulkan_engine 