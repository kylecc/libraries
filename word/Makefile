word: main.o word.o check.o
	g++ -Wall -Werror -o word main.o word.o check.o

main.o: main.cc word.h check.h
	g++ -c -Wall -Werror main.cc

word.o: word.cc word.h check.h
	g++ -c -Wall -Werror word.cc

check.o: check.cc check.h
	g++ -c -Wall -Werror check.cc

clean:
	rm -rf *~ *.o word
