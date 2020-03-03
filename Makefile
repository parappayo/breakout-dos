CC=../dm/bin/dmc
INC=
LIB=
CFLAGS=-mc

BIN=breakout.exe
SRC=$(wildcard *.c)
HDR=$(wildcard *.h)

all: $(BIN)

clean:
	rm *.obj

# one-shot build rule, will rebuild all for any change
$(BIN): $(SRC) $(HDR)
	$(CC) $(SRC) -o $(BIN) $(INC) $(LIB) $(CFLAGS)
