IDIR = Headers
CFLAGS = -std=c++11 -O3
LIBS = 

LDIR = lib
SRCDIR = 



Solitaire: main.cpp SourceFiles/Game.cpp
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(IDIR)/*~ 
