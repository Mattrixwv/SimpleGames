IDIR = Headers
CFLAGS = -std=c++11 -O3
LIBS = 

ODIR = ObjectFiles
LDIR = lib

_DEPS = headers.h
DEPS = $(patsubst %, $(IDIR)/%,$(_DEPS))

_OBJ = Deck.o Discard.o Foundation.o Game.o Pile.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))




$(ODIR)/%.o: SourceFiles/%.cpp Headers/%.h
	$(CXX) -c -o $@ $< $(CFLAGS)

Solitaire: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
