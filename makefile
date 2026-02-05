gof : main.o game.o binary.o
	gcc -o gof main.o game.o binary.o

#gof_testing : tests.o game.o binary.o 
#	gcc -o gof_testing tests.o game.o binary.o

main.o : main.c binary.h game.h
	gcc -c main.c

game.o : game.c game.h binary.h
	gcc -c game.c

binary.o : binary.c binary.h
	gcc -c binary.c

clean : 
	rm gof gof_testing *.o