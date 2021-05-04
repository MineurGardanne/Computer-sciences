all: main_ex2 clean

pile.o: pile.c pile.h
	gcc -c pile.c

main_ex2.o: main_ex2.c pile.h
	gcc -c main_ex2.c

main_ex2: main_ex2.o pile.o
	gcc main_ex2.o pile.o -o main_ex2
clean: 
	rm -rf *.o

mrproper: clean
	rm -rf main_ex2	
