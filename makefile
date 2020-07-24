transfer_build.out: main.o utility.o Process.o checksum.o
	g++ -o transfer_build main.o utility.o Process.o checksum.o

main.o: main.cpp tansfer.h
	g++ -c main.cpp

utility.o: utility.cpp utility.h
	g++ -c utility.cpp

Process.o: Process.cpp Process.h
	g++ -c Process.cpp

checksum.o: checksum.cpp checksum.h
	g++ -c checksum.cpp