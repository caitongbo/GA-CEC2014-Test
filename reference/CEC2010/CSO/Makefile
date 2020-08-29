CC=mpicxx
LDFLAGS= -Wl,-rpath
CXXFLAGS=-Wall -pedantic  -O4
#CXXFLAGS=-Wall -pedantic  -ggdb -DDEBUG

all: CSO CSO_1 CSO_2 CSO_3 CSO_4


OBJECTS=Self_Define_Functions.o ./CEC2010/Benchmarks.o ./CEC2010/F1.o ./CEC2010/F2.o ./CEC2010/F3.o ./CEC2010/F4.o ./CEC2010/F5.o ./CEC2010/F6.o ./CEC2010/F7.o ./CEC2010/F8.o ./CEC2010/F9.o ./CEC2010/F10.o\
./CEC2010/F11.o ./CEC2010/F12.o ./CEC2010/F13.o ./CEC2010/F14.o ./CEC2010/F15.o ./CEC2010/F16.o ./CEC2010/F17.o ./CEC2010/F18.o ./CEC2010/F19.o ./CEC2010/F20.o

INCLUDE=./CEC2010/Header.h  ./CEC2010/Benchmarks.h \
./CEC2010/F1.h ./CEC2010/F2.h ./CEC2010/F3.h ./CEC2010/F4.h ./CEC2010/F5.h ./CEC2010/F6.h ./CEC2010/F7.h ./CEC2010/F8.h ./CEC2010/F9.h ./CEC2010/F10.h\
./CEC2010/F11.h ./CEC2010/F12.h ./CEC2010/F13.h ./CEC2010/F14.h ./CEC2010/F15.h ./CEC2010/F16.h ./CEC2010/F17.h ./CEC2010/F18.h ./CEC2010/F19.h ./CEC2010/F20.h\
Self_Define_Functions.h


CSO: CSO.o $(OBJECTS) $(INCLUDE)
	$(CC) $(CXXFLAGS) -o CSO CSO.o $(OBJECTS)
CSO.o: $(INCLUDE) Self_Define_Functions.h CSO.cpp
	$(CC) $(CXXFLAGS) -c CSO.cpp

CSO_1: CSO_1.o $(OBJECTS) $(INCLUDE)
	$(CC) $(CXXFLAGS) -o CSO_1 CSO_1.o $(OBJECTS)
CSO_1.o: $(INCLUDE) Self_Define_Functions.h CSO_1.cpp
	$(CC) $(CXXFLAGS) -c CSO_1.cpp

CSO_2: CSO_2.o $(OBJECTS) $(INCLUDE)
	$(CC) $(CXXFLAGS) -o CSO_2 CSO_2.o $(OBJECTS)
CSO_2.o: $(INCLUDE) Self_Define_Functions.h CSO_2.cpp
	$(CC) $(CXXFLAGS) -c CSO_2.cpp

CSO_3: CSO_3.o $(OBJECTS) $(INCLUDE)
	$(CC) $(CXXFLAGS) -o CSO_3 CSO_3.o $(OBJECTS)
CSO_3.o: $(INCLUDE) Self_Define_Functions.h CSO_3.cpp
	$(CC) $(CXXFLAGS) -c CSO_3.cpp

CSO_4: CSO_4.o $(OBJECTS) $(INCLUDE)
	$(CC) $(CXXFLAGS) -o CSO_4 CSO_4.o $(OBJECTS)
CSO_4.o: $(INCLUDE) Self_Define_Functions.h CSO_4.cpp
	$(CC) $(CXXFLAGS) -c CSO_4.cpp


Self_Define_Functions.o:  ./CEC2010/Benchmarks.h Self_Define_Functions.h Self_Define_Functions.cpp
	$(CC) $(CXXFLAGS) -c Self_Define_Functions.cpp

/CEC2010/Benchmarks.o:  ./CEC2010/Benchmarks.h ./CEC2010/Benchmarks.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/Benchmarks.cpp

/CEC2010/F1.o: ./CEC2010/F1.h ./CEC2010/Benchmarks.h ./CEC2010/F1.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F1.cpp

/CEC2010/F2.o: ./CEC2010/F2.h ./CEC2010/Benchmarks.h ./CEC2010/F2.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F2.cpp

/CEC2010/F3.o: ./CEC2010/F3.h ./CEC2010/Benchmarks.h ./CEC2010/F3.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F3.cpp

/CEC2010/F4.o: ./CEC2010/F4.h ./CEC2010/Benchmarks.h ./CEC2010/F4.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F4.cpp

/CEC2010/F5.o: ./CEC2010/F5.h ./CEC2010/Benchmarks.h ./CEC2010/F5.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F5.cpp

/CEC2010/F6.o: ./CEC2010/F6.h ./CEC2010/Benchmarks.h ./CEC2010/F6.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F6.cpp

/CEC2010/F7.o: ./CEC2010/F7.h ./CEC2010/Benchmarks.h ./CEC2010/F7.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F7.cpp

/CEC2010/F8.o: ./CEC2010/F8.h ./CEC2010/Benchmarks.h ./CEC2010/F8.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F8.cpp

/CEC2010/F9.o: ./CEC2010/F9.h ./CEC2010/Benchmarks.h ./CEC2010/F9.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F9.cpp

/CEC2010/F10.o: ./CEC2010/F10.h ./CEC2010/Benchmarks.h ./CEC2010/F10.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F10.cpp

/CEC2010/F11.o: ./CEC2010/F11.h ./CEC2010/Benchmarks.h ./CEC2010/F11.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F11.cpp

/CEC2010/F12.o: ./CEC2010/F12.h ./CEC2010/Benchmarks.h ./CEC2010/F12.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F12.cpp

/CEC2010/F13.o: ./CEC2010/F13.h ./CEC2010/Benchmarks.h ./CEC2010/F13.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F13.cpp

/CEC2010/F14.o: ./CEC2010/F14.h ./CEC2010/Benchmarks.h ./CEC2010/F14.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F14.cpp

/CEC2010/F15.o: F15.h Benchmarks.h F15.cpp
	$(CC) $(CXXFLAGS) -c F15.cpp

/CEC2010/F16.o: ./CEC2010/F16.h ./CEC2010/Benchmarks.h ./CEC2010/F16.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F16.cpp

/CEC2010/F17.o: ./CEC2010/F17.h ./CEC2010/Benchmarks.h ./CEC2010/F17.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F17.cpp

/CEC2010/F18.o: ./CEC2010/F18.h ./CEC2010/Benchmarks.h ./CEC2010/F18.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F18.cpp

/CEC2010/F19.o: ./CEC2010/F19.h ./CEC2010/Benchmarks.h ./CEC2010/F19.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F19.cpp

/CEC2010/F20.o: ./CEC2010/F20.h ./CEC2010/Benchmarks.h ./CEC2010/F20.cpp
	$(CC) $(CXXFLAGS) -c ./CEC2010/F20.cpp

.PHONY : clean clrout
clean:
	rm -f  $(OBJECTS)
	rm -f  CSO.o CSO_1.o CSO_2.o CSO_3.o CSO_4.o

clrout:
	rm -fr result trace out outout
