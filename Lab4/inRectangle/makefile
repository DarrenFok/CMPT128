r: inRectangle.o main.o
		gcc -o r inRectangle.o main.o

inRectangle.o: inRectangle.c inRectangle.h
		gcc -Wall -c inRectangle.c inRectangle.h

main.o: main.c inRectangle.h
		gcc -Wall -c main.c inRectangle.h

clean:
		rm -f r *.o