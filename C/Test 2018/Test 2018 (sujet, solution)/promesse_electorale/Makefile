all: main_ex1 clean

main_ex1: main_ex1.o graph.o tas.o
	gcc main_ex1.o graph.o tas.o -o main_ex1

tas.o: tas.c tas.h
	gcc -c tas.c

graph.o: graph.c graph.h tas.h
	gcc -c graph.c

main_ex1.o: main_ex1.c graph.h
	gcc -c main_ex1.c

clean: 
	rm -rf *.o

mrproper: clean
	rm -rf main_ex1
