
q3: Quiz3.o testDriver.o
	gcc -o q3 Quiz3.o testDriver.o

Quiz3.o: Quiz3.c Quiz3.h
	gcc -Wall -c Quiz3.c Quiz3.h

testDriver.o: testDriver.c Quiz3.h
	gcc -Wall -c testDriver.c Quiz3.h

clean:
	rm -f q3 *.o *.out Quiz3.h.gch
