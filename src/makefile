# Makefile for Ords. Copyright 2010 Teemu Vasama

# Assigning the macro that contains all the necessary object files
OBJECTS = args.o args_parser.o collection.o conjugation.o definition.o def_term.o dictionary.o file.o init.o ords.o plaintext.o question.o settings.o ui.o uifuncs.o utils.o wrapper.o

# Assigning the compiler and flags to use
CPP = g++
CPPFLAGS = -Wall -pedantic
LOCATION = ~

# The rule that compiles all the files
%.o : */%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Links the files, producing the binary
ords: $(OBJECTS)
	$(CPP) -g $(OBJECTS) -o ords

# For cleaning the files, remove everything that was compiled
clean:
	rm ords $(OBJECTS)
	
# For installing, move the binary file to the location specified
install:
	mv ords $(LOCATION)/ords
