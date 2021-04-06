
# Very Simple Makefile #
#        Giffi         #

SOURCES := engine/*.c engine/widgets/*.c source/*.c source/entities/*.c
CFLAGS  := -std=c99
LIBS    := -lSDL2 -lSDL2_image
BUILD   := ../bin/Release/space_shooter

all:
	gcc $(CFLAGS) $(SOURCES) $(LIBS) -o $(BUILD)

clean:
	rm $(BUILD)

