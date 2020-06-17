

bite: main.o bite.o tokenizer.o programizer.o program.o line.o bluePrint.o
	g++ main.o bite.o tokenizer.o programizer.o program.o line.o bluePrint.o -o bite

main.o: main.cpp
	g++ -c main.cpp

bite.o: bite.cpp bite.h
	g++ -c bite.cpp

tokenizer.o: tokenizer.cpp tokenizer.h
	g++ -c tokenizer.cpp

programizer.o: programizer.cpp programizer.h
	g++ -c programizer.cpp

program.o: program.cpp program.h
	g++ -c programizer.cpp

line.o: line.cpp line.h
	g++ -c line.cpp

bluePrint.o: bluePrint.cpp bluePrint.h line.h program.h
	g++ -c blueprint.cpp

clean:
	rm *.o
