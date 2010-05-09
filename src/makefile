# Makefile for Ords. Copyright 2010 Teemu Vasama

# Assgning the macro that contains all the necessary object files
OBJECTS = ords.o file.o plaintext.o settings.o args.o ui.o uifuncs.o init.o definition.o def_term.o wrapper.o conjugation.o dictionary.o question.o collection.o utils.o

# Assigning the compiler and flags to use
CPP = g++
CPPFLAGS = -Wall -pedantic

# The rule that compiles all the files
%.o : */%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Links the files, producing the binary
ords: $(OBJECTS)
	$(CPP) -g $(OBJECTS) -o ords

# For cleaning the files
clean:
	rm ords $(OBJECTS)