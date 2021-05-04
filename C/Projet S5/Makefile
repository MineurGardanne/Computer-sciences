windmill: vent.o releve.o windmill.o
	gcc vent.o releve.o windmill.o -o windmill -lm
vent.o : vent.c
	gcc -c vent.c
releve.o: releve.c vent.h
	gcc -c releve.c
windmill.o: windmill.c vent.h releve.h
	gcc -c windmill.c
clean:
	rm -rf *.o
