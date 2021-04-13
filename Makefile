
# Very Simple Makefile #
#        Giffi         #

SOURCES := game/engine/*.c game/engine/widgets/*.c game/source/*.c game/source/entities/*.c
CFLAGS  := -std=c99 -O2
LIBS    := -lSDL2 -lSDL2_image
BUILD   := bin/Release/space_shooter

all:
	gcc $(CFLAGS) $(SOURCES) $(LIBS) -o $(BUILD)

clean:
	rm $(BUILD)

