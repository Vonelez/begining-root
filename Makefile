# compiler
CXX=g++

# program name
EXECUTABLE=main

# Root libraries flag
ROOTFLAG=`root-config --glibs --cflags`

# source codes directory path
SOURCE=sources
# headers directory path
HEADER=headers

# object files names list
OBJECTS = main.o MadeClass.o


$(EXECUTABLE) : $(OBJECTS)
	$(CXX) -o $(EXECUTABLE) $(OBJECTS) $(ROOTFLAG)

main.o : main.cpp $(HEADER)/MadeClass.h
	$(CXX) -c main.cpp -I $(HEADER) $(ROOTFLAG)

MadeClass.o : $(SOURCE)/MadeClass.cpp $(HEADER)/MadeClass.h
	$(CXX) -c $(SOURCE)/MadeClass.cpp -I $(HEADER) $(ROOTFLAG)


# phony targets
.PHONY : cleanobj clean
	
cleanobj :
	rm $(OBJECTS)

clean :
	rm $(OBJECTS) $(EXECUTABLE)