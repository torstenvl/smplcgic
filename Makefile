NAME = namedisp

SRC = $(NAME).c

EXE = $(NAME).cgi

HDR = smplcgic.h

LIB = smplcgic.c

CC = cc

RFLAGS = -std=c17 -Oz

DFLAGS = -std=c17 -O0 -gfull


all: 		release

release:	$(SRC) $(LIB) $(HDR)
			$(CC) $(RFLAGS) $(SRC) $(LIB) -o $(EXE)
			strip $(EXE)

debug: 		$(SRC) $(LIB) $(HDR)
			$(CC) $(DFLAGS) $(SRC) $(LIB) -o $(EXE)

clean:
			rm -Rf core *.o *~ $(EXE) $(EXE).dSYM/
