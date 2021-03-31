#  Very Simple MakeFile	#
#      Does the Job		#

SOURCES := ./*.c engine/*.c source/*.c source/entitys/*.c
CFLAGS := -O2 -std=c99 -lSDL2 -lSDL2_image


all:
	gcc $(CFLAGS) $(SOURCES) -o game

clean:
	rm ./game