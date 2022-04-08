###
## Makefile skeleton
## INFO0030: Projet 3
##
###

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes `pkg-config --cflags --libs gtk+-2.0`
LD=gcc
LDFLAGS=`pkg-config --cflags --libs gtk+-2.0`
DOXYGEN=doxygen

# Files
EXEC=tresor
MODULES=main_hunt.c model_hunt.c view_hunt.c controller_hunt.c
OBJECTS=main_hunt.o model_hunt.o view_hunt.o controller_hunt.o

## Rules

all: $(EXEC)

tresor: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main_hunt.o: main_hunt.c
	$(CC) -c main_hunt.c -o main_hunt.o $(CFLAGS)

model_hunt.o: model_hunt.c
	$(CC) -c model_hunt.c -o model_hunt.o $(CFLAGS)

view_hunt.o: view_hunt.c
	$(CC) -c view_hunt.c -o view_hunt.o $(CFLAGS)

controller_hunt.o: controller_hunt.c
	$(CC) -c controller_hunt.c -o controller_hunt.o $(CFLAGS)

clean:
	rm -f *.o $(EXEC) *~ Doc/html/*.html Doc/html/*.dot Doc/html/*.js Doc/html/*.png Doc/html/*.css Doc/html/search/*.html Doc/html/search/*.js Doc/html/search/*.png Doc/html/search/*.css
	rmdir -p Doc/html/search Doc/html Doc

doc:
	$(DOXYGEN) Doxyfile

archive:
	tar -zcvf projet.tar.gz *.h *.c Doxyfile Makefile