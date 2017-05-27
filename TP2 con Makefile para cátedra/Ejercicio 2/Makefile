TARGETS= ej2
FLAGS= -std=c++11
make: $(TARGETS)

ej2: Ej2.cpp
	g++ $^ -o $@ $(FLAGS)

clean:
	rm -f *.o *~ $(TARGETS)