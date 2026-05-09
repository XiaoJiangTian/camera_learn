CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGETS = camera_demo

.PHONY: all clean

all: $(TARGETS)

camera_demo: camera_demo.c camera_driver.c snapdragon_camera.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS)
