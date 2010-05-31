# Makefile for Ords. Copyright 2010 Teemu Vasama

# Assigning the compiler and flags to use
CPP = g++
QT_CPPFLAGS = -I/usr/local/Qt4.6/mkspecs/macx-g++ -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/usr/include -F/Library/Frameworks
QT_LFLAGS = -F/Library/Frameworks -L/Library/Frameworks -framework QtGui -framework QtCore
CPPFLAGS = -Wall -Werror -pedantic -ansi
LFLAGS =
LOCATION = ~
WITH_GUI =

# Assigning the macro that contains all the necessary object files
CLI_OBJS = args.o args_parser.o ui.o uifuncs.o
DATA_OBJS = collection.o conjugation.o def_term.o definition.o dictionary.o question.o wrapper.o
FILE_OBJS = file.o plaintext.o settings.o
MISC_OBJS = ords.o init.o utils.o
QT_OBJS = qt_main.o

OBJECTS = $(MISC_OBJS) $(CLI_OBJS) $(DATA_OBJS) $(FILE_OBJS)

ifeq ($(WITH_GUI), TRUE)
	OBJECTS += $(QT_OBJS)
	LFLAGS += $(QT_LFLAGS)
endif

# Links the files, producing the binary
ords: $(OBJECTS)
	$(CPP) $(LFLAGS) -g $(OBJECTS) -o ords

# The rule that compiles all the files
ords.o: ords.cpp
ifeq ($(WITH_GUI), TRUE)
	$(CPP) $(CPPFLAGS) $(QT_CPPFLAGS) -DWITH_GUI -c $< -o $@
else
	$(CPP) $(CPPFLAGS) -c $< -o $@
endif

%.o: cli/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	
%.o: data/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	
%.o: file/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	
%.o: init/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

%.o: utils/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	
qt_main.o: qt/qt_main.cpp qt/qt_main.h
	g++ -c -pipe -g -gdwarf-2 -Wall -W -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/usr/local/Qt4.6/mkspecs/macx-g++ -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/usr/include -F/Library/Frameworks -o qt_main.o qt/qt_main.cpp

# For cleaning the files, remove everything that was compiled
clean:
	rm ords *.o
	
# For installing, move the binary file to the location specified
install:
	mv ords $(LOCATION)/ords
